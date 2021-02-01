/*
 *  Copyright (C) 2020-2021 FotaHub Inc. All rights reserved.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License"); you may
 *  not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *  WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  This file is part of the FotaHub(R) Device SDK program (https://fotahub.com)
 */
#include "Main.h"

#include "Configuration.h"
#include "DemoFOTAUpdateWorkflow.h"
#include "SinglePartitionDemoFirmwareUpdateInfoFileReader.h"
#include "DemoFOTAUpdateWorkflowFilePersistence.h"
#include "DemoFOTAUpdateSelfTest.h"
#include "DemoProductInfo.h"
#include "FotaHub.h"
#include <string.h>
#include <libgen.h>
#include <unistd.h>
#include <limits.h>

int32_t main(int32_t argc, char *argv[])
{
  /* 
   * Change directory to where this program's executable is located
   */
  char *programDir = dirname(strdup(argv[0]));
  chdir(programDir);
  
  firmwareUpdateInfoReader_init();
  fotaUpdateWorkflow_init();
  fotaUpdateSelfTest_init();
  fotahub_init(argv[0], DEMO_PRODUCT_ID, DEMO_PRODUCT_NAME, &FOTA_UPDATE_CLIENT_CONFIG);
  
  printf("\n--------------------------------------------------------------------------\n");
  printf("Running %s %s firmware\n", DEMO_PRODUCT_NAME, DEMO_PRODUCT_FIRMWARE_VERSION);
  printf("--------------------------------------------------------------------------\n\n");
  
  /* 
   * Assume machine this program is running on to be connected to some Wi-Fi or Ethernet network
   */
  fotahub_notifyNetworkStatusChange(NETWORK_ADAPTER_STATUS_CONNECTED);
  
  char *separator = (strlen(programDir) > 0) ? ("/") : ("");
  printf("Waiting for firmware update info (<new-version>:<checksum-or-signature>) to be entered and saved in '%s%s%s' file\n", programDir, separator, DEMO_PRODUCT_UPDATE_INFO_FILE_NAME);
  
  while (true)
  {
    firmwareUpdateInfoReader_run();
    fotahub_run();
  }
}
