/** @file KeyApiStaDefs.h
 *
 *  @brief This file Contains data structures and defines related to key material.
 *
 *  (C) Copyright 2014-2017 Marvell International Ltd. All Rights Reserved
 *
 *  MARVELL CONFIDENTIAL
 *  The source code contained or described herein and all documents related to
 *  the source code ("Material") are owned by Marvell International Ltd or its
 *  suppliers or licensors. Title to the Material remains with Marvell International Ltd
 *  or its suppliers and licensors. The Material contains trade secrets and
 *  proprietary and confidential information of Marvell or its suppliers and
 *  licensors. The Material is protected by worldwide copyright and trade secret
 *  laws and treaty provisions. No part of the Material may be used, copied,
 *  reproduced, modified, published, uploaded, posted, transmitted, distributed,
 *  or disclosed in any way without Marvell's prior express written permission.
 *
 *  No license under any patent, copyright, trade secret or other intellectual
 *  property right is granted to or conferred upon you by disclosure or delivery
 *  of the Materials, either expressly, by implication, inducement, estoppel or
 *  otherwise. Any license under such intellectual property rights must be
 *  express and approved by Marvell in writing.
 *
 */

/******************************************************
Change log:
    03/07/2014: Initial version
******************************************************/
#ifndef _KEY_API_STA_DEFS_H
#define _KEY_API_STA_DEFS_H
/******************************************************************/
/*!
 *  \ingroup wpa_supplicant
 *  \file   keyApiStaDefs.h
 *  \brief  Contains data structures and defines related to key material
 *
 *******************************************************************/

/* Key Material for TKIP type key */
#define CRYPTO_TKIP_KEY_LEN_MAX     16
#define CRYPTO_KEY_LEN_MAX          16
#define MIC_KEY_LEN_MAX             8

/* Key Material for AES type key */
#define CRYPTO_AES_KEY_LEN_MAX      16

#define WAPI_KEY_LEN               16
#define WAPI_MIC_LEN               16
#define WAPI_PN_LEN                16

#define CRYPTO_AES_CMAC_KEY_LEN		16
#define CRYPTO_AES_CMAC_IPN_LEN		6
#define CRYPTO_WEP_KEY_LEN_MAX     13

/*
  WIN7 softAP (uAP) :
  BIT14 and BIT15 of keyInfo is used to pass keyID for broadcast frame
*/

#define KEYDATA_KEY_ID_MASK   (BIT14 | BIT15)
#define KEYDATA_KEY_ID_OFFSET 14

#define KEY_INFO_MULTICAST      0x1
#define KEY_INFO_UNICAST        0x2
#define KEY_INFO_ENABLED        0x4
#define KEY_INFO_DEFAULT        0x8
#define KEY_INFO_TX             0x10
#define KEY_INFO_RX             0x20
#define KEY_INFO_MULTICAST_IGTK	0x400

typedef MLAN_PACK_START struct {
	UINT8 key[CRYPTO_TKIP_KEY_LEN_MAX];
	UINT8 txMicKey[MIC_KEY_LEN_MAX];
	UINT8 rxMicKey[MIC_KEY_LEN_MAX];
} MLAN_PACK_END key_Type_TKIP_t;

/* This struct is used in ROM and existing fields should not be changed.
  * New fields can be added at the end.
  */
typedef MLAN_PACK_START struct {
	UINT8 keyIndex;
	UINT8 isDefaultTx;
	UINT8 key[CRYPTO_WEP_KEY_LEN_MAX];
} MLAN_PACK_END key_Type_WEP_t;

typedef MLAN_PACK_START struct {
	UINT8 key[CRYPTO_AES_KEY_LEN_MAX];
} MLAN_PACK_END key_Type_AES_t;

typedef MLAN_PACK_START struct {
	UINT8 keyIndex;
	UINT8 isDefKey;
	UINT8 key[WAPI_KEY_LEN];
	UINT8 mickey[WAPI_MIC_LEN];
	UINT8 rxPN[WAPI_PN_LEN];
} MLAN_PACK_END key_Type_WAPI_t;

typedef MLAN_PACK_START struct {
	UINT8 ipn[CRYPTO_AES_CMAC_IPN_LEN];
	UINT8 reserved[2];
	UINT8 key[CRYPTO_AES_CMAC_KEY_LEN];
} MLAN_PACK_END key_Type_AES_CMAC_t;

typedef MLAN_PACK_START struct {
	UINT16 keyType;
	UINT16 keyInfo;
	UINT16 keyLen;
	MLAN_PACK_START union {
		key_Type_TKIP_t TKIP;
		key_Type_AES_t AES;
		key_Type_WEP_t WEP;

//#if defined(WAPI_HW_SUPPORT) || defined(WAPI_FW_SUPPORT)
//        key_Type_WAPI_t     WAPI;
//#endif
		key_Type_AES_CMAC_t iGTK;

	} MLAN_PACK_END keyEncypt;
} MLAN_PACK_END key_MgtMaterial_t;

/* deprecated but still around for backwards compatibility */
#define KEY_INFO_TKIP_MULTICAST     0x1
#define KEY_INFO_TKIP_UNICAST       0x2
#define KEY_INFO_TKIP_ENABLED       0x4

#define KEY_INFO_AES_MULTICAST      0x1
#define KEY_INFO_AES_UNICAST        0x2
#define KEY_INFO_AES_ENABLED        0x4

#endif
