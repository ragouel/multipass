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

#ifndef MULTIPASS_MOCK_LXD_SERVER_RESPONSES_H
#define MULTIPASS_MOCK_LXD_SERVER_RESPONSES_H

#include <QByteArray>

namespace multipass
{
namespace test
{
const QByteArray not_found_response{"HTTP/1.1 404 Not Found\r\n"
                                    "Content-Type: application/json\r\n"
                                    "Content-Length: 55\r\n\r\n"
                                    "{\"error\": \"not found\",\"error_code\": 404,\"type\": \"error\"}"};

const QByteArray create_vm_response{"HTTP/1.1 202 Accepted\r\n"
                                    "Content-Type: application/json\r\n\r\n"
                                    "{"
                                    "\"type\": \"async\","
                                    "\"error\": \"\","
                                    "\"error_code\": 0,"
                                    "\"metadata\": {"
                                    "    \"class\": \"task\","
                                    "    \"created_at\": \"2020-05-18T15:14:21.104580212-04:00\","
                                    "    \"description\": \"Creating container\","
                                    "    \"err\": \"\","
                                    "    \"id\": \"0020444c-2e4c-49d5-83ed-3275e3f6d005\","
                                    "    \"location\": \"none\","
                                    "    \"may_cancel\": false,"
                                    "    \"metadata\": null,"
                                    "    \"resources\": {"
                                    "        \"containers\": ["
                                    "            \"/1.0/containers/pied-piper-valley\""
                                    "         ],"
                                    "        \"instances\": ["
                                    "            \"/1.0/instances/pied-piper-valley\""
                                    "         ]"
                                    "     },"
                                    "    \"status\": \"Running\","
                                    "    \"status_code\": 103,"
                                    "    \"updated_at\": \"2020-05-18T15:14:21.104580212-04:00\""
                                    " },"
                                    "\"operation\": \"/1.0/operations/0020444c-2e4c-49d5-83ed-3275e3f6d005\","
                                    "\"status\": \"Operation created\","
                                    "\"status_code\": 100,"
                                    "\"type\": \"async\""
                                    "}\n"};

const QByteArray vm_created_response{
    "HTTP/1.1 200 OK\r\n"
    "Content-Type: application/json\r\n\r\n"
    "{"
    "\"error\": \"\","
    "\"error_code\": 0,"
    "\"metadata\": {"
    "  \"architecture\": \"x86_64\","
    "  \"config\": {"
    "    \"image.architecture\": \"amd64\","
    "    \"image.description\": \"ubuntu 18.04 LTS amd64 (release) (20200506)\","
    "    \"image.label\": \"release\","
    "    \"image.os\": \"ubuntu\","
    "    \"image.release\": \"bionic\","
    "    \"image.serial\": \"20200506\","
    "    \"image.type\": \"disk1.img\","
    "    \"image.version\": \"18.04\","
    "    \"limits.cpu\": \"2\","
    "    \"limits.memory\": \"3221225472\","
    "    \"volatile.apply_template\": \"create\","
    "    \"volatile.base_image\": \"016b05541bc82306d971e04c53fe4a7979f99c3d87220516c798ffa3544de347\","
    "    \"volatile.eth0.hwaddr\": \"00:16:3e:b0:c5:f4\""
    "    },"
    "  \"created_at\": \"2020-05-13T15:31:46.194594923-04:00\","
    "  \"description\": \"\","
    "  \"devices\": {"
    "    \"config\": {"
    "      \"source\": \"cloud-init:config\","
    "      \"type\": \"disk\""
    "      },"
    "    \"root\": {"
    "      \"path\": \"/\","
    "      \"pool\": \"default\","
    "      \"size\": \"16106127360\","
    "      \"type\": \"disk\""
    "      }"
    "    },"
    "    \"ephemeral\": false,"
    "    \"expanded_config\": {"
    "      \"image.architecture\": \"amd64\","
    "      \"image.description\": \"ubuntu 18.04 LTS amd64 (release) (20200506)\","
    "      \"image.label\": \"release\","
    "      \"image.os\": \"ubuntu\","
    "      \"image.release\": \"bionic\","
    "      \"image.serial\": \"20200506\","
    "      \"image.type\": \"disk1.img\","
    "      \"image.version\": \"18.04\","
    "      \"limits.cpu\": \"2\","
    "      \"limits.memory\": \"3221225472\","
    "      \"volatile.apply_template\": \"create\","
    "      \"volatile.base_image\": \"016b05541bc82306d971e04c53fe4a7979f99c3d87220516c798ffa3544de347\","
    "      \"volatile.eth0.hwaddr\": \"00:16:3e:b0:c5:f4\""
    "      },"
    "    \"expanded_devices\": {"
    "      \"config\": {"
    "        \"source\": \"cloud-init:config\","
    "        \"type\": \"disk\""
    "        },"
    "      \"eth0\": {"
    "        \"name\": \"eth0\","
    "        \"nictype\": \"bridged\","
    "        \"parent\": \"lxdbr0\","
    "        \"type\": \"nic\""
    "        },"
    "      \"root\": {"
    "        \"path\": \"/\","
    "        \"pool\": \"default\","
    "        \"size\": \"16106127360\","
    "        \"type\": \"disk\""
    "        }"
    "      },"
    "    \"last_used_at\": \"2020-05-13T15:34:22.934800001-04:00\","
    "    \"location\": \"none\","
    "    \"name\": \"pied-piper-valley\","
    "    \"profiles\": ["
    "      \"default\""
    "      ],"
    "    \"stateful\": false,"
    "    \"status\": \"Stopped\","
    "    \"status_code\": 102,"
    "    \"type\": \"virtual-machine\""
    "  },"
    "  \"operation\": \"\","
    "  \"status\": \"Success\","
    "  \"status_code\": 200,"
    "  \"type\": \"sync\""
    "}\n"};

const QByteArray start_vm_response{"HTTP/1.1 202 Accepted\r\n"
                                   "Content-Type: application/json\r\n\r\n"
                                   "{"
                                   "\"error\": \"\","
                                   "\"error_code\": 0,"
                                   "\"metadata\": {"
                                   "  \"class\": \"task\","
                                   "  \"created_at\": \"2020-05-19T11:17:20.979902453-04:00\","
                                   "  \"description\": \"Starting container\","
                                   "  \"err\": \"\","
                                   "  \"id\": \"b043d632-5c48-44b3-983c-a25660d61164\","
                                   "  \"location\": \"none\","
                                   "  \"may_cancel\": false,"
                                   "  \"metadata\": null,"
                                   "  \"resources\": {"
                                   "    \"containers\": ["
                                   "      \"/1.0/containers/pied-piper-valley\""
                                   "      ]"
                                   "    },"
                                   "  \"status\": \"Running\","
                                   "  \"status_code\": 103,"
                                   "  \"updated_at\": \"2020-05-19T11:17:20.979902453-04:00\""
                                   "  },"
                                   "\"operation\": \"/1.0/operations/b043d632-5c48-44b3-983c-a25660d61164\","
                                   "\"status\": \"Operation created\","
                                   "\"status_code\": 100,"
                                   "\"type\": \"async\""
                                   "}\n"};

const QByteArray stop_vm_response{"HTTP/1.1 202 Accepted\r\n"
                                  "Content-Type: application/json\r\n\r\n"
                                  "{"
                                  "\"error\": \"\","
                                  "\"error_code\": 0,"
                                  "\"metadata\": {"
                                  "  \"class\": \"task\","
                                  "  \"created_at\": \"2020-05-19T11:17:20.979902453-04:00\","
                                  "  \"description\": \"Stopping container\","
                                  "  \"err\": \"\","
                                  "  \"id\": \"b043d632-5c48-44b3-983c-a25660d61164\","
                                  "  \"location\": \"none\","
                                  "  \"may_cancel\": false,"
                                  "  \"metadata\": null,"
                                  "  \"resources\": {"
                                  "    \"containers\": ["
                                  "      \"/1.0/containers/pied-piper-valley\""
                                  "      ]"
                                  "    },"
                                  "  \"status\": \"Running\","
                                  "  \"status_code\": 103,"
                                  "  \"updated_at\": \"2020-05-19T11:17:20.979902453-04:00\""
                                  "  },"
                                  "\"operation\": \"/1.0/operations/b043d632-5c48-44b3-983c-a25660d61164\","
                                  "\"status\": \"Operation created\","
                                  "\"status_code\": 100,"
                                  "\"type\": \"async\""
                                  "}\n"};

const QByteArray vm_state_stopped_response{"HTTP/1.1 200 OK\r\n"
                                           "Content-Type: application/json\r\n\r\n"
                                           "{"
                                           "\"error\": \"\","
                                           "\"error_code\": 0,"
                                           "\"metadata\": {"
                                           "  \"cpu\": {"
                                           "    \"usage\": 0"
                                           "    },"
                                           "  \"disk\": null,"
                                           "  \"memory\": {"
                                           "    \"swap_usage\": 0,"
                                           "    \"swap_usage_peak\": 0,"
                                           "    \"usage\": 0,"
                                           "    \"usage_peak\": 0"
                                           "    },"
                                           "  \"network\": null,"
                                           "  \"pid\": 0,"
                                           "  \"processes\": 0,"
                                           "  \"status\": \"Stopped\","
                                           "  \"status_code\": 102"
                                           "  },"
                                           "\"operation\": \"\","
                                           "\"status\": \"Success\","
                                           "\"status_code\": 200,"
                                           "\"type\": \"sync\""
                                           "}\n"};

const QByteArray vm_state_starting_response{"HTTP/1.1 200 OK\r\n"
                                            "Content-Type: application/json\r\n\r\n"
                                            "{"
                                            "\"error\": \"\","
                                            "\"error_code\": 0,"
                                            "\"metadata\": {"
                                            "  \"cpu\": {"
                                            "    \"usage\": 0"
                                            "    },"
                                            "  \"disk\": null,"
                                            "  \"memory\": {"
                                            "    \"swap_usage\": 0,"
                                            "    \"swap_usage_peak\": 0,"
                                            "    \"usage\": 0,"
                                            "    \"usage_peak\": 0"
                                            "    },"
                                            "  \"network\": null,"
                                            "  \"pid\": 0,"
                                            "  \"processes\": 0,"
                                            "  \"status\": \"Starting\","
                                            "  \"status_code\": 106"
                                            "  },"
                                            "\"operation\": \"\","
                                            "\"status\": \"Success\","
                                            "\"status_code\": 200,"
                                            "\"type\": \"sync\""
                                            "}\n"};

const QByteArray vm_state_freezing_response{"HTTP/1.1 200 OK\r\n"
                                            "Content-Type: application/json\r\n\r\n"
                                            "{"
                                            "\"error\": \"\","
                                            "\"error_code\": 0,"
                                            "\"metadata\": {"
                                            "  \"cpu\": {"
                                            "    \"usage\": 0"
                                            "    },"
                                            "  \"disk\": null,"
                                            "  \"memory\": {"
                                            "    \"swap_usage\": 0,"
                                            "    \"swap_usage_peak\": 0,"
                                            "    \"usage\": 0,"
                                            "    \"usage_peak\": 0"
                                            "    },"
                                            "  \"network\": null,"
                                            "  \"pid\": 0,"
                                            "  \"processes\": 0,"
                                            "  \"status\": \"Freezing\","
                                            "  \"status_code\": 109"
                                            "  },"
                                            "\"operation\": \"\","
                                            "\"status\": \"Success\","
                                            "\"status_code\": 200,"
                                            "\"type\": \"sync\""
                                            "}\n"};

const QByteArray vm_state_frozen_response{"HTTP/1.1 200 OK\r\n"
                                          "Content-Type: application/json\r\n\r\n"
                                          "{"
                                          "\"error\": \"\","
                                          "\"error_code\": 0,"
                                          "\"metadata\": {"
                                          "  \"cpu\": {"
                                          "    \"usage\": 0"
                                          "    },"
                                          "  \"disk\": null,"
                                          "  \"memory\": {"
                                          "    \"swap_usage\": 0,"
                                          "    \"swap_usage_peak\": 0,"
                                          "    \"usage\": 0,"
                                          "    \"usage_peak\": 0"
                                          "    },"
                                          "  \"network\": null,"
                                          "  \"pid\": 0,"
                                          "  \"processes\": 0,"
                                          "  \"status\": \"Frozen\","
                                          "  \"status_code\": 110"
                                          "  },"
                                          "\"operation\": \"\","
                                          "\"status\": \"Success\","
                                          "\"status_code\": 200,"
                                          "\"type\": \"sync\""
                                          "}\n"};

const QByteArray vm_state_cancelling_response{"HTTP/1.1 200 OK\r\n"
                                              "Content-Type: application/json\r\n\r\n"
                                              "{"
                                              "\"error\": \"\","
                                              "\"error_code\": 0,"
                                              "\"metadata\": {"
                                              "  \"cpu\": {"
                                              "    \"usage\": 0"
                                              "    },"
                                              "  \"disk\": null,"
                                              "  \"memory\": {"
                                              "    \"swap_usage\": 0,"
                                              "    \"swap_usage_peak\": 0,"
                                              "    \"usage\": 0,"
                                              "    \"usage_peak\": 0"
                                              "    },"
                                              "  \"network\": null,"
                                              "  \"pid\": 0,"
                                              "  \"processes\": 0,"
                                              "  \"status\": \"Cancelling\","
                                              "  \"status_code\": 104"
                                              "  },"
                                              "\"operation\": \"\","
                                              "\"status\": \"Success\","
                                              "\"status_code\": 200,"
                                              "\"type\": \"sync\""
                                              "}\n"};

const QByteArray vm_state_other_response{"HTTP/1.1 200 OK\r\n"
                                         "Content-Type: application/json\r\n\r\n"
                                         "{"
                                         "\"error\": \"\","
                                         "\"error_code\": 0,"
                                         "\"metadata\": {"
                                         "  \"cpu\": {"
                                         "    \"usage\": 0"
                                         "    },"
                                         "  \"disk\": null,"
                                         "  \"memory\": {"
                                         "    \"swap_usage\": 0,"
                                         "    \"swap_usage_peak\": 0,"
                                         "    \"usage\": 0,"
                                         "    \"usage_peak\": 0"
                                         "    },"
                                         "  \"network\": null,"
                                         "  \"pid\": 0,"
                                         "  \"processes\": 0,"
                                         "  \"status\": \"Bogus\","
                                         "  \"status_code\": 115"
                                         "  },"
                                         "\"operation\": \"\","
                                         "\"status\": \"Success\","
                                         "\"status_code\": 200,"
                                         "\"type\": \"sync\""
                                         "}\n"};

const QByteArray vm_state_fully_running_response{"HTTP/1.1 200 OK\r\n"
                                                 "Content-Type: application/json\r\n\r\n"
                                                 "{"
                                                 "\"error\": \"\","
                                                 "\"error_code\": 0,"
                                                 "\"metadata\": {"
                                                 "  \"cpu\": {"
                                                 "    \"usage\": 0"
                                                 "    },"
                                                 "  \"disk\": {"
                                                 "    \"root\": {"
                                                 "      \"usage\": 100352"
                                                 "      }"
                                                 "    },"
                                                 "  \"memory\": {"
                                                 "    \"swap_usage\": 0,"
                                                 "    \"swap_usage_peak\": 0,"
                                                 "    \"usage\": 0,"
                                                 "    \"usage_peak\": 0"
                                                 "    },"
                                                 "  \"network\": {"
                                                 "    \"eth0\": {"
                                                 "      \"addresses\": ["
                                                 "        {"
                                                 "          \"address\": \"10.217.27.168\","
                                                 "          \"family\": \"inet\","
                                                 "          \"netmask\": \"24\","
                                                 "          \"scope\": \"global\""
                                                 "        }"
                                                 "      ],"
                                                 "      \"counters\": {"
                                                 "        \"bytes_received\": 0,"
                                                 "        \"bytes_sent\": 0,"
                                                 "        \"packets_received\": 0,"
                                                 "        \"packets_sent\": 0"
                                                 "      },"
                                                 "      \"host_name\": \"tape3019389\","
                                                 "      \"hwaddr\": \"00:16:3e:13:36:01\","
                                                 "      \"mtu\": 1500,"
                                                 "      \"state\": \"up\","
                                                 "      \"type\": \"broadcast\""
                                                 "    }"
                                                 "  },"
                                                 "  \"pid\": 1266500,"
                                                 "  \"processes\": -1,"
                                                 "  \"status\": \"Running\","
                                                 "  \"status_code\": 103"
                                                 "  },"
                                                 "\"operation\": \"\","
                                                 "\"status\": \"Success\","
                                                 "\"status_code\": 200,"
                                                 "\"type\": \"sync\""
                                                 "}\n"};

const QByteArray vm_state_partial_running_response{"HTTP/1.1 200 OK\r\n"
                                                   "Content-Type: application/json\r\n\r\n"
                                                   "{"
                                                   "\"error\": \"\","
                                                   "\"error_code\": 0,"
                                                   "\"metadata\": {"
                                                   "  \"cpu\": {"
                                                   "    \"usage\": 0"
                                                   "    },"
                                                   "  \"disk\": null,"
                                                   "  \"memory\": {"
                                                   "    \"swap_usage\": 0,"
                                                   "    \"swap_usage_peak\": 0,"
                                                   "    \"usage\": 0,"
                                                   "    \"usage_peak\": 0"
                                                   "    },"
                                                   "  \"network\": null,"
                                                   "  \"pid\": 0,"
                                                   "  \"processes\": 0,"
                                                   "  \"status\": \"Running\","
                                                   "  \"status_code\": 103"
                                                   "  },"
                                                   "\"operation\": \"\","
                                                   "\"status\": \"Success\","
                                                   "\"status_code\": 200,"
                                                   "\"type\": \"sync\""
                                                   "}\n"};

QByteArray vm_stop_wait_task_response{"HTTP/1.1 200 OK\r\n"
                                      "Content-Type: application/json\r\n\r\n"
                                      "{"
                                      "\"error\": \"\","
                                      "\"error_code\": 0,"
                                      "\"metadata\": {"
                                      "  \"class\": \"task\","
                                      "  \"created_at\": \"2020-05-20T10:22:02.684673072-04:00\","
                                      "  \"description\": \"Stopping container\","
                                      "  \"err\": \"\","
                                      "  \"id\": \"b043d632-5c48-44b3-983c-a25660d61164\","
                                      "  \"location\": \"none\","
                                      "  \"may_cancel\": false,"
                                      "  \"metadata\": null,"
                                      "  \"resources\": {"
                                      "    \"containers\": ["
                                      "      \"/1.0/containers/pied-piper-valley\""
                                      "      ]"
                                      "    },"
                                      "  \"status\": \"Success\","
                                      "  \"status_code\": 200,"
                                      "  \"updated_at\": \"2020-05-20T10:22:02.684673072-04:00\""
                                      "  },"
                                      "\"operation\": \"\","
                                      "\"status\": \"Success\","
                                      "\"status_code\": 200,"
                                      "\"type\": \"sync\""
                                      "}\n"};

} // namespace test
} // namespace multipass

#endif // MULTIPASS_MOCK_LXD_SERVER_RESPONSES_H
