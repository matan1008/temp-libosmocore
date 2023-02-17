/*! \file gsm_08_18.h */
/* Updated to reflect TS 48.018 version 15.0.0 Release 15 */

#pragma once

#include <stdint.h>
#include <osmocom/core/endian.h>

/*! Fixed BVCI definitions (Section 5.4.1) */
#define BVCI_SIGNALLING	0x0000
#define BVCI_PTM	0x0001

/* typo backwards compatiblity */
#define BSSGP_PDUT_RA_CAPA_UDPATE BSSGP_PDUT_RA_CAPA_UPDATE

/*! BSSGP PDU types (Section 11.3.26 / Table 11.27) */
enum bssgp_pdu_type {
	/* PDUs between RL and BSSGP SAPs */
	BSSGP_PDUT_DL_UNITDATA		= 0x00,
	BSSGP_PDUT_UL_UNITDATA		= 0x01,
	BSSGP_PDUT_RA_CAPABILITY	= 0x02,
	/* PDUs between MBMS SAPs */
	BSSGP_PDUT_PTM_UNITDATA		= 0x03, /* reserved in later specs */
	BSSGP_PDUT_DL_MMBS_UNITDATA	= 0x04,
	BSSGP_PDUT_UL_MMBS_UNITDATA	= 0x05,
	/* PDUs between GMM SAPs */
	BSSGP_PDUT_PAGING_PS		= 0x06,
	BSSGP_PDUT_PAGING_CS		= 0x07,
	BSSGP_PDUT_RA_CAPA_UPDATE	= 0x08,
	BSSGP_PDUT_RA_CAPA_UPDATE_ACK	= 0x09,
	BSSGP_PDUT_RADIO_STATUS		= 0x0a,
	BSSGP_PDUT_SUSPEND		= 0x0b,
	BSSGP_PDUT_SUSPEND_ACK		= 0x0c,
	BSSGP_PDUT_SUSPEND_NACK		= 0x0d,
	BSSGP_PDUT_RESUME		= 0x0e,
	BSSGP_PDUT_RESUME_ACK		= 0x0f,
	BSSGP_PDUT_RESUME_NACK		= 0x10,
	BSSGP_PDUT_PAGING_PS_REJECT	= 0x11,
	BSSGP_PDUT_DUMMY_PAGING_PS	= 0x12,
	BSSGP_PDUT_DUMMY_PAGING_PS_RESP	= 0x13,
	BSSGP_PDUT_MS_REGISTR_ENQ	= 0x14,
	BSSGP_PDUT_MS_REGISTR_ENQ_RESP	= 0x15,
	/* PDus between NM SAPs */
	BSSGP_PDUT_BVC_BLOCK		= 0x20,
	BSSGP_PDUT_BVC_BLOCK_ACK	= 0x21,
	BSSGP_PDUT_BVC_RESET		= 0x22,
	BSSGP_PDUT_BVC_RESET_ACK	= 0x23,
	BSSGP_PDUT_BVC_UNBLOCK		= 0x24,
	BSSGP_PDUT_BVC_UNBLOCK_ACK	= 0x25,
	BSSGP_PDUT_FLOW_CONTROL_BVC	= 0x26,
	BSSGP_PDUT_FLOW_CONTROL_BVC_ACK	= 0x27,
	BSSGP_PDUT_FLOW_CONTROL_MS	= 0x28,
	BSSGP_PDUT_FLOW_CONTROL_MS_ACK	= 0x29,
	BSSGP_PDUT_FLUSH_LL		= 0x2a,
	BSSGP_PDUT_FLUSH_LL_ACK		= 0x2b,
	BSSGP_PDUT_LLC_DISCARD		= 0x2c,
	BSSGP_PDUT_FLOW_CONTROL_PFC	= 0x2d,
	BSSGP_PDUT_FLOW_CONTROL_PFC_ACK	= 0x2e,
	BSSGP_PDUT_SGSN_INVOKE_TRACE	= 0x40,
	BSSGP_PDUT_STATUS		= 0x41,
	BSSGP_PDUT_OVERLOAD		= 0x42,
	/* PDUs between PFM SAP's */
	BSSGP_PDUT_DOWNLOAD_BSS_PFC	= 0x50,
	BSSGP_PDUT_CREATE_BSS_PFC	= 0x51,
	BSSGP_PDUT_CREATE_BSS_PFC_ACK	= 0x52,
	BSSGP_PDUT_CREATE_BSS_PFC_NACK	= 0x53,
	BSSGP_PDUT_MODIFY_BSS_PFC	= 0x54,
	BSSGP_PDUT_MODIFY_BSS_PFC_ACK	= 0x55,
	BSSGP_PDUT_DELETE_BSS_PFC	= 0x56,
	BSSGP_PDUT_DELETE_BSS_PFC_ACK	= 0x57,
	BSSGP_PDUT_DELETE_BSS_PFC_REQ	= 0x58,
	BSSGP_PDUT_PS_HO_REQUIRED	= 0x59,
	BSSGP_PDUT_PS_HO_REQUIRED_ACK	= 0x5a,
	BSSGP_PDUT_PS_HO_REQUIRED_NACK	= 0x5b,
	BSSGP_PDUT_PS_HO_REQUEST	= 0x5c,
	BSSGP_PDUT_PS_HO_REQUEST_ACK	= 0x5d,
	BSSGP_PDUT_PS_HO_REQUEST_NACK	= 0x5e,
	BSSGP_PDUT_PS_HO_COMPLETE	= 0x91,
	BSSGP_PDUT_PS_HO_CANCEL		= 0x92,
	BSSGP_PDUT_PS_HO_COMPLETE_ACK	= 0x93,
	/* PDUs between LCS SAPs */
	BSSGP_PDUT_PERFORM_LOC_REQ	= 0x60,
	BSSGP_PDUT_PERFORM_LOC_RESP	= 0x61,
	BSSGP_PDUT_PERFORM_LOC_ABORT	= 0x62,
	BSSGP_PDUT_POSITION_COMMAND	= 0x63,
	BSSGP_PDUT_POSITION_RESPONSE	= 0x64,
	/* PDUs between RIM SAPs */
	BSSGP_PDUT_RAN_INFO		= 0x70,
	BSSGP_PDUT_RAN_INFO_REQ		= 0x71,
	BSSGP_PDUT_RAN_INFO_ACK		= 0x72,
	BSSGP_PDUT_RAN_INFO_ERROR	= 0x73,
	BSSGP_PDUT_RAN_INFO_APP_ERROR	= 0x74,
	/* PDUs between MBMS SAPs */
	BSSGP_PDUT_MBMS_START_REQ	= 0x80,
	BSSGP_PDUT_MBMS_START_RESP	= 0x81,
	BSSGP_PDUT_MBMS_STOP_REQ	= 0x82,
	BSSGP_PDUT_MBMS_STOP_RESP	= 0x83,
	BSSGP_PDUT_MBMS_UPDATE_REQ	= 0x84,
	BSSGP_PDUT_MBMS_UPDATE_RESP	= 0x85,
};

/*! BSSGP User-Data header (Section 10.2.1 and 10.2.2) */
struct bssgp_ud_hdr {
	uint8_t pdu_type;	/*!< BSSGP PDU type */
	uint32_t tlli;		/*!< Temporary Link-Local Identifier */
	uint8_t qos_profile[3];	/*!< QoS profile */
	uint8_t data[0];	/* optional/conditional IEs as TLVs */
} __attribute__((packed));

/*! BSSGP normal header */
struct bssgp_normal_hdr {
	uint8_t pdu_type;	/*!< BSSGP PDU type */
	uint8_t data[0];	/*!< optional/conditional IEs as TLVs */
};

/*! BSSGP Information Element Identifiers (Section 11.3 / Table 11.3) */
enum bssgp_iei_type {
	BSSGP_IE_ALIGNMENT		= 0x00,
	BSSGP_IE_BMAX_DEFAULT_MS	= 0x01,
	BSSGP_IE_BSS_AREA_ID		= 0x02,
	BSSGP_IE_BUCKET_LEAK_RATE	= 0x03,
	BSSGP_IE_BVCI			= 0x04,
	BSSGP_IE_BVC_BUCKET_SIZE	= 0x05,
	BSSGP_IE_BVC_MEASUREMENT	= 0x06,
	BSSGP_IE_CAUSE			= 0x07,
	BSSGP_IE_CELL_ID		= 0x08,
	BSSGP_IE_CHAN_NEEDED		= 0x09,
	BSSGP_IE_DRX_PARAMS		= 0x0a,
	BSSGP_IE_EMLPP_PRIO		= 0x0b,
	BSSGP_IE_FLUSH_ACTION		= 0x0c,
	BSSGP_IE_IMSI			= 0x0d,
	BSSGP_IE_LLC_PDU		= 0x0e,
	BSSGP_IE_LLC_FRAMES_DISCARDED	= 0x0f,
	BSSGP_IE_LOCATION_AREA		= 0x10,
	BSSGP_IE_MOBILE_ID		= 0x11,
	BSSGP_IE_MS_BUCKET_SIZE		= 0x12,
	BSSGP_IE_MS_RADIO_ACCESS_CAP	= 0x13,
	BSSGP_IE_OMC_ID			= 0x14,
	BSSGP_IE_PDU_IN_ERROR		= 0x15,
	BSSGP_IE_PDU_LIFETIME		= 0x16,
	BSSGP_IE_PRIORITY		= 0x17,
	BSSGP_IE_QOS_PROFILE		= 0x18,
	BSSGP_IE_RADIO_CAUSE		= 0x19,
	BSSGP_IE_RA_CAP_UPD_CAUSE	= 0x1a,
	BSSGP_IE_ROUTEING_AREA		= 0x1b,
	BSSGP_IE_R_DEFAULT_MS		= 0x1c,
	BSSGP_IE_SUSPEND_REF_NR		= 0x1d,
	BSSGP_IE_TAG			= 0x1e,
	BSSGP_IE_TLLI			= 0x1f,
	BSSGP_IE_TMSI			= 0x20,
	BSSGP_IE_TRACE_REFERENC		= 0x21,
	BSSGP_IE_TRACE_TYPE		= 0x22,
	BSSGP_IE_TRANSACTION_ID		= 0x23,
	BSSGP_IE_TRIGGER_ID		= 0x24,
	BSSGP_IE_NUM_OCT_AFF		= 0x25,
	BSSGP_IE_LSA_ID_LIST		= 0x26,
	BSSGP_IE_LSA_INFORMATION	= 0x27,
	BSSGP_IE_PACKET_FLOW_ID		= 0x28,
	BSSGP_IE_PACKET_FLOW_TIMER	= 0x29,
	BSSGP_IE_AGG_BSS_QOS_PROFILE	= 0x3a,
	BSSGP_IE_FEATURE_BITMAP		= 0x3b,
	BSSGP_IE_BUCKET_FULL_RATIO	= 0x3c,
	BSSGP_IE_SERVICE_UTRAN_CCO	= 0x3d,
	BSSGP_IE_NSEI			= 0x3e,
	BSSGP_IE_RRLP_APDU		= 0x3f,
	BSSGP_IE_LCS_QOS		= 0x40,
	BSSGP_IE_LCS_CLIENT_TYPE	= 0x41,
	BSSGP_IE_REQUESTED_GPS_AST_DATA	= 0x42,
	BSSGP_IE_LOCATION_TYPE		= 0x43,
	BSSGP_IE_LOCATION_ESTIMATE	= 0x44,
	BSSGP_IE_POSITIONING_DATA	= 0x45,
	BSSGP_IE_DECIPHERING_KEYS	= 0x46,
	BSSGP_IE_LCS_PRIORITY		= 0x47,
	BSSGP_IE_LCS_CAUSE		= 0x48,
	BSSGP_IE_LCS_CAPABILITY		= 0x49,
	BSSGP_IE_RRLP_FLAGS		= 0x4a,
	BSSGP_IE_RIM_APP_IDENTITY	= 0x4b,
	BSSGP_IE_RIM_SEQ_NR		= 0x4c,
	BSSGP_IE_RIM_REQ_APP_CONTAINER	= 0x4d,
	BSSGP_IE_RAN_INFO_APP_CONTAINER	= 0x4e,
	BSSGP_IE_RIM_PDU_INDICATIONS	= 0x4f,
	BSSGP_IE_PFC_FLOW_CTRL_PARAMS	= 0x52,
	BSSGP_IE_GLOBAL_CN_ID		= 0x53,
	BSSGP_IE_RIM_ROUTING_INFO	= 0x54,
	BSSGP_IE_RIM_PROTOCOL_VERSION	= 0x55,
	BSSGP_IE_APP_ERROR_CONTAINER	= 0x56,
	BSSGP_IE_RI_REQ_RIM_CONTAINER	= 0x57,
	BSSGP_IE_RI_RIM_CONTAINER	= 0x58,
	BSSGP_IE_RI_APP_ERROR_RIM_CONT	= 0x59,
	BSSGP_IE_RI_ACK_RIM_CONTAINER	= 0x5a,
	BSSGP_IE_RI_ERROR_RIM_COINTAINER= 0x5b,
	BSSGP_IE_TMGI			= 0x5c,
	BSSGP_IE_MBMS_SESSION_ID	= 0x5d,
	BSSGP_IE_MBMS_SESSION_DURATION	= 0x5e,
	BSSGP_IE_MBMS_SA_ID_LIST	= 0x5f,
	BSSGP_IE_MBMS_RESPONSE		= 0x60,
	BSSGP_IE_MBMS_RA_LIST		= 0x61,
	BSSGP_IE_MBMS_SESSION_INFO	= 0x62,
	BSSGP_IE_MBMS_STOP_CAUSE	= 0x63,
	BSSGP_IE_SBSS_TO_TBSS_TR_CONT	= 0x64,
	BSSGP_IE_TBSS_TO_SBSS_TR_CONT	= 0x65,
	BSSGP_IE_NAS_CONT_FOR_PS_HO	= 0x66,
	BSSGP_IE_PFC_TO_BE_SETUP_LIST	= 0x67,
	BSSGP_IE_LIST_OF_SETUP_PFC	= 0x68,
	BSSGP_IE_EXT_FEATURE_BITMAP	= 0x69,
	BSSGP_IE_SRC_TO_TGT_TR_CONT	= 0x6a,
	BSSGP_IE_TGT_TO_SRC_TR_CONT	= 0x6b,
	BSSGP_IE_NC_ID			= 0x6c,
	BSSGP_IE_PAGE_MODE		= 0x6d,
	BSSGP_IE_CONTAINER_ID		= 0x6e,
	BSSGP_IE_GLOBAL_TFI		= 0x6f,
	BSSGP_IE_IMEI			= 0x70,
	BSSGP_IE_TIME_TO_MBMS_DATA_XFR	= 0x71,
	BSSGP_IE_MBMS_SESSION_REP_NR	= 0x72,
	BSSGP_IE_INTER_RAT_HO_INFO	= 0x73,
	BSSGP_IE_PS_HO_COMMAND		= 0x74,
	BSSGP_IE_PS_HO_INDICATIONS	= 0x75,
	BSSGP_IE_SI_PSI_CONTAINER	= 0x76,
	BSSGP_IE_ACTIVE_PFC_LIST	= 0x77,
	BSSGP_IE_VELOCITY_DATA		= 0x78,
	BSSGP_IE_DTM_HO_COMMAND		= 0x79,
	BSSGP_IE_CS_INDICATION		= 0x7a,
	BSSGP_IE_RQD_GANNS_AST_DATA	= 0x7b,
	BSSGP_IE_GANSS_LOCATION_TYPE	= 0x7c,
	BSSGP_IE_GANSS_POSITIONING_DATA	= 0x7d,
	BSSGP_IE_FLOW_CTRL_GRANULARITY	= 0x7e,
	BSSGP_IE_ENB_ID			= 0x7f,
	BSSGP_IE_EUTRAN_IRAT_HO_INFO	= 0x80,
	BSSGP_IE_SUB_PID4RAT_FREQ_PRIO	= 0x81,
	BSSGP_IE_REQ4IRAT_HO_INFO	= 0x82,
	BSSGP_IE_RELIABLE_IRAT_HO_INFO	= 0x83,
	BSSGP_IE_SON_TRANSFER_APP_ID	= 0x84,
	BSSGP_IE_CSG_ID			= 0x85,
	BSSGP_IE_TAC			= 0x86,
	BSSGP_IE_REDIRECT_ATTEMPT_FLAG	= 0x87,
	BSSGP_IE_REDIRECTION_INDICATION	= 0x88,
	BSSGP_IE_REDIRECTION_COMPLETED	= 0x89,
	BSSGP_IE_UNCONF_SEND_STATE_VAR	= 0x8a,
	BSSGP_IE_IRAT_MEASUREMENT_CONF	= 0x8b,
	BSSGP_IE_SCI			= 0x8c,
	BSSGP_IE_GGSN_PGW_LOCATION	= 0x8d,
	BSSGP_IE_SELECTED_PLMN_ID	= 0x8e,
	BSSGP_IE_PRIO_CLASS_IND		= 0x8f,
	BSSGP_IE_SOURCE_CELL_ID		= 0x90,
	BSSGP_IE_IRAT_MEAS_CFG_E_EARFCN	= 0x91,
	BSSGP_IE_EDRX_PARAMETERS	= 0x92,
	BSSGP_IE_T_UNTIL_NEXT_PAGING	= 0x93,
	BSSGP_IE_COVERAGE_CLASS		= 0x98,
	BSSGP_IE_PAGING_ATTEMPT_INFO	= 0x99,
	BSSGP_IE_EXCEPTION_REPORT_FLAG	= 0x9a,
	BSSGP_IE_OLD_RA_ID		= 0x9b,
	BSSGP_IE_ATTACH_IND		= 0x9c,
	BSSGP_IE_PLMN_ID		= 0x9d,
	BSSGP_IE_MME_QUERY		= 0x9e,
	BSSGP_IE_SGSN_GROUP_ID		= 0x9f,
	BSSGP_IE_ADDITIONAL_PTMSI	= 0xa0,
	BSSGP_IE_UE_USAGE_TYPE		= 0xa1,
	BSSGP_IE_MLAT_TIMER		= 0xa2,
	BSSGP_IE_MLAT_TA		= 0xa3,
	BSSGP_IE_MS_SYNC_ACCURACY	= 0xa4,
	BSSGP_IE_BTS_RX_ACCURACY_LVL	= 0xa5,
	BSSGP_IE_TA_REQ			= 0xa6,
};

