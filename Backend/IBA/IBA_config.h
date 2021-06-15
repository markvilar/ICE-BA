/******************************************************************************
 * Copyright 2017-2018 Baidu Robotic Vision Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#ifndef IBA_IBA_CONFIG_H_
#define IBA_IBA_CONFIG_H_

#define CFG_IMU_FULL_COVARIANCE
#define CFG_INCREMENTAL_PCG
#ifdef CFG_PCG_DOUBLE
typedef double PCG_TYPE;
#else
typedef float PCG_TYPE;
#endif
#define CFG_CAMERA_PRIOR_DOUBLE
#define CFG_CHECK_REPROJECTION

#define CFG_STEREO
#define CFG_SERIAL
#define CFG_VERBOSE
#define CFG_HISTORY
#define CFG_GROUND_TRUTH
#ifdef WIN32
#else
#endif
#ifdef CFG_DEBUG
#define CFG_DEBUG_EIGEN
#endif

#include <assert.h>
#include <cmath>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#ifdef WIN32
#include <io.h>
#include <tchar.h>
#include <windows.h>
#endif

#include <algorithm>
#include <float.h>
#include <fstream>
#include <list>
#include <queue>
#include <string>
#include <vector>

typedef unsigned char ubyte;
typedef unsigned short ushort; // NOLINT
typedef unsigned int uint;
typedef unsigned long long ullong; // NOLINT

#ifdef max
#undef max
#endif
#ifdef min
#undef min
#endif
#ifdef small
#undef small
#endif
#ifdef _C2
#undef _C2
#endif
#ifdef _T
#undef _T
#endif
#ifdef ERROR
#undef ERROR
#endif

#endif // IBA_IBA_CONFIG_H_
