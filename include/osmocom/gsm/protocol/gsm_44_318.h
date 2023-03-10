/*! \file gsm_44_318.h
 * Definitions according to 3GPP TS 44.318 6.8.0 Release 6. */

#pragma once

#include <stdint.h>
#include <osmocom/core/endian.h>

/* Table 11.1.1.2.1: Protocol Discriminator */
enum gan_pdisc {
	GA_PDISC_RC			= 0,
	GA_PDISC_CSR			= 1,
	GA_PDISC_PSR			= 2,
};

/* Table 11.1.1.4.1: Message types for URR */

enum gan_msg_type {
	GA_MT_RC_DISCOVERY_REQUEST	= 0x01,
	GA_MT_RC_DISCOVERY_ACCEPT	= 0x02,
	GA_MT_RC_DISCOVERY_REJECT	= 0x03,

	GA_MT_RC_REGISTER_REQUEST	= 0x10,
	GA_MT_RC_REGISTER_ACCEPT	= 0x11,
	GA_MT_RC_REGISTER_REDIRECT	= 0x12,
	GA_MT_RC_REGISTER_REJECT	= 0x13,
	GA_MT_RC_DEREGISTER		= 0x14,
	GA_MT_RC_REGISTER_UPDATE_UL	= 0x15,
	GA_MT_RC_REGISTER_UPDATE_DL	= 0x16,
	GA_MT_RC_CELL_BCAST_INFO	= 0x17,

	GA_MT_CSR_CIPH_MODE_CMD		= 0x20,
	GA_MT_CSR_CIPH_MODE_COMPL	= 0x21,

	GA_MT_CSR_ACT_CHAN		= 0x30,
	GA_MT_CSR_ACT_CHAN_ACK		= 0x31,
	GA_MT_CSR_ACT_CHAN_COMPL	= 0x32,
	GA_MT_CSR_ACT_CHAN_FAIL		= 0x33,
	GA_MT_CSR_CHAN_MODE_MOD		= 0x34,
	GA_MT_CSR_CHAN_MODE_MOD_ACK	= 0x35,

	GA_MT_CSR_RELEASE		= 0x40,
	GA_MT_CSR_RELEASE_COMPL		= 0x41,
	GA_MT_CSR_CLEAR_REQ		= 0x42,

	GA_MT_CSR_HO_ACCESS		= 0x50,
	GA_MT_CSR_HO_COMPL		= 0x51,
	GA_MT_CSR_UL_QUAL_IND		= 0x52,
	GA_MT_CSR_HO_INFO		= 0x53,
	GA_MT_CSR_HO_CMD		= 0x54,
	GA_MT_CSR_HO_FAIL		= 0x55,

	GA_MT_CSR_PAGING_REQ		= 0x60,
	GA_MT_CSR_PAGING_RESP		= 0x61,

	GA_MT_CSR_UL_DIRECT_XFER	= 0x70,
	GA_MT_CSR_DL_DIRECT_XFER	= 0x72,
	GA_MT_CSR_STATUS		= 0x73,
	GA_MT_RC_KEEPALIVE		= 0x74,
	GA_MT_CSR_CM_ENQ		= 0x75,
	GA_MT_CSR_CM_CHANGE		= 0x76,
	GA_MT_PSR_GPRS_SUSPEND_REQ	= 0x77,
	GA_RC_SYNC_INFO			= 0x78,
	GA_CSR_UTRAN_CM_CHG		= 0x79,

	GA_MT_CSR_REQUEST		= 0x80,
	GA_MT_CSR_REQUEST_ACCEPT	= 0x81,
	GA_MT_CSR_REQUEST_REJECT	= 0x82,
};