/*! Cause coding (Section 11.3.8 / Table 11.10) */
enum gprs_bssgp_cause {
	BSSGP_CAUSE_PROC_OVERLOAD		= 0x00,
	BSSGP_CAUSE_EQUIP_FAIL			= 0x01,
	BSSGP_CAUSE_TRASIT_NET_FAIL		= 0x02,
	BSSGP_CAUSE_CAPA_GREATER_0KPBS		= 0x03,
	BSSGP_CAUSE_UNKNOWN_MS			= 0x04,
	BSSGP_CAUSE_UNKNOWN_BVCI		= 0x05,
	BSSGP_CAUSE_CELL_TRAF_CONG		= 0x06,
	BSSGP_CAUSE_SGSN_CONG			= 0x07,
	BSSGP_CAUSE_OML_INTERV			= 0x08,
	BSSGP_CAUSE_BVCI_BLOCKED		= 0x09,
	BSSGP_CAUSE_PFC_CREATE_FAIL		= 0x0a,
	BSSGP_CAUSE_PFC_PREEMPTED		= 0x0b,
	BSSGP_CAUSE_ABQP_NOT_SUPP		= 0x0c,
	BSSGP_CAUSE_SEM_INCORR_PDU		= 0x20,
	BSSGP_CAUSE_INV_MAND_INF		= 0x21,
	BSSGP_CAUSE_MISSING_MAND_IE		= 0x22,
	BSSGP_CAUSE_MISSING_COND_IE		= 0x23,
	BSSGP_CAUSE_UNEXP_COND_IE		= 0x24,
	BSSGP_CAUSE_COND_IE_ERR			= 0x25,
	BSSGP_CAUSE_PDU_INCOMP_STATE		= 0x26,
	BSSGP_CAUSE_PROTO_ERR_UNSPEC		= 0x27,
	BSSGP_CAUSE_PDU_INCOMP_FEAT		= 0x28,
	BSSGP_CAUSE_REQ_INFO_NOT_AVAIL		= 0x29,
	BSSGP_CAUSE_UNKN_DST			= 0x2a,
	BSSGP_CAUSE_UNKN_RIM_AI			= 0x2b,
	BSSGP_CAUSE_INVAL_CONT_UI		= 0x2c,
	BSSGP_CAUSE_PFC_QUEUE			= 0x2d,
	BSSGP_CAUSE_PFC_CREATED			= 0x2e,
	BSSGP_CAUSE_T12_EXPIRY			= 0x2f,
	BSSGP_CAUSE_MS_UNDER_PS_HO		= 0x30,
	BSSGP_CAUSE_UL_QUALITY			= 0x31,
	BSSGP_CAUSE_UL_STRENGTH			= 0x32,
	BSSGP_CAUSE_DL_QUALITY			= 0x33,
	BSSGP_CAUSE_DL_STRENGTH			= 0x34,
	BSSGP_CAUSE_DISTANCE			= 0x35,
	BSSGP_CAUSE_BETTER_CELL			= 0x36,
	BSSGP_CAUSE_TRAFFIC			= 0x37,
	BSSGP_CAUSE_MS_RADIO_LOSS		= 0x38,
	BSSGP_CAUSE_MS_BACK_OLD_CHAN		= 0x39,
	BSSGP_CAUSE_T13_EXPIRY			= 0x3a,
	BSSGP_CAUSE_T14_EXPIRY			= 0x3b,
	BSSGP_CAUSE_NOT_ALL_PFC			= 0x3c,
	BSSGP_CAUSE_CS				= 0x3d,
	BSSGP_CAUSE_REQ_ALG_NOT_SUPP		= 0x3e,
	BSSGP_CAUSE_RELOC_FAIL			= 0x3f,
	BSSGP_CAUSE_DIR_RETRY			= 0x40,
	BSSGP_CAUSE_TIME_CRIT_RELOC		= 0x41,
	BSSGP_CAUSE_PS_HO_TARG_NA		= 0x42,
	BSSGP_CAUSE_PS_HO_TARG_NOT_SUPP		= 0x43,
	BSSGP_CAUSE_PUESBINE			= 0x44,
	BSSGP_CAUSE_DTM_HO_NO_CS_RES		= 0x45,
	BSSGP_CAUSE_DTM_HO_PS_ALLOC_FAIL	= 0x46,
	BSSGP_CAUSE_DTM_HO_T24_EXPIRY		= 0x47,
	BSSGP_CAUSE_DTM_HO_INVAL_CS_IND		= 0x48,
	BSSGP_CAUSE_DTM_HO_T23_EXPIRY		= 0x49,
	BSSGP_CAUSE_DTM_HO_MSC_ERR		= 0x4a,
	BSSGP_CAUSE_INVAL_CSG_CELL		= 0x4b,
};

