typedef enum { IPv4, IPv6 } IPFamily;

struct ip6_hdr {
	union {
		struct ip6_hdrctl {
			uint32 ip6_un1_flow; /* 4 bits version, 8 bits TC, 20 bits
                                      flow-ID */
			uint16 ip6_un1_plen; /* payload length */
			uint8  ip6_un1_nxt;  /* next header */
			uint8  ip6_un1_hlim; /* hop limit */
		} ip6_un1;
		uint8 ip6_un2_vfc;     /* 4 bits version, top 4 bits tclass */
	} ip6_ctlun;
	struct in6_addr ip6_src;   /* source address */
	struct in6_addr ip6_dst;   /* destination address */
};

struct ip4_hdr {
	union {
		struct ip4_hdrctl {
			uint8 ip4_version_IHL /* 4 bits version, 4 bits Internet header length */
            uint8 ip4_tos /* 8 bits type of service */
			uint16 ip4_un1_plen; /* total length */
            uint16 ip4_identify; /* Identification Fragment */
            uint16 ip4_offset; /* Fragment Offset */
            uint8 ip4_ttl; /* Time to live */
			uint8  ip4_protocol;  /* Protocol */
			uint16  ip4_checksum; /* Check Sum */
		} ip4_un1;
		uint8 ip4_un2_vfc;     /* 4 bits version, 4 bits Internet header length */
	} ip4_ctlun;
	struct in6_addr ip4_src;   /* source address */
	struct in6_addr ip4_dst;   /* destination address */
};
