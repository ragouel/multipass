/*
 * Copyright (C) 2020 Canonical, Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 3.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "get_image_size.h"
#include <multipass/format.h>
#include <multipass/platform.h>

#include <QRegularExpression>
#include <QString>

namespace mp = multipass;

mp::MemorySize mp::get_image_size(const mp::VMImage& image)
{
    auto qemuimg_process = mp::platform::make_qemuimg_process({"info", image.image_path});
    auto process_state = qemuimg_process->execute();

    if (!process_state.completed_successfully())
        throw std::runtime_error(fmt::format("Cannot get image info: qemu-img failed ({}) with output:\n{}",
                                             process_state.failure_message(),
                                             qemuimg_process->read_all_standard_error()));

    const auto img_info = QString{qemuimg_process->read_all_standard_output()};
    const auto pattern = QStringLiteral("^virtual size: .+ \\((?<size>\\d+) bytes\\)$");
    const auto re = QRegularExpression{pattern, QRegularExpression::MultilineOption};

    mp::MemorySize image_size{};

    const auto match = re.match(img_info);

    if (match.hasMatch())
    {
        image_size = mp::MemorySize(match.captured("size").toStdString());
    }
    else
    {
        throw std::runtime_error{"Could not obtain image's virtual size"};
    }

    return image_size;
}