/* Feature Bitmap (Section 11.3.45) */
#define	BSSGP_FEAT_PFC		0x01	/* Packet Flow Context */
#define	BSSGP_FEAT_CBL		0x02	/* Current Bucket Level */
#define	BSSGP_FEAT_INR		0x04	/* Inter-NSE re-routing */
#define	BSSGP_FEAT_LCS		0x08	/* Location Services */
#define	BSSGP_FEAT_RIM		0x10	/* RAN Inoformation Management */
#define	BSSGP_FEAT_PFC_FC	0x20	/* PFC Flow Control */
#define	BSSGP_FEAT_ERS		0x40	/* Enhanced Radio Status */
#define	BSSGP_FEAT_MBMS		0x80	/* Multimedia Broadcast */

/* Extended Feature Bitmap (Section 11.3.84) */
#define	BSSGP_XFEAT_PSHO	0x01	/* PS Handover */
#define	BSSGP_XFEAT_GBIT	0x02	/* Gigabit Interface */
#define	BSSGP_XFEAT_MOCN	0x04	/* Multi-Operator CN */
#define	BSSGP_XFEAT_CSPS	0x08	/* CS/PS coordination enhancements */
#define	BSSGP_XFEAT_ECIoT	0x10	/* EC-GSM-IoT */
#define	BSSGP_XFEAT_DCN		0x20	/* Dedicated CN */
#define	BSSGP_XFEAT_eDRX	0x40	/* eDRX */
#define	BSSGP_XFEAT_MSAD	0x80	/* MS-assisted Dedicated CN selection */

/* Flow Control Granularity (Section 11.3.102) */
enum bssgp_fc_granularity {
	BSSGP_FC_GRAN_100	= 0,
	BSSGP_FC_GRAN_1000	= 1,
	BSSGP_FC_GRAN_10000	= 2,
	BSSGP_FC_GRAN_100000	= 3,
};

/* RAN-INFORMATION-REQUEST PDU Type Extension
 * 3GPP TS 48.018, table 11.3.65.1 */
enum bssgp_rim_pdu_type {
	RIM_PDU_TYPE_STOP	= 0,
	RIM_PDU_TYPE_SING_REP	= 1,
	RIM_PDU_TYPE_MULT_REP	= 2,
};

/* RIM PDU Indications
 * 3GPP TS 48.018, section 11.3.65.0 */
struct bssgp_rim_pdu_ind {
#if OSMO_IS_LITTLE_ENDIAN
		uint8_t ack_requested:1,
			pdu_type_ext:3,
			reserved:4;
#elif OSMO_IS_BIG_ENDIAN
/* auto-generated from the little endian part above (libosmocore/contrib/struct_endianness.py) */
		uint8_t reserved:4, pdu_type_ext:3, ack_requested:1;
#endif
} __attribute__ ((packed));