/* All tables in 10.1.x and 10.2.x / Table 11.2.1 */
enum gan_iei {
	GA_IE_MI		= 1,
	GA_IE_GAN_RELEASE_IND	= 2,
	GA_IE_RADIO_IE		= 3,
	GA_IE_GERAN_CELL_ID	= 4,
	GA_IE_LAC		= 5,
	GA_IE_GERAN_COV_IND	= 6,
	GA_IE_GAN_CM		= 7,
	GA_IE_GEO_LOC		= 8,
	GA_IE_DEF_SEGW_IP	= 9,
	GA_IE_DEF_SEGW_FQDN	= 10,
	GA_IE_REDIR_CTR		= 11,
	GA_IE_DISCOV_REJ_CAUSE	= 12,
	GA_IE_GANC_CELL_DESC	= 13,
	GA_IE_GANC_CTRL_CH_DESC	= 14,
	GA_IE_GERAN_CELL_ID_LIST= 15,
	GA_IE_TU3907_TIMER	= 16,
	GA_IE_RR_STATE		= 17,
	GA_IE_RAI		= 18,
	GA_IE_GAN_BAND		= 19,
	GA_IE_GARC_GACSR_STATE	= 20,
	GA_IE_REG_REJ_CAUSE	= 21,
	GA_IE_TU3906_TIMER	= 22,
	GA_IE_TU3910_TIMER	= 23,
	GA_IE_TU3902_TIMER	= 24,
	GA_IE_L3_MSG		= 26,
	GA_IE_CHAN_MODE		= 27,
	GA_IE_MS_CLASSMARK2	= 28,
	GA_IE_RR_CAUSE		= 29,
	GA_EI_CIPH_MODE_SET	= 30,
	GA_IE_GPRS_RESUMPTION	= 31,
	GA_IE_HO_FROM_GAN_CMD	= 32,
	GA_IE_UL_QUAL_IND	= 33,
	GA_IE_TLLI		= 34,
	GA_IE_PFI		= 35,
	GA_IE_SUSP_CAUSE	= 36,
	GA_IE_TU3920_TIMER	= 37,
	GA_IE_REQD_QOS		= 38,
	GA_IE_P_DEACT_CAUSE	= 39,
	GA_IE_REQD_UL_RATE	= 40,
	GA_IE_RAC		= 41,
	GA_IE_AP_LOCATION	= 42,
	GA_IE_TU4001_TIMER	= 43,
	GA_IE_LOC_STATUS	= 44,
	GA_IE_CIPH_RESP		= 45,
	GA_IE_CIPH_RAND		= 46,
	GA_IE_CIPH_MAC		= 47,
	GA_IE_CKSN		= 48,
	GA_IE_SAPI_ID		= 49,
	GA_IE_EST_CAUSE		= 50,
	GA_IE_CHAN_NEEDED	= 51,
	GA_IE_PDU_IN_ERROR	= 52,
	GA_IE_SAMPLE_SIZE	= 53,
	GA_IE_PAYLOAD_TYPE	= 54,
	GA_IE_MULTIRATE_CONF	= 55,
	GA_IE_MS_CLASSMARK3	= 56,
	GA_IE_LLC_PDU		= 57,
	GA_IE_LOC_BLACKL_IND	= 58,
	GA_IE_RESET_IND		= 59,
	GA_IE_TU4003_TIMER	= 60,
	GA_IE_AP_SERV_NAME	= 61,
	GA_IE_SERV_ZONE_INFO	= 62,
	GA_IE_RTP_RED_CONF	= 63,
	GA_IE_UTRAN_CLASSMARK	= 64,
	GA_IE_CM_ENQ_MASK	= 65,
	GA_IE_UTRAN_CELLID_LIST = 66,
	GA_IE_SERV_GANC_TBL_IND	= 67,
	GA_IE_AP_REG_IND	= 68,
	GA_IE_GAN_PLMN_LIST	= 69,
	GA_IE_REQD_GAN_SERV	= 71,
	GA_IE_BCAST_CONTAINER	= 72,
	GA_IE_3G_CELL_ID	= 73,
	GA_IE_MS_RADIO_ID	= 96,
	GA_IE_DEF_GANC_IP	= 97,
	GA_IE_DEF_GANC_FQDN	= 98,
	GA_IE_GPRS_IP_ADDR	= 99,
	GA_IE_GPRS_UDP_PORT	= 100,
	GA_IE_GANC_TCP_PORT	= 103,
	GA_IE_RTP_UDP_PORT	= 104,
	GA_IE_RTCP_UDP_PORT	= 105,
	GA_IE_GERAN_RCV_SIGL_LIST = 106,
	GA_IE_UTRAN_RCV_SIGL_LIST = 107,
};

/* 11.1.1 GA-RC and GA-CSR Message header IE */
struct gan_rc_csr_hdr {
#if OSMO_IS_LITTLE_ENDIAN
	uint16_t len;
	uint8_t pdisc:4,
		skip_ind:4;
	uint8_t msg_type;
	uint8_t data[0];
#elif OSMO_IS_BIG_ENDIAN
/* auto-generated from the little endian part above (libosmocore/contrib/struct_endianness.py) */
	uint16_t len;
	uint8_t skip_ind:4, pdisc:4;
	uint8_t msg_type;
	uint8_t data[0];
#endif
} __attribute__((packed));

/* 11.2.14.1: GAN Control Channel Description IE */
struct gan_cch_desc_ie {
#if OSMO_IS_LITTLE_ENDIAN
	uint8_t spare:1,
		ecmc:1,
		nmo:2,
		gprs:1,
		dtm:1,
		att:1,
		mscr:1;
	uint8_t t3212;
	uint8_t rac;
	uint8_t sgsnr:1,
		ecmp:1,
		re:1,
		pfcfm:1,
		tgecs:2,
		spare2:2;
	uint8_t access_class[2];
#elif OSMO_IS_BIG_ENDIAN
/* auto-generated from the little endian part above (libosmocore/contrib/struct_endianness.py) */
	uint8_t mscr:1, att:1, dtm:1, gprs:1, nmo:2, ecmc:1, spare:1;
	uint8_t t3212;
	uint8_t rac;
	uint8_t spare2:2, tgecs:2, pfcfm:1, re:1, ecmp:1, sgsnr:1;
	uint8_t access_class[2];
#endif
} __attribute__((packed));
