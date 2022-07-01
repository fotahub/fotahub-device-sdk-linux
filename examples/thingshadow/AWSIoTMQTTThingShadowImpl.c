/*
 *  Copyright (C) 2022 FotaHub Inc. All rights reserved.
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
#include "AWSIoTMQTTThingShadowImpl.h"

#include <string.h>

void const* AWSIoTMQTTThingShadowImpl_thingShadow_connect(IoTConnectionParameters_t *pConnParams, void *pUserData, void *___id)
{
  AWSIoTMQTTThingShadowImpl__cdata_t *___cid = ((AWSIoTMQTTThingShadowImpl__cdata_t *) ___id);
  if (pConnParams == NULL) 
  {
    return NULL;
  }
  
  AWSIoTSessionData_t *pSessionData = AbstractAWSIoTMQTTThingShadowImpl_newAWSIoTData(___cid);
  if (AbstractAWSIoTMQTTThingShadowImpl_isAWSIoTDataDeleted(pSessionData, ___cid)) 
  {
    return NULL;
  }
  pSessionData->pConnectionParams = pConnParams;
  pSessionData->pUserData = pUserData;
  
  MQTTConnectionParameters_t *mqttConnParams = ((MQTTConnectionParameters_t *)(pConnParams->pDownstreamConnParams));
  if (mqttConnParams == NULL) 
  {
    AbstractAWSIoTMQTTThingShadowImpl_deleteAWSIoTData(pSessionData, ___cid);
    return NULL;
  }
  
  if (mqttConnParams->clientID == NULL) 
  {
    mqttConnParams->clientID = pSessionData->pConnectionParams->deviceName;
  }
  else if (strlen(mqttConnParams->clientID) == 0) {
    mqttConnParams->clientID = pSessionData->pConnectionParams->deviceName;
  }
  pSessionData->hDownstreamSession = (*___cid->baseComponentData.mqttClient__ops->connect)(mqttConnParams, pSessionData, ___cid->baseComponentData.mqttClient__ops->__instance);
  
  if (pSessionData->hDownstreamSession == NULL) 
  {
    AbstractAWSIoTMQTTThingShadowImpl_deleteAWSIoTData(pSessionData, ___cid);
    return NULL;
  }
  return pSessionData;
}
