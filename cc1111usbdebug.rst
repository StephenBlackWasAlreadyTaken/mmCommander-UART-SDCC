                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.4.0 #8981 (Oct 10 2014) (Mac OS X x86_64)
                                      4 ; This file was generated Tue Apr 21 08:15:47 2015
                                      5 ;--------------------------------------------------------
                                      6 	.module cc1111usbdebug
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _txdata
                                     13 	.globl _USBIF
                                     14 	.globl _MODE
                                     15 	.globl _RE
                                     16 	.globl _SLAVE
                                     17 	.globl _FE
                                     18 	.globl _ERR
                                     19 	.globl _RX_BYTE
                                     20 	.globl _TX_BYTE
                                     21 	.globl _ACTIVE
                                     22 	.globl _B_7
                                     23 	.globl _B_6
                                     24 	.globl _B_5
                                     25 	.globl _B_4
                                     26 	.globl _B_3
                                     27 	.globl _B_2
                                     28 	.globl _B_1
                                     29 	.globl _B_0
                                     30 	.globl _WDTIF
                                     31 	.globl _P1IF
                                     32 	.globl _UTX1IF
                                     33 	.globl _UTX0IF
                                     34 	.globl _P2IF
                                     35 	.globl _ACC_7
                                     36 	.globl _ACC_6
                                     37 	.globl _ACC_5
                                     38 	.globl _ACC_4
                                     39 	.globl _ACC_3
                                     40 	.globl _ACC_2
                                     41 	.globl _ACC_1
                                     42 	.globl _ACC_0
                                     43 	.globl _OVFIM
                                     44 	.globl _T4CH1IF
                                     45 	.globl _T4CH0IF
                                     46 	.globl _T4OVFIF
                                     47 	.globl _T3CH1IF
                                     48 	.globl _T3CH0IF
                                     49 	.globl _T3OVFIF
                                     50 	.globl _CY
                                     51 	.globl _AC
                                     52 	.globl _F0
                                     53 	.globl _RS1
                                     54 	.globl _RS0
                                     55 	.globl _OV
                                     56 	.globl _F1
                                     57 	.globl _P
                                     58 	.globl _STIF
                                     59 	.globl _P0IF
                                     60 	.globl _T4IF
                                     61 	.globl _T3IF
                                     62 	.globl _T2IF
                                     63 	.globl _T1IF
                                     64 	.globl _DMAIF
                                     65 	.globl _P0IE
                                     66 	.globl _T4IE
                                     67 	.globl _T3IE
                                     68 	.globl _T2IE
                                     69 	.globl _T1IE
                                     70 	.globl _DMAIE
                                     71 	.globl _EA
                                     72 	.globl _STIE
                                     73 	.globl _ENCIE
                                     74 	.globl _URX1IE
                                     75 	.globl _URX0IE
                                     76 	.globl _ADCIE
                                     77 	.globl _RFTXRXIE
                                     78 	.globl _P2_7
                                     79 	.globl _P2_6
                                     80 	.globl _P2_5
                                     81 	.globl _P2_4
                                     82 	.globl _P2_3
                                     83 	.globl _P2_2
                                     84 	.globl _P2_1
                                     85 	.globl _P2_0
                                     86 	.globl _ENCIF_1
                                     87 	.globl _ENCIF_0
                                     88 	.globl _P1_7
                                     89 	.globl _P1_6
                                     90 	.globl _P1_5
                                     91 	.globl _P1_4
                                     92 	.globl _P1_3
                                     93 	.globl _P1_2
                                     94 	.globl _P1_1
                                     95 	.globl _P1_0
                                     96 	.globl _URX1IF
                                     97 	.globl _ADCIF
                                     98 	.globl _URX0IF
                                     99 	.globl _IT1
                                    100 	.globl _RFTXRXIF
                                    101 	.globl _IT0
                                    102 	.globl _P0_7
                                    103 	.globl _P0_6
                                    104 	.globl _P0_5
                                    105 	.globl _P0_4
                                    106 	.globl _P0_3
                                    107 	.globl _P0_2
                                    108 	.globl _P0_1
                                    109 	.globl _P0_0
                                    110 	.globl _P2DIR
                                    111 	.globl _P1DIR
                                    112 	.globl _P0DIR
                                    113 	.globl _U1GCR
                                    114 	.globl _U1UCR
                                    115 	.globl _U1BAUD
                                    116 	.globl _U1DBUF
                                    117 	.globl _U1CSR
                                    118 	.globl _P2INP
                                    119 	.globl _P1INP
                                    120 	.globl _P2SEL
                                    121 	.globl _P1SEL
                                    122 	.globl _P0SEL
                                    123 	.globl _ADCCFG
                                    124 	.globl _PERCFG
                                    125 	.globl _B
                                    126 	.globl _T4CC1
                                    127 	.globl _T4CCTL1
                                    128 	.globl _T4CC0
                                    129 	.globl _T4CCTL0
                                    130 	.globl _T4CTL
                                    131 	.globl _T4CNT
                                    132 	.globl _RFIF
                                    133 	.globl _IRCON2
                                    134 	.globl _T1CCTL2
                                    135 	.globl _T1CCTL1
                                    136 	.globl _T1CCTL0
                                    137 	.globl _T1CTL
                                    138 	.globl _T1CNTH
                                    139 	.globl _T1CNTL
                                    140 	.globl _RFST
                                    141 	.globl _ACC
                                    142 	.globl _T1CC2H
                                    143 	.globl _T1CC2L
                                    144 	.globl _T1CC1H
                                    145 	.globl _T1CC1L
                                    146 	.globl _T1CC0H
                                    147 	.globl _T1CC0L
                                    148 	.globl _RFD
                                    149 	.globl _TIMIF
                                    150 	.globl _DMAREQ
                                    151 	.globl _DMAARM
                                    152 	.globl _DMA0CFGH
                                    153 	.globl _DMA0CFGL
                                    154 	.globl _DMA1CFGH
                                    155 	.globl _DMA1CFGL
                                    156 	.globl _DMAIRQ
                                    157 	.globl _PSW
                                    158 	.globl _T3CC1
                                    159 	.globl _T3CCTL1
                                    160 	.globl _T3CC0
                                    161 	.globl _T3CCTL0
                                    162 	.globl _T3CTL
                                    163 	.globl _T3CNT
                                    164 	.globl _WDCTL
                                    165 	.globl __SFRC8
                                    166 	.globl _MEMCTR
                                    167 	.globl _CLKCON
                                    168 	.globl _U0GCR
                                    169 	.globl _U0UCR
                                    170 	.globl __SFRC3
                                    171 	.globl _U0BAUD
                                    172 	.globl _U0DBUF
                                    173 	.globl _IRCON
                                    174 	.globl __SFRBF
                                    175 	.globl _SLEEP
                                    176 	.globl _RNDH
                                    177 	.globl _RNDL
                                    178 	.globl _ADCH
                                    179 	.globl _ADCL
                                    180 	.globl _IP1
                                    181 	.globl _IEN1
                                    182 	.globl __SFRB7
                                    183 	.globl _ADCCON3
                                    184 	.globl _ADCCON2
                                    185 	.globl _ADCCON1
                                    186 	.globl _ENCCS
                                    187 	.globl _ENCDO
                                    188 	.globl _ENCDI
                                    189 	.globl __SFRB0
                                    190 	.globl _FWDATA
                                    191 	.globl _FCTL
                                    192 	.globl _FADDRH
                                    193 	.globl _FADDRL
                                    194 	.globl _FWT
                                    195 	.globl __SFRAA
                                    196 	.globl _IP0
                                    197 	.globl _IEN0
                                    198 	.globl __SFRA7
                                    199 	.globl _WORTIME1
                                    200 	.globl _WORTIME0
                                    201 	.globl _WOREVT1
                                    202 	.globl _WOREVT0
                                    203 	.globl _WORCTRL
                                    204 	.globl _WORIRQ
                                    205 	.globl _P2
                                    206 	.globl __SFR9F
                                    207 	.globl _T2CTL
                                    208 	.globl _T2PR
                                    209 	.globl _T2CT
                                    210 	.globl _S1CON
                                    211 	.globl _IEN2
                                    212 	.globl __SFR99
                                    213 	.globl _S0CON
                                    214 	.globl __SFR97
                                    215 	.globl __SFR96
                                    216 	.globl __SFR95
                                    217 	.globl __SFR94
                                    218 	.globl __XPAGE
                                    219 	.globl _MPAGE
                                    220 	.globl _DPS
                                    221 	.globl _RFIM
                                    222 	.globl _P1
                                    223 	.globl _P0INP
                                    224 	.globl __SFR8E
                                    225 	.globl _P1IEN
                                    226 	.globl _PICTL
                                    227 	.globl _P2IFG
                                    228 	.globl _P1IFG
                                    229 	.globl _P0IFG
                                    230 	.globl _TCON
                                    231 	.globl _PCON
                                    232 	.globl _U0CSR
                                    233 	.globl _DPH1
                                    234 	.globl _DPL1
                                    235 	.globl _DPH0
                                    236 	.globl _DPL0
                                    237 	.globl _SP
                                    238 	.globl _P0
                                    239 	.globl _USBFIFO
                                    240 	.globl _USBF5
                                    241 	.globl _USBF4
                                    242 	.globl _USBF3
                                    243 	.globl _USBF2
                                    244 	.globl _USBF1
                                    245 	.globl _USBF0
                                    246 	.globl _USBCNTH
                                    247 	.globl _USBCNTL
                                    248 	.globl _USBCNT0
                                    249 	.globl _USBCSOH
                                    250 	.globl _USBCSOL
                                    251 	.globl _USBMAXO
                                    252 	.globl _USBCSIH
                                    253 	.globl _USBCSIL
                                    254 	.globl _USBCS0
                                    255 	.globl _USBMAXI
                                    256 	.globl _USBINDEX
                                    257 	.globl _USBFRMH
                                    258 	.globl _USBFRML
                                    259 	.globl _USBCIE
                                    260 	.globl _USBOIE
                                    261 	.globl _USBIIE
                                    262 	.globl _USBCIF
                                    263 	.globl _USBOIF
                                    264 	.globl _USBIIF
                                    265 	.globl _USBPOW
                                    266 	.globl _USBADDR
                                    267 	.globl _X_P2DIR
                                    268 	.globl _X_P1DIR
                                    269 	.globl _X_P0DIR
                                    270 	.globl _X_U1GCR
                                    271 	.globl _X_U1UCR
                                    272 	.globl _X_U1BAUD
                                    273 	.globl _X_U1DBUF
                                    274 	.globl _X_U1CSR
                                    275 	.globl _X_P2INP
                                    276 	.globl _X_P1INP
                                    277 	.globl _X_P2SEL
                                    278 	.globl _X_P1SEL
                                    279 	.globl _X_P0SEL
                                    280 	.globl _X_ADCCFG
                                    281 	.globl _X_PERCFG
                                    282 	.globl __NA_B
                                    283 	.globl _X_T4CC1
                                    284 	.globl _X_T4CCTL1
                                    285 	.globl _X_T4CC0
                                    286 	.globl _X_T4CCTL0
                                    287 	.globl _X_T4CTL
                                    288 	.globl _X_T4CNT
                                    289 	.globl _X_RFIF
                                    290 	.globl __NA_IRCON2
                                    291 	.globl _X_T1CCTL2
                                    292 	.globl _X_T1CCTL1
                                    293 	.globl _X_T1CCTL0
                                    294 	.globl _X_T1CTL
                                    295 	.globl _X_T1CNTH
                                    296 	.globl _X_T1CNTL
                                    297 	.globl _X_RFST
                                    298 	.globl __NA_ACC
                                    299 	.globl _X_T1CC2H
                                    300 	.globl _X_T1CC2L
                                    301 	.globl _X_T1CC1H
                                    302 	.globl _X_T1CC1L
                                    303 	.globl _X_T1CC0H
                                    304 	.globl _X_T1CC0L
                                    305 	.globl _X_RFD
                                    306 	.globl _X_TIMIF
                                    307 	.globl _X_DMAREQ
                                    308 	.globl _X_DMAARM
                                    309 	.globl _X_DMA0CFGH
                                    310 	.globl _X_DMA0CFGL
                                    311 	.globl _X_DMA1CFGH
                                    312 	.globl _X_DMA1CFGL
                                    313 	.globl _X_DMAIRQ
                                    314 	.globl __NA_PSW
                                    315 	.globl _X_T3CC1
                                    316 	.globl _X_T3CCTL1
                                    317 	.globl _X_T3CC0
                                    318 	.globl _X_T3CCTL0
                                    319 	.globl _X_T3CTL
                                    320 	.globl _X_T3CNT
                                    321 	.globl _X_WDCTL
                                    322 	.globl __X_SFRC8
                                    323 	.globl _X_MEMCTR
                                    324 	.globl _X_CLKCON
                                    325 	.globl _X_U0GCR
                                    326 	.globl _X_U0UCR
                                    327 	.globl __X_SFRC3
                                    328 	.globl _X_U0BAUD
                                    329 	.globl _X_U0DBUF
                                    330 	.globl __NA_IRCON
                                    331 	.globl __X_SFRBF
                                    332 	.globl _X_SLEEP
                                    333 	.globl _X_RNDH
                                    334 	.globl _X_RNDL
                                    335 	.globl _X_ADCH
                                    336 	.globl _X_ADCL
                                    337 	.globl __NA_IP1
                                    338 	.globl __NA_IEN1
                                    339 	.globl __X_SFRB7
                                    340 	.globl _X_ADCCON3
                                    341 	.globl _X_ADCCON2
                                    342 	.globl _X_ADCCON1
                                    343 	.globl _X_ENCCS
                                    344 	.globl _X_ENCDO
                                    345 	.globl _X_ENCDI
                                    346 	.globl __X_SFRB0
                                    347 	.globl _X_FWDATA
                                    348 	.globl _X_FCTL
                                    349 	.globl _X_FADDRH
                                    350 	.globl _X_FADDRL
                                    351 	.globl _X_FWT
                                    352 	.globl __X_SFRAA
                                    353 	.globl __NA_IP0
                                    354 	.globl __NA_IEN0
                                    355 	.globl __X_SFRA7
                                    356 	.globl _X_WORTIME1
                                    357 	.globl _X_WORTIME0
                                    358 	.globl _X_WOREVT1
                                    359 	.globl _X_WOREVT0
                                    360 	.globl _X_WORCTRL
                                    361 	.globl _X_WORIRQ
                                    362 	.globl __NA_P2
                                    363 	.globl __X_SFR9F
                                    364 	.globl _X_T2CTL
                                    365 	.globl _X_T2PR
                                    366 	.globl _X_T2CT
                                    367 	.globl __NA_S1CON
                                    368 	.globl __NA_IEN2
                                    369 	.globl __X_SFR99
                                    370 	.globl __NA_S0CON
                                    371 	.globl __X_SFR97
                                    372 	.globl __X_SFR96
                                    373 	.globl __X_SFR95
                                    374 	.globl __X_SFR94
                                    375 	.globl _X_MPAGE
                                    376 	.globl __NA_DPS
                                    377 	.globl _X_RFIM
                                    378 	.globl __NA_P1
                                    379 	.globl _X_P0INP
                                    380 	.globl __X_SFR8E
                                    381 	.globl _X_P1IEN
                                    382 	.globl _X_PICTL
                                    383 	.globl _X_P2IFG
                                    384 	.globl _X_P1IFG
                                    385 	.globl _X_P0IFG
                                    386 	.globl __NA_TCON
                                    387 	.globl __NA_PCON
                                    388 	.globl _X_U0CSR
                                    389 	.globl __NA_DPH1
                                    390 	.globl __NA_DPL1
                                    391 	.globl __NA_DPH0
                                    392 	.globl __NA_DPL0
                                    393 	.globl __NA_SP
                                    394 	.globl __NA_P0
                                    395 	.globl _I2SCLKF2
                                    396 	.globl _I2SCLKF1
                                    397 	.globl _I2SCLKF0
                                    398 	.globl _I2SSTAT
                                    399 	.globl _I2SWCNT
                                    400 	.globl _I2SDATH
                                    401 	.globl _I2SDATL
                                    402 	.globl _I2SCFG1
                                    403 	.globl _I2SCFG0
                                    404 	.globl _VCO_VC_DAC
                                    405 	.globl _PKTSTATUS
                                    406 	.globl _MARCSTATE
                                    407 	.globl _RSSI
                                    408 	.globl _LQI
                                    409 	.globl _FREQEST
                                    410 	.globl _VERSION
                                    411 	.globl _PARTNUM
                                    412 	.globl __XREGDF35
                                    413 	.globl __XREGDF34
                                    414 	.globl __XREGDF33
                                    415 	.globl __XREGDF32
                                    416 	.globl _IOCFG0
                                    417 	.globl _IOCFG1
                                    418 	.globl _IOCFG2
                                    419 	.globl _PA_TABLE0
                                    420 	.globl _PA_TABLE1
                                    421 	.globl _PA_TABLE2
                                    422 	.globl _PA_TABLE3
                                    423 	.globl _PA_TABLE4
                                    424 	.globl _PA_TABLE5
                                    425 	.globl _PA_TABLE6
                                    426 	.globl _PA_TABLE7
                                    427 	.globl __XREGDF26
                                    428 	.globl _TEST0
                                    429 	.globl _TEST1
                                    430 	.globl _TEST2
                                    431 	.globl __XREGDF22
                                    432 	.globl __XREGDF21
                                    433 	.globl __XREGDF20
                                    434 	.globl _FSCAL0
                                    435 	.globl _FSCAL1
                                    436 	.globl _FSCAL2
                                    437 	.globl _FSCAL3
                                    438 	.globl _FREND0
                                    439 	.globl _FREND1
                                    440 	.globl _AGCCTRL0
                                    441 	.globl _AGCCTRL1
                                    442 	.globl _AGCCTRL2
                                    443 	.globl _BSCFG
                                    444 	.globl _FOCCFG
                                    445 	.globl _MCSM0
                                    446 	.globl _MCSM1
                                    447 	.globl _MCSM2
                                    448 	.globl _DEVIATN
                                    449 	.globl _MDMCFG0
                                    450 	.globl _MDMCFG1
                                    451 	.globl _MDMCFG2
                                    452 	.globl _MDMCFG3
                                    453 	.globl _MDMCFG4
                                    454 	.globl _FREQ0
                                    455 	.globl _FREQ1
                                    456 	.globl _FREQ2
                                    457 	.globl _FSCTRL0
                                    458 	.globl _FSCTRL1
                                    459 	.globl _CHANNR
                                    460 	.globl _ADDR
                                    461 	.globl _PKTCTRL0
                                    462 	.globl _PKTCTRL1
                                    463 	.globl _PKTLEN
                                    464 	.globl _SYNC0
                                    465 	.globl _SYNC1
                                    466 	.globl _MDMCTRL0H
                                    467 	.globl _debugEP0Req
                                    468 	.globl _debug
                                    469 ;--------------------------------------------------------
                                    470 ; special function registers
                                    471 ;--------------------------------------------------------
                                    472 	.area RSEG    (ABS,DATA)
      000000                        473 	.org 0x0000
                           000080   474 _P0	=	0x0080
                           000081   475 _SP	=	0x0081
                           000082   476 _DPL0	=	0x0082
                           000083   477 _DPH0	=	0x0083
                           000084   478 _DPL1	=	0x0084
                           000085   479 _DPH1	=	0x0085
                           000086   480 _U0CSR	=	0x0086
                           000087   481 _PCON	=	0x0087
                           000088   482 _TCON	=	0x0088
                           000089   483 _P0IFG	=	0x0089
                           00008A   484 _P1IFG	=	0x008a
                           00008B   485 _P2IFG	=	0x008b
                           00008C   486 _PICTL	=	0x008c
                           00008D   487 _P1IEN	=	0x008d
                           00008E   488 __SFR8E	=	0x008e
                           00008F   489 _P0INP	=	0x008f
                           000090   490 _P1	=	0x0090
                           000091   491 _RFIM	=	0x0091
                           000092   492 _DPS	=	0x0092
                           000093   493 _MPAGE	=	0x0093
                           000093   494 __XPAGE	=	0x0093
                           000094   495 __SFR94	=	0x0094
                           000095   496 __SFR95	=	0x0095
                           000096   497 __SFR96	=	0x0096
                           000097   498 __SFR97	=	0x0097
                           000098   499 _S0CON	=	0x0098
                           000099   500 __SFR99	=	0x0099
                           00009A   501 _IEN2	=	0x009a
                           00009B   502 _S1CON	=	0x009b
                           00009C   503 _T2CT	=	0x009c
                           00009D   504 _T2PR	=	0x009d
                           00009E   505 _T2CTL	=	0x009e
                           00009F   506 __SFR9F	=	0x009f
                           0000A0   507 _P2	=	0x00a0
                           0000A1   508 _WORIRQ	=	0x00a1
                           0000A2   509 _WORCTRL	=	0x00a2
                           0000A3   510 _WOREVT0	=	0x00a3
                           0000A4   511 _WOREVT1	=	0x00a4
                           0000A5   512 _WORTIME0	=	0x00a5
                           0000A6   513 _WORTIME1	=	0x00a6
                           0000A7   514 __SFRA7	=	0x00a7
                           0000A8   515 _IEN0	=	0x00a8
                           0000A9   516 _IP0	=	0x00a9
                           0000AA   517 __SFRAA	=	0x00aa
                           0000AB   518 _FWT	=	0x00ab
                           0000AC   519 _FADDRL	=	0x00ac
                           0000AD   520 _FADDRH	=	0x00ad
                           0000AE   521 _FCTL	=	0x00ae
                           0000AF   522 _FWDATA	=	0x00af
                           0000B0   523 __SFRB0	=	0x00b0
                           0000B1   524 _ENCDI	=	0x00b1
                           0000B2   525 _ENCDO	=	0x00b2
                           0000B3   526 _ENCCS	=	0x00b3
                           0000B4   527 _ADCCON1	=	0x00b4
                           0000B5   528 _ADCCON2	=	0x00b5
                           0000B6   529 _ADCCON3	=	0x00b6
                           0000B7   530 __SFRB7	=	0x00b7
                           0000B8   531 _IEN1	=	0x00b8
                           0000B9   532 _IP1	=	0x00b9
                           0000BA   533 _ADCL	=	0x00ba
                           0000BB   534 _ADCH	=	0x00bb
                           0000BC   535 _RNDL	=	0x00bc
                           0000BD   536 _RNDH	=	0x00bd
                           0000BE   537 _SLEEP	=	0x00be
                           0000BF   538 __SFRBF	=	0x00bf
                           0000C0   539 _IRCON	=	0x00c0
                           0000C1   540 _U0DBUF	=	0x00c1
                           0000C2   541 _U0BAUD	=	0x00c2
                           0000C3   542 __SFRC3	=	0x00c3
                           0000C4   543 _U0UCR	=	0x00c4
                           0000C5   544 _U0GCR	=	0x00c5
                           0000C6   545 _CLKCON	=	0x00c6
                           0000C7   546 _MEMCTR	=	0x00c7
                           0000C8   547 __SFRC8	=	0x00c8
                           0000C9   548 _WDCTL	=	0x00c9
                           0000CA   549 _T3CNT	=	0x00ca
                           0000CB   550 _T3CTL	=	0x00cb
                           0000CC   551 _T3CCTL0	=	0x00cc
                           0000CD   552 _T3CC0	=	0x00cd
                           0000CE   553 _T3CCTL1	=	0x00ce
                           0000CF   554 _T3CC1	=	0x00cf
                           0000D0   555 _PSW	=	0x00d0
                           0000D1   556 _DMAIRQ	=	0x00d1
                           0000D2   557 _DMA1CFGL	=	0x00d2
                           0000D3   558 _DMA1CFGH	=	0x00d3
                           0000D4   559 _DMA0CFGL	=	0x00d4
                           0000D5   560 _DMA0CFGH	=	0x00d5
                           0000D6   561 _DMAARM	=	0x00d6
                           0000D7   562 _DMAREQ	=	0x00d7
                           0000D8   563 _TIMIF	=	0x00d8
                           0000D9   564 _RFD	=	0x00d9
                           0000DA   565 _T1CC0L	=	0x00da
                           0000DB   566 _T1CC0H	=	0x00db
                           0000DC   567 _T1CC1L	=	0x00dc
                           0000DD   568 _T1CC1H	=	0x00dd
                           0000DE   569 _T1CC2L	=	0x00de
                           0000DF   570 _T1CC2H	=	0x00df
                           0000E0   571 _ACC	=	0x00e0
                           0000E1   572 _RFST	=	0x00e1
                           0000E2   573 _T1CNTL	=	0x00e2
                           0000E3   574 _T1CNTH	=	0x00e3
                           0000E4   575 _T1CTL	=	0x00e4
                           0000E5   576 _T1CCTL0	=	0x00e5
                           0000E6   577 _T1CCTL1	=	0x00e6
                           0000E7   578 _T1CCTL2	=	0x00e7
                           0000E8   579 _IRCON2	=	0x00e8
                           0000E9   580 _RFIF	=	0x00e9
                           0000EA   581 _T4CNT	=	0x00ea
                           0000EB   582 _T4CTL	=	0x00eb
                           0000EC   583 _T4CCTL0	=	0x00ec
                           0000ED   584 _T4CC0	=	0x00ed
                           0000EE   585 _T4CCTL1	=	0x00ee
                           0000EF   586 _T4CC1	=	0x00ef
                           0000F0   587 _B	=	0x00f0
                           0000F1   588 _PERCFG	=	0x00f1
                           0000F2   589 _ADCCFG	=	0x00f2
                           0000F3   590 _P0SEL	=	0x00f3
                           0000F4   591 _P1SEL	=	0x00f4
                           0000F5   592 _P2SEL	=	0x00f5
                           0000F6   593 _P1INP	=	0x00f6
                           0000F7   594 _P2INP	=	0x00f7
                           0000F8   595 _U1CSR	=	0x00f8
                           0000F9   596 _U1DBUF	=	0x00f9
                           0000FA   597 _U1BAUD	=	0x00fa
                           0000FB   598 _U1UCR	=	0x00fb
                           0000FC   599 _U1GCR	=	0x00fc
                           0000FD   600 _P0DIR	=	0x00fd
                           0000FE   601 _P1DIR	=	0x00fe
                           0000FF   602 _P2DIR	=	0x00ff
                                    603 ;--------------------------------------------------------
                                    604 ; special function bits
                                    605 ;--------------------------------------------------------
                                    606 	.area RSEG    (ABS,DATA)
      000000                        607 	.org 0x0000
                           000080   608 _P0_0	=	0x0080
                           000081   609 _P0_1	=	0x0081
                           000082   610 _P0_2	=	0x0082
                           000083   611 _P0_3	=	0x0083
                           000084   612 _P0_4	=	0x0084
                           000085   613 _P0_5	=	0x0085
                           000086   614 _P0_6	=	0x0086
                           000087   615 _P0_7	=	0x0087
                           000088   616 _IT0	=	0x0088
                           000089   617 _RFTXRXIF	=	0x0089
                           00008A   618 _IT1	=	0x008a
                           00008B   619 _URX0IF	=	0x008b
                           00008D   620 _ADCIF	=	0x008d
                           00008F   621 _URX1IF	=	0x008f
                           000090   622 _P1_0	=	0x0090
                           000091   623 _P1_1	=	0x0091
                           000092   624 _P1_2	=	0x0092
                           000093   625 _P1_3	=	0x0093
                           000094   626 _P1_4	=	0x0094
                           000095   627 _P1_5	=	0x0095
                           000096   628 _P1_6	=	0x0096
                           000097   629 _P1_7	=	0x0097
                           000098   630 _ENCIF_0	=	0x0098
                           000099   631 _ENCIF_1	=	0x0099
                           0000A0   632 _P2_0	=	0x00a0
                           0000A1   633 _P2_1	=	0x00a1
                           0000A2   634 _P2_2	=	0x00a2
                           0000A3   635 _P2_3	=	0x00a3
                           0000A4   636 _P2_4	=	0x00a4
                           0000A5   637 _P2_5	=	0x00a5
                           0000A6   638 _P2_6	=	0x00a6
                           0000A7   639 _P2_7	=	0x00a7
                           0000A8   640 _RFTXRXIE	=	0x00a8
                           0000A9   641 _ADCIE	=	0x00a9
                           0000AA   642 _URX0IE	=	0x00aa
                           0000AB   643 _URX1IE	=	0x00ab
                           0000AC   644 _ENCIE	=	0x00ac
                           0000AD   645 _STIE	=	0x00ad
                           0000AF   646 _EA	=	0x00af
                           0000B8   647 _DMAIE	=	0x00b8
                           0000B9   648 _T1IE	=	0x00b9
                           0000BA   649 _T2IE	=	0x00ba
                           0000BB   650 _T3IE	=	0x00bb
                           0000BC   651 _T4IE	=	0x00bc
                           0000BD   652 _P0IE	=	0x00bd
                           0000C0   653 _DMAIF	=	0x00c0
                           0000C1   654 _T1IF	=	0x00c1
                           0000C2   655 _T2IF	=	0x00c2
                           0000C3   656 _T3IF	=	0x00c3
                           0000C4   657 _T4IF	=	0x00c4
                           0000C5   658 _P0IF	=	0x00c5
                           0000C7   659 _STIF	=	0x00c7
                           0000D0   660 _P	=	0x00d0
                           0000D1   661 _F1	=	0x00d1
                           0000D2   662 _OV	=	0x00d2
                           0000D3   663 _RS0	=	0x00d3
                           0000D4   664 _RS1	=	0x00d4
                           0000D5   665 _F0	=	0x00d5
                           0000D6   666 _AC	=	0x00d6
                           0000D7   667 _CY	=	0x00d7
                           0000D8   668 _T3OVFIF	=	0x00d8
                           0000D9   669 _T3CH0IF	=	0x00d9
                           0000DA   670 _T3CH1IF	=	0x00da
                           0000DB   671 _T4OVFIF	=	0x00db
                           0000DC   672 _T4CH0IF	=	0x00dc
                           0000DD   673 _T4CH1IF	=	0x00dd
                           0000DE   674 _OVFIM	=	0x00de
                           0000E0   675 _ACC_0	=	0x00e0
                           0000E1   676 _ACC_1	=	0x00e1
                           0000E2   677 _ACC_2	=	0x00e2
                           0000E3   678 _ACC_3	=	0x00e3
                           0000E4   679 _ACC_4	=	0x00e4
                           0000E5   680 _ACC_5	=	0x00e5
                           0000E6   681 _ACC_6	=	0x00e6
                           0000E7   682 _ACC_7	=	0x00e7
                           0000E8   683 _P2IF	=	0x00e8
                           0000E9   684 _UTX0IF	=	0x00e9
                           0000EA   685 _UTX1IF	=	0x00ea
                           0000EB   686 _P1IF	=	0x00eb
                           0000EC   687 _WDTIF	=	0x00ec
                           0000F0   688 _B_0	=	0x00f0
                           0000F1   689 _B_1	=	0x00f1
                           0000F2   690 _B_2	=	0x00f2
                           0000F3   691 _B_3	=	0x00f3
                           0000F4   692 _B_4	=	0x00f4
                           0000F5   693 _B_5	=	0x00f5
                           0000F6   694 _B_6	=	0x00f6
                           0000F7   695 _B_7	=	0x00f7
                           0000F8   696 _ACTIVE	=	0x00f8
                           0000F9   697 _TX_BYTE	=	0x00f9
                           0000FA   698 _RX_BYTE	=	0x00fa
                           0000FB   699 _ERR	=	0x00fb
                           0000FC   700 _FE	=	0x00fc
                           0000FD   701 _SLAVE	=	0x00fd
                           0000FE   702 _RE	=	0x00fe
                           0000FF   703 _MODE	=	0x00ff
                           0000E8   704 _USBIF	=	0x00e8
                                    705 ;--------------------------------------------------------
                                    706 ; overlayable register banks
                                    707 ;--------------------------------------------------------
                                    708 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        709 	.ds 8
                                    710 ;--------------------------------------------------------
                                    711 ; internal ram data
                                    712 ;--------------------------------------------------------
                                    713 	.area DSEG    (DATA)
                                    714 ;--------------------------------------------------------
                                    715 ; overlayable items in internal ram 
                                    716 ;--------------------------------------------------------
                                    717 	.area	OSEG    (OVR,DATA)
                                    718 ;--------------------------------------------------------
                                    719 ; indirectly addressable internal ram data
                                    720 ;--------------------------------------------------------
                                    721 	.area ISEG    (DATA)
                                    722 ;--------------------------------------------------------
                                    723 ; absolute internal ram data
                                    724 ;--------------------------------------------------------
                                    725 	.area IABS    (ABS,DATA)
                                    726 	.area IABS    (ABS,DATA)
                                    727 ;--------------------------------------------------------
                                    728 ; bit data
                                    729 ;--------------------------------------------------------
                                    730 	.area BSEG    (BIT)
                                    731 ;--------------------------------------------------------
                                    732 ; paged external ram data
                                    733 ;--------------------------------------------------------
                                    734 	.area PSEG    (PAG,XDATA)
                                    735 ;--------------------------------------------------------
                                    736 ; external ram data
                                    737 ;--------------------------------------------------------
                                    738 	.area XSEG    (XDATA)
                           00DF02   739 _MDMCTRL0H	=	0xdf02
                           00DF00   740 _SYNC1	=	0xdf00
                           00DF01   741 _SYNC0	=	0xdf01
                           00DF02   742 _PKTLEN	=	0xdf02
                           00DF03   743 _PKTCTRL1	=	0xdf03
                           00DF04   744 _PKTCTRL0	=	0xdf04
                           00DF05   745 _ADDR	=	0xdf05
                           00DF06   746 _CHANNR	=	0xdf06
                           00DF07   747 _FSCTRL1	=	0xdf07
                           00DF08   748 _FSCTRL0	=	0xdf08
                           00DF09   749 _FREQ2	=	0xdf09
                           00DF0A   750 _FREQ1	=	0xdf0a
                           00DF0B   751 _FREQ0	=	0xdf0b
                           00DF0C   752 _MDMCFG4	=	0xdf0c
                           00DF0D   753 _MDMCFG3	=	0xdf0d
                           00DF0E   754 _MDMCFG2	=	0xdf0e
                           00DF0F   755 _MDMCFG1	=	0xdf0f
                           00DF10   756 _MDMCFG0	=	0xdf10
                           00DF11   757 _DEVIATN	=	0xdf11
                           00DF12   758 _MCSM2	=	0xdf12
                           00DF13   759 _MCSM1	=	0xdf13
                           00DF14   760 _MCSM0	=	0xdf14
                           00DF15   761 _FOCCFG	=	0xdf15
                           00DF16   762 _BSCFG	=	0xdf16
                           00DF17   763 _AGCCTRL2	=	0xdf17
                           00DF18   764 _AGCCTRL1	=	0xdf18
                           00DF19   765 _AGCCTRL0	=	0xdf19
                           00DF1A   766 _FREND1	=	0xdf1a
                           00DF1B   767 _FREND0	=	0xdf1b
                           00DF1C   768 _FSCAL3	=	0xdf1c
                           00DF1D   769 _FSCAL2	=	0xdf1d
                           00DF1E   770 _FSCAL1	=	0xdf1e
                           00DF1F   771 _FSCAL0	=	0xdf1f
                           00DF20   772 __XREGDF20	=	0xdf20
                           00DF21   773 __XREGDF21	=	0xdf21
                           00DF22   774 __XREGDF22	=	0xdf22
                           00DF23   775 _TEST2	=	0xdf23
                           00DF24   776 _TEST1	=	0xdf24
                           00DF25   777 _TEST0	=	0xdf25
                           00DF26   778 __XREGDF26	=	0xdf26
                           00DF27   779 _PA_TABLE7	=	0xdf27
                           00DF28   780 _PA_TABLE6	=	0xdf28
                           00DF29   781 _PA_TABLE5	=	0xdf29
                           00DF2A   782 _PA_TABLE4	=	0xdf2a
                           00DF2B   783 _PA_TABLE3	=	0xdf2b
                           00DF2C   784 _PA_TABLE2	=	0xdf2c
                           00DF2D   785 _PA_TABLE1	=	0xdf2d
                           00DF2E   786 _PA_TABLE0	=	0xdf2e
                           00DF2F   787 _IOCFG2	=	0xdf2f
                           00DF30   788 _IOCFG1	=	0xdf30
                           00DF31   789 _IOCFG0	=	0xdf31
                           00DF32   790 __XREGDF32	=	0xdf32
                           00DF33   791 __XREGDF33	=	0xdf33
                           00DF34   792 __XREGDF34	=	0xdf34
                           00DF35   793 __XREGDF35	=	0xdf35
                           00DF36   794 _PARTNUM	=	0xdf36
                           00DF37   795 _VERSION	=	0xdf37
                           00DF38   796 _FREQEST	=	0xdf38
                           00DF39   797 _LQI	=	0xdf39
                           00DF3A   798 _RSSI	=	0xdf3a
                           00DF3B   799 _MARCSTATE	=	0xdf3b
                           00DF3C   800 _PKTSTATUS	=	0xdf3c
                           00DF3D   801 _VCO_VC_DAC	=	0xdf3d
                           00DF40   802 _I2SCFG0	=	0xdf40
                           00DF41   803 _I2SCFG1	=	0xdf41
                           00DF42   804 _I2SDATL	=	0xdf42
                           00DF43   805 _I2SDATH	=	0xdf43
                           00DF44   806 _I2SWCNT	=	0xdf44
                           00DF45   807 _I2SSTAT	=	0xdf45
                           00DF46   808 _I2SCLKF0	=	0xdf46
                           00DF47   809 _I2SCLKF1	=	0xdf47
                           00DF48   810 _I2SCLKF2	=	0xdf48
                           00DF80   811 __NA_P0	=	0xdf80
                           00DF81   812 __NA_SP	=	0xdf81
                           00DF82   813 __NA_DPL0	=	0xdf82
                           00DF83   814 __NA_DPH0	=	0xdf83
                           00DF84   815 __NA_DPL1	=	0xdf84
                           00DF85   816 __NA_DPH1	=	0xdf85
                           00DF86   817 _X_U0CSR	=	0xdf86
                           00DF87   818 __NA_PCON	=	0xdf87
                           00DF88   819 __NA_TCON	=	0xdf88
                           00DF89   820 _X_P0IFG	=	0xdf89
                           00DF8A   821 _X_P1IFG	=	0xdf8a
                           00DF8B   822 _X_P2IFG	=	0xdf8b
                           00DF8C   823 _X_PICTL	=	0xdf8c
                           00DF8D   824 _X_P1IEN	=	0xdf8d
                           00DF8E   825 __X_SFR8E	=	0xdf8e
                           00DF8F   826 _X_P0INP	=	0xdf8f
                           00DF90   827 __NA_P1	=	0xdf90
                           00DF91   828 _X_RFIM	=	0xdf91
                           00DF92   829 __NA_DPS	=	0xdf92
                           00DF93   830 _X_MPAGE	=	0xdf93
                           00DF94   831 __X_SFR94	=	0xdf94
                           00DF95   832 __X_SFR95	=	0xdf95
                           00DF96   833 __X_SFR96	=	0xdf96
                           00DF97   834 __X_SFR97	=	0xdf97
                           00DF98   835 __NA_S0CON	=	0xdf98
                           00DF99   836 __X_SFR99	=	0xdf99
                           00DF9A   837 __NA_IEN2	=	0xdf9a
                           00DF9B   838 __NA_S1CON	=	0xdf9b
                           00DF9C   839 _X_T2CT	=	0xdf9c
                           00DF9D   840 _X_T2PR	=	0xdf9d
                           00DF9E   841 _X_T2CTL	=	0xdf9e
                           00DF9F   842 __X_SFR9F	=	0xdf9f
                           00DFA0   843 __NA_P2	=	0xdfa0
                           00DFA1   844 _X_WORIRQ	=	0xdfa1
                           00DFA2   845 _X_WORCTRL	=	0xdfa2
                           00DFA3   846 _X_WOREVT0	=	0xdfa3
                           00DFA4   847 _X_WOREVT1	=	0xdfa4
                           00DFA5   848 _X_WORTIME0	=	0xdfa5
                           00DFA6   849 _X_WORTIME1	=	0xdfa6
                           00DFA7   850 __X_SFRA7	=	0xdfa7
                           00DFA8   851 __NA_IEN0	=	0xdfa8
                           00DFA9   852 __NA_IP0	=	0xdfa9
                           00DFAA   853 __X_SFRAA	=	0xdfaa
                           00DFAB   854 _X_FWT	=	0xdfab
                           00DFAC   855 _X_FADDRL	=	0xdfac
                           00DFAD   856 _X_FADDRH	=	0xdfad
                           00DFAE   857 _X_FCTL	=	0xdfae
                           00DFAF   858 _X_FWDATA	=	0xdfaf
                           00DFB0   859 __X_SFRB0	=	0xdfb0
                           00DFB1   860 _X_ENCDI	=	0xdfb1
                           00DFB2   861 _X_ENCDO	=	0xdfb2
                           00DFB3   862 _X_ENCCS	=	0xdfb3
                           00DFB4   863 _X_ADCCON1	=	0xdfb4
                           00DFB5   864 _X_ADCCON2	=	0xdfb5
                           00DFB6   865 _X_ADCCON3	=	0xdfb6
                           00DFB7   866 __X_SFRB7	=	0xdfb7
                           00DFB8   867 __NA_IEN1	=	0xdfb8
                           00DFB9   868 __NA_IP1	=	0xdfb9
                           00DFBA   869 _X_ADCL	=	0xdfba
                           00DFBB   870 _X_ADCH	=	0xdfbb
                           00DFBC   871 _X_RNDL	=	0xdfbc
                           00DFBD   872 _X_RNDH	=	0xdfbd
                           00DFBE   873 _X_SLEEP	=	0xdfbe
                           00DFBF   874 __X_SFRBF	=	0xdfbf
                           00DFC0   875 __NA_IRCON	=	0xdfc0
                           00DFC1   876 _X_U0DBUF	=	0xdfc1
                           00DFC2   877 _X_U0BAUD	=	0xdfc2
                           00DFC3   878 __X_SFRC3	=	0xdfc3
                           00DFC4   879 _X_U0UCR	=	0xdfc4
                           00DFC5   880 _X_U0GCR	=	0xdfc5
                           00DFC6   881 _X_CLKCON	=	0xdfc6
                           00DFC7   882 _X_MEMCTR	=	0xdfc7
                           00DFC8   883 __X_SFRC8	=	0xdfc8
                           00DFC9   884 _X_WDCTL	=	0xdfc9
                           00DFCA   885 _X_T3CNT	=	0xdfca
                           00DFCB   886 _X_T3CTL	=	0xdfcb
                           00DFCC   887 _X_T3CCTL0	=	0xdfcc
                           00DFCD   888 _X_T3CC0	=	0xdfcd
                           00DFCE   889 _X_T3CCTL1	=	0xdfce
                           00DFCF   890 _X_T3CC1	=	0xdfcf
                           00DFD0   891 __NA_PSW	=	0xdfd0
                           00DFD1   892 _X_DMAIRQ	=	0xdfd1
                           00DFD2   893 _X_DMA1CFGL	=	0xdfd2
                           00DFD3   894 _X_DMA1CFGH	=	0xdfd3
                           00DFD4   895 _X_DMA0CFGL	=	0xdfd4
                           00DFD5   896 _X_DMA0CFGH	=	0xdfd5
                           00DFD6   897 _X_DMAARM	=	0xdfd6
                           00DFD7   898 _X_DMAREQ	=	0xdfd7
                           00DFD8   899 _X_TIMIF	=	0xdfd8
                           00DFD9   900 _X_RFD	=	0xdfd9
                           00DFDA   901 _X_T1CC0L	=	0xdfda
                           00DFDB   902 _X_T1CC0H	=	0xdfdb
                           00DFDC   903 _X_T1CC1L	=	0xdfdc
                           00DFDD   904 _X_T1CC1H	=	0xdfdd
                           00DFDE   905 _X_T1CC2L	=	0xdfde
                           00DFDF   906 _X_T1CC2H	=	0xdfdf
                           00DFE0   907 __NA_ACC	=	0xdfe0
                           00DFE1   908 _X_RFST	=	0xdfe1
                           00DFE2   909 _X_T1CNTL	=	0xdfe2
                           00DFE3   910 _X_T1CNTH	=	0xdfe3
                           00DFE4   911 _X_T1CTL	=	0xdfe4
                           00DFE5   912 _X_T1CCTL0	=	0xdfe5
                           00DFE6   913 _X_T1CCTL1	=	0xdfe6
                           00DFE7   914 _X_T1CCTL2	=	0xdfe7
                           00DFE8   915 __NA_IRCON2	=	0xdfe8
                           00DFE9   916 _X_RFIF	=	0xdfe9
                           00DFEA   917 _X_T4CNT	=	0xdfea
                           00DFEB   918 _X_T4CTL	=	0xdfeb
                           00DFEC   919 _X_T4CCTL0	=	0xdfec
                           00DFED   920 _X_T4CC0	=	0xdfed
                           00DFEE   921 _X_T4CCTL1	=	0xdfee
                           00DFEF   922 _X_T4CC1	=	0xdfef
                           00DFF0   923 __NA_B	=	0xdff0
                           00DFF1   924 _X_PERCFG	=	0xdff1
                           00DFF2   925 _X_ADCCFG	=	0xdff2
                           00DFF3   926 _X_P0SEL	=	0xdff3
                           00DFF4   927 _X_P1SEL	=	0xdff4
                           00DFF5   928 _X_P2SEL	=	0xdff5
                           00DFF6   929 _X_P1INP	=	0xdff6
                           00DFF7   930 _X_P2INP	=	0xdff7
                           00DFF8   931 _X_U1CSR	=	0xdff8
                           00DFF9   932 _X_U1DBUF	=	0xdff9
                           00DFFA   933 _X_U1BAUD	=	0xdffa
                           00DFFB   934 _X_U1UCR	=	0xdffb
                           00DFFC   935 _X_U1GCR	=	0xdffc
                           00DFFD   936 _X_P0DIR	=	0xdffd
                           00DFFE   937 _X_P1DIR	=	0xdffe
                           00DFFF   938 _X_P2DIR	=	0xdfff
                           00DE00   939 _USBADDR	=	0xde00
                           00DE01   940 _USBPOW	=	0xde01
                           00DE02   941 _USBIIF	=	0xde02
                           00DE04   942 _USBOIF	=	0xde04
                           00DE06   943 _USBCIF	=	0xde06
                           00DE07   944 _USBIIE	=	0xde07
                           00DE09   945 _USBOIE	=	0xde09
                           00DE0B   946 _USBCIE	=	0xde0b
                           00DE0C   947 _USBFRML	=	0xde0c
                           00DE0D   948 _USBFRMH	=	0xde0d
                           00DE0E   949 _USBINDEX	=	0xde0e
                           00DE10   950 _USBMAXI	=	0xde10
                           00DE11   951 _USBCS0	=	0xde11
                           00DE11   952 _USBCSIL	=	0xde11
                           00DE12   953 _USBCSIH	=	0xde12
                           00DE13   954 _USBMAXO	=	0xde13
                           00DE14   955 _USBCSOL	=	0xde14
                           00DE15   956 _USBCSOH	=	0xde15
                           00DE16   957 _USBCNT0	=	0xde16
                           00DE16   958 _USBCNTL	=	0xde16
                           00DE17   959 _USBCNTH	=	0xde17
                           00DE20   960 _USBF0	=	0xde20
                           00DE22   961 _USBF1	=	0xde22
                           00DE24   962 _USBF2	=	0xde24
                           00DE26   963 _USBF3	=	0xde26
                           00DE28   964 _USBF4	=	0xde28
                           00DE2A   965 _USBF5	=	0xde2a
                           00DE20   966 _USBFIFO	=	0xde20
                                    967 ;--------------------------------------------------------
                                    968 ; absolute external ram data
                                    969 ;--------------------------------------------------------
                                    970 	.area XABS    (ABS,XDATA)
                                    971 ;--------------------------------------------------------
                                    972 ; external initialized ram data
                                    973 ;--------------------------------------------------------
                                    974 	.area XISEG   (XDATA)
                                    975 	.area HOME    (CODE)
                                    976 	.area GSINIT0 (CODE)
                                    977 	.area GSINIT1 (CODE)
                                    978 	.area GSINIT2 (CODE)
                                    979 	.area GSINIT3 (CODE)
                                    980 	.area GSINIT4 (CODE)
                                    981 	.area GSINIT5 (CODE)
                                    982 	.area GSINIT  (CODE)
                                    983 	.area GSFINAL (CODE)
                                    984 	.area CSEG    (CODE)
                                    985 ;--------------------------------------------------------
                                    986 ; global & static initialisations
                                    987 ;--------------------------------------------------------
                                    988 	.area HOME    (CODE)
                                    989 	.area GSINIT  (CODE)
                                    990 	.area GSFINAL (CODE)
                                    991 	.area GSINIT  (CODE)
                                    992 ;--------------------------------------------------------
                                    993 ; Home
                                    994 ;--------------------------------------------------------
                                    995 	.area HOME    (CODE)
                                    996 	.area HOME    (CODE)
                                    997 ;--------------------------------------------------------
                                    998 ; code
                                    999 ;--------------------------------------------------------
                                   1000 	.area CSEG    (CODE)
                                   1001 ;------------------------------------------------------------
                                   1002 ;Allocation info for local variables in function 'debugEP0Req'
                                   1003 ;------------------------------------------------------------
                                   1004 ;pReq                      Allocated to registers 
                                   1005 ;------------------------------------------------------------
                                   1006 ;	cc1111usbdebug.c:7: void debugEP0Req(u8 *pReq)
                                   1007 ;	-----------------------------------------
                                   1008 ;	 function debugEP0Req
                                   1009 ;	-----------------------------------------
      0025CA                       1010 _debugEP0Req:
                           000007  1011 	ar7 = 0x07
                           000006  1012 	ar6 = 0x06
                           000005  1013 	ar5 = 0x05
                           000004  1014 	ar4 = 0x04
                           000003  1015 	ar3 = 0x03
                           000002  1016 	ar2 = 0x02
                           000001  1017 	ar1 = 0x01
                           000000  1018 	ar0 = 0x00
                                   1019 ;	cc1111usbdebug.c:9: (void) pReq;
      0025CA 22               [24] 1020 	ret
                                   1021 ;------------------------------------------------------------
                                   1022 ;Allocation info for local variables in function 'debug'
                                   1023 ;------------------------------------------------------------
                                   1024 ;text                      Allocated to registers r6 r7 
                                   1025 ;len                       Allocated to registers r4 r5 
                                   1026 ;ptr                       Allocated to registers r2 r3 
                                   1027 ;------------------------------------------------------------
                                   1028 ;	cc1111usbdebug.c:23: void debug(__code u8* text)
                                   1029 ;	-----------------------------------------
                                   1030 ;	 function debug
                                   1031 ;	-----------------------------------------
      0025CB                       1032 _debug:
      0025CB AE 82            [24] 1033 	mov	r6,dpl
      0025CD AF 83            [24] 1034 	mov	r7,dph
                                   1035 ;	cc1111usbdebug.c:27: while (*ptr++ != 0)
      0025CF 7C 00            [12] 1036 	mov	r4,#0x00
      0025D1 7D 00            [12] 1037 	mov	r5,#0x00
      0025D3 8E 02            [24] 1038 	mov	ar2,r6
      0025D5 8F 03            [24] 1039 	mov	ar3,r7
      0025D7                       1040 00101$:
      0025D7 8A 82            [24] 1041 	mov	dpl,r2
      0025D9 8B 83            [24] 1042 	mov	dph,r3
      0025DB E4               [12] 1043 	clr	a
      0025DC 93               [24] 1044 	movc	a,@a+dptr
      0025DD F9               [12] 1045 	mov	r1,a
      0025DE A3               [24] 1046 	inc	dptr
      0025DF AA 82            [24] 1047 	mov	r2,dpl
      0025E1 AB 83            [24] 1048 	mov	r3,dph
      0025E3 E9               [12] 1049 	mov	a,r1
      0025E4 60 07            [24] 1050 	jz	00103$
                                   1051 ;	cc1111usbdebug.c:28: len ++;
      0025E6 0C               [12] 1052 	inc	r4
      0025E7 BC 00 ED         [24] 1053 	cjne	r4,#0x00,00101$
      0025EA 0D               [12] 1054 	inc	r5
      0025EB 80 EA            [24] 1055 	sjmp	00101$
      0025ED                       1056 00103$:
                                   1057 ;	cc1111usbdebug.c:29: txdata(0xfe, 0xf0, len, (__xdata u8*)text);
      0025ED 8E 2F            [24] 1058 	mov	_txdata_PARM_4,r6
      0025EF 8F 30            [24] 1059 	mov	(_txdata_PARM_4 + 1),r7
      0025F1 75 2C F0         [24] 1060 	mov	_txdata_PARM_2,#0xF0
      0025F4 8C 2D            [24] 1061 	mov	_txdata_PARM_3,r4
      0025F6 8D 2E            [24] 1062 	mov	(_txdata_PARM_3 + 1),r5
      0025F8 75 82 FE         [24] 1063 	mov	dpl,#0xFE
      0025FB 02 17 12         [24] 1064 	ljmp	_txdata
                                   1065 	.area CSEG    (CODE)
                                   1066 	.area CONST   (CODE)
                                   1067 	.area XINIT   (CODE)
                                   1068 	.area CABS    (ABS,CODE)
