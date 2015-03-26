//// Uncomment to get minimum footprint (suitable for 1-2 concurrent calls only)
//#define PJ_CONFIG_MINIMAL_SIZE
//
//// Uncomment to get maximum performance
//#define PJ_CONFIG_MAXIMUM_SPEED
/* To reduce socket buffers */
//#define PJ_STUN_SOCK_PKT_LEN			(160+200)		/* 2000 */
//#define PJ_STUN_MAX_PKT_LEN			PJ_STUN_SOCK_PKT_LEN	/*  800 */
//#define PJ_TURN_MAX_PKT_LEN			PJ_STUN_MAX_PKT_LEN	/* 3000 */

/* Reduce the size of the respective sessions */
//#define PJ_ICE_ST_MAX_CAND			4			/* 8 */
//#define PJ_ICE_COMP_BITS			0			/* 1 */
//#define PJ_ICE_MAX_CAND				(PJ_ICE_ST_MAX_CAND*2)	/* 16 */
//#define PJ_ICE_MAX_CHECKS			(PJ_ICE_ST_MAX_CAND*PJ_ICE_ST_MAX_CAND)	/* 32 */

/* Log level < 5 frees up 1000 bytes of buffer in the STUN session! */
//#define PJ_LOG_MAX_LEVEL			4                       /* 5 */

/* A lazy pool memory usage optimization.. */
//#define PJNATH_POOL_LEN_ICE_SESS		    128
//#define PJNATH_POOL_INC_ICE_SESS		    128
//#define PJNATH_POOL_LEN_ICE_STRANS		    128
//#define PJNATH_POOL_INC_ICE_STRANS		    128
//#define PJNATH_POOL_LEN_NATCK				128
//#define PJNATH_POOL_INC_NATCK				128
//#define PJNATH_POOL_LEN_STUN_SESS		    128
//#define PJNATH_POOL_INC_STUN_SESS		    128
//#define PJNATH_POOL_LEN_STUN_TDATA		    128
//#define PJNATH_POOL_INC_STUN_TDATA		    128

//#define PJNATH_POOL_LEN_TURN_SESS		    128
//#define PJNATH_POOL_INC_TURN_SESS		    128
//#define PJNATH_POOL_LEN_TURN_SOCK		    128
//#define PJNATH_POOL_INC_TURN_SOCK		    128
//*/

//#define PJ_ICE_TA_VAL						50	//default 20
//#define PJ_STUN_RTO_VALUE					300 //default 100
//#define PJNATH_ICE_PRIO_STD 0

//#define ICE_CONTROLLED_AGENT_WAIT_NOMINATION_TIMEOUT	-1

//#define PJ_ICE_CANCEL_ALL	0

#include <pj/config_site_sample.h> 