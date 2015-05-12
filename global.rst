                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.4.0 #8981 (Oct 10 2014) (Mac OS X x86_64)
                                      4 ; This file was generated Tue Apr 21 08:10:37 2015
                                      5 ;--------------------------------------------------------
                                      6 	.module global
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _USBIF
                                     13 	.globl _MODE
                                     14 	.globl _RE
                                     15 	.globl _SLAVE
                                     16 	.globl _FE
                                     17 	.globl _ERR
                                     18 	.globl _RX_BYTE
                                     19 	.globl _TX_BYTE
                                     20 	.globl _ACTIVE
                                     21 	.globl _B_7
                                     22 	.globl _B_6
                                     23 	.globl _B_5
                                     24 	.globl _B_4
                                     25 	.globl _B_3
                                     26 	.globl _B_2
                                     27 	.globl _B_1
                                     28 	.globl _B_0
                                     29 	.globl _WDTIF
                                     30 	.globl _P1IF
                                     31 	.globl _UTX1IF
                                     32 	.globl _UTX0IF
                                     33 	.globl _P2IF
                                     34 	.globl _ACC_7
                                     35 	.globl _ACC_6
                                     36 	.globl _ACC_5
                                     37 	.globl _ACC_4
                                     38 	.globl _ACC_3
                                     39 	.globl _ACC_2
                                     40 	.globl _ACC_1
                                     41 	.globl _ACC_0
                                     42 	.globl _OVFIM
                                     43 	.globl _T4CH1IF
                                     44 	.globl _T4CH0IF
                                     45 	.globl _T4OVFIF
                                     46 	.globl _T3CH1IF
                                     47 	.globl _T3CH0IF
                                     48 	.globl _T3OVFIF
                                     49 	.globl _CY
                                     50 	.globl _AC
                                     51 	.globl _F0
                                     52 	.globl _RS1
                                     53 	.globl _RS0
                                     54 	.globl _OV
                                     55 	.globl _F1
                                     56 	.globl _P
                                     57 	.globl _STIF
                                     58 	.globl _P0IF
                                     59 	.globl _T4IF
                                     60 	.globl _T3IF
                                     61 	.globl _T2IF
                                     62 	.globl _T1IF
                                     63 	.globl _DMAIF
                                     64 	.globl _P0IE
                                     65 	.globl _T4IE
                                     66 	.globl _T3IE
                                     67 	.globl _T2IE
                                     68 	.globl _T1IE
                                     69 	.globl _DMAIE
                                     70 	.globl _EA
                                     71 	.globl _STIE
                                     72 	.globl _ENCIE
                                     73 	.globl _URX1IE
                                     74 	.globl _URX0IE
                                     75 	.globl _ADCIE
                                     76 	.globl _RFTXRXIE
                                     77 	.globl _P2_7
                                     78 	.globl _P2_6
                                     79 	.globl _P2_5
                                     80 	.globl _P2_4
                                     81 	.globl _P2_3
                                     82 	.globl _P2_2
                                     83 	.globl _P2_1
                                     84 	.globl _P2_0
                                     85 	.globl _ENCIF_1
                                     86 	.globl _ENCIF_0
                                     87 	.globl _P1_7
                                     88 	.globl _P1_6
                                     89 	.globl _P1_5
                                     90 	.globl _P1_4
                                     91 	.globl _P1_3
                                     92 	.globl _P1_2
                                     93 	.globl _P1_1
                                     94 	.globl _P1_0
                                     95 	.globl _URX1IF
                                     96 	.globl _ADCIF
                                     97 	.globl _URX0IF
                                     98 	.globl _IT1
                                     99 	.globl _RFTXRXIF
                                    100 	.globl _IT0
                                    101 	.globl _P0_7
                                    102 	.globl _P0_6
                                    103 	.globl _P0_5
                                    104 	.globl _P0_4
                                    105 	.globl _P0_3
                                    106 	.globl _P0_2
                                    107 	.globl _P0_1
                                    108 	.globl _P0_0
                                    109 	.globl _P2DIR
                                    110 	.globl _P1DIR
                                    111 	.globl _P0DIR
                                    112 	.globl _U1GCR
                                    113 	.globl _U1UCR
                                    114 	.globl _U1BAUD
                                    115 	.globl _U1DBUF
                                    116 	.globl _U1CSR
                                    117 	.globl _P2INP
                                    118 	.globl _P1INP
                                    119 	.globl _P2SEL
                                    120 	.globl _P1SEL
                                    121 	.globl _P0SEL
                                    122 	.globl _ADCCFG
                                    123 	.globl _PERCFG
                                    124 	.globl _B
                                    125 	.globl _T4CC1
                                    126 	.globl _T4CCTL1
                                    127 	.globl _T4CC0
                                    128 	.globl _T4CCTL0
                                    129 	.globl _T4CTL
                                    130 	.globl _T4CNT
                                    131 	.globl _RFIF
                                    132 	.globl _IRCON2
                                    133 	.globl _T1CCTL2
                                    134 	.globl _T1CCTL1
                                    135 	.globl _T1CCTL0
                                    136 	.globl _T1CTL
                                    137 	.globl _T1CNTH
                                    138 	.globl _T1CNTL
                                    139 	.globl _RFST
                                    140 	.globl _ACC
                                    141 	.globl _T1CC2H
                                    142 	.globl _T1CC2L
                                    143 	.globl _T1CC1H
                                    144 	.globl _T1CC1L
                                    145 	.globl _T1CC0H
                                    146 	.globl _T1CC0L
                                    147 	.globl _RFD
                                    148 	.globl _TIMIF
                                    149 	.globl _DMAREQ
                                    150 	.globl _DMAARM
                                    151 	.globl _DMA0CFGH
                                    152 	.globl _DMA0CFGL
                                    153 	.globl _DMA1CFGH
                                    154 	.globl _DMA1CFGL
                                    155 	.globl _DMAIRQ
                                    156 	.globl _PSW
                                    157 	.globl _T3CC1
                                    158 	.globl _T3CCTL1
                                    159 	.globl _T3CC0
                                    160 	.globl _T3CCTL0
                                    161 	.globl _T3CTL
                                    162 	.globl _T3CNT
                                    163 	.globl _WDCTL
                                    164 	.globl __SFRC8
                                    165 	.globl _MEMCTR
                                    166 	.globl _CLKCON
                                    167 	.globl _U0GCR
                                    168 	.globl _U0UCR
                                    169 	.globl __SFRC3
                                    170 	.globl _U0BAUD
                                    171 	.globl _U0DBUF
                                    172 	.globl _IRCON
                                    173 	.globl __SFRBF
                                    174 	.globl _SLEEP
                                    175 	.globl _RNDH
                                    176 	.globl _RNDL
                                    177 	.globl _ADCH
                                    178 	.globl _ADCL
                                    179 	.globl _IP1
                                    180 	.globl _IEN1
                                    181 	.globl __SFRB7
                                    182 	.globl _ADCCON3
                                    183 	.globl _ADCCON2
                                    184 	.globl _ADCCON1
                                    185 	.globl _ENCCS
                                    186 	.globl _ENCDO
                                    187 	.globl _ENCDI
                                    188 	.globl __SFRB0
                                    189 	.globl _FWDATA
                                    190 	.globl _FCTL
                                    191 	.globl _FADDRH
                                    192 	.globl _FADDRL
                                    193 	.globl _FWT
                                    194 	.globl __SFRAA
                                    195 	.globl _IP0
                                    196 	.globl _IEN0
                                    197 	.globl __SFRA7
                                    198 	.globl _WORTIME1
                                    199 	.globl _WORTIME0
                                    200 	.globl _WOREVT1
                                    201 	.globl _WOREVT0
                                    202 	.globl _WORCTRL
                                    203 	.globl _WORIRQ
                                    204 	.globl _P2
                                    205 	.globl __SFR9F
                                    206 	.globl _T2CTL
                                    207 	.globl _T2PR
                                    208 	.globl _T2CT
                                    209 	.globl _S1CON
                                    210 	.globl _IEN2
                                    211 	.globl __SFR99
                                    212 	.globl _S0CON
                                    213 	.globl __SFR97
                                    214 	.globl __SFR96
                                    215 	.globl __SFR95
                                    216 	.globl __SFR94
                                    217 	.globl __XPAGE
                                    218 	.globl _MPAGE
                                    219 	.globl _DPS
                                    220 	.globl _RFIM
                                    221 	.globl _P1
                                    222 	.globl _P0INP
                                    223 	.globl __SFR8E
                                    224 	.globl _P1IEN
                                    225 	.globl _PICTL
                                    226 	.globl _P2IFG
                                    227 	.globl _P1IFG
                                    228 	.globl _P0IFG
                                    229 	.globl _TCON
                                    230 	.globl _PCON
                                    231 	.globl _U0CSR
                                    232 	.globl _DPH1
                                    233 	.globl _DPL1
                                    234 	.globl _DPH0
                                    235 	.globl _DPL0
                                    236 	.globl _SP
                                    237 	.globl _P0
                                    238 	.globl _lastCode
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
                                    467 	.globl _blink_binary_baby_lsb_PARM_2
                                    468 	.globl _sleepMillis
                                    469 	.globl _sleepMicros
                                    470 	.globl _blink_binary_baby_lsb
                                    471 ;--------------------------------------------------------
                                    472 ; special function registers
                                    473 ;--------------------------------------------------------
                                    474 	.area RSEG    (ABS,DATA)
      000000                        475 	.org 0x0000
                           000080   476 _P0	=	0x0080
                           000081   477 _SP	=	0x0081
                           000082   478 _DPL0	=	0x0082
                           000083   479 _DPH0	=	0x0083
                           000084   480 _DPL1	=	0x0084
                           000085   481 _DPH1	=	0x0085
                           000086   482 _U0CSR	=	0x0086
                           000087   483 _PCON	=	0x0087
                           000088   484 _TCON	=	0x0088
                           000089   485 _P0IFG	=	0x0089
                           00008A   486 _P1IFG	=	0x008a
                           00008B   487 _P2IFG	=	0x008b
                           00008C   488 _PICTL	=	0x008c
                           00008D   489 _P1IEN	=	0x008d
                           00008E   490 __SFR8E	=	0x008e
                           00008F   491 _P0INP	=	0x008f
                           000090   492 _P1	=	0x0090
                           000091   493 _RFIM	=	0x0091
                           000092   494 _DPS	=	0x0092
                           000093   495 _MPAGE	=	0x0093
                           000093   496 __XPAGE	=	0x0093
                           000094   497 __SFR94	=	0x0094
                           000095   498 __SFR95	=	0x0095
                           000096   499 __SFR96	=	0x0096
                           000097   500 __SFR97	=	0x0097
                           000098   501 _S0CON	=	0x0098
                           000099   502 __SFR99	=	0x0099
                           00009A   503 _IEN2	=	0x009a
                           00009B   504 _S1CON	=	0x009b
                           00009C   505 _T2CT	=	0x009c
                           00009D   506 _T2PR	=	0x009d
                           00009E   507 _T2CTL	=	0x009e
                           00009F   508 __SFR9F	=	0x009f
                           0000A0   509 _P2	=	0x00a0
                           0000A1   510 _WORIRQ	=	0x00a1
                           0000A2   511 _WORCTRL	=	0x00a2
                           0000A3   512 _WOREVT0	=	0x00a3
                           0000A4   513 _WOREVT1	=	0x00a4
                           0000A5   514 _WORTIME0	=	0x00a5
                           0000A6   515 _WORTIME1	=	0x00a6
                           0000A7   516 __SFRA7	=	0x00a7
                           0000A8   517 _IEN0	=	0x00a8
                           0000A9   518 _IP0	=	0x00a9
                           0000AA   519 __SFRAA	=	0x00aa
                           0000AB   520 _FWT	=	0x00ab
                           0000AC   521 _FADDRL	=	0x00ac
                           0000AD   522 _FADDRH	=	0x00ad
                           0000AE   523 _FCTL	=	0x00ae
                           0000AF   524 _FWDATA	=	0x00af
                           0000B0   525 __SFRB0	=	0x00b0
                           0000B1   526 _ENCDI	=	0x00b1
                           0000B2   527 _ENCDO	=	0x00b2
                           0000B3   528 _ENCCS	=	0x00b3
                           0000B4   529 _ADCCON1	=	0x00b4
                           0000B5   530 _ADCCON2	=	0x00b5
                           0000B6   531 _ADCCON3	=	0x00b6
                           0000B7   532 __SFRB7	=	0x00b7
                           0000B8   533 _IEN1	=	0x00b8
                           0000B9   534 _IP1	=	0x00b9
                           0000BA   535 _ADCL	=	0x00ba
                           0000BB   536 _ADCH	=	0x00bb
                           0000BC   537 _RNDL	=	0x00bc
                           0000BD   538 _RNDH	=	0x00bd
                           0000BE   539 _SLEEP	=	0x00be
                           0000BF   540 __SFRBF	=	0x00bf
                           0000C0   541 _IRCON	=	0x00c0
                           0000C1   542 _U0DBUF	=	0x00c1
                           0000C2   543 _U0BAUD	=	0x00c2
                           0000C3   544 __SFRC3	=	0x00c3
                           0000C4   545 _U0UCR	=	0x00c4
                           0000C5   546 _U0GCR	=	0x00c5
                           0000C6   547 _CLKCON	=	0x00c6
                           0000C7   548 _MEMCTR	=	0x00c7
                           0000C8   549 __SFRC8	=	0x00c8
                           0000C9   550 _WDCTL	=	0x00c9
                           0000CA   551 _T3CNT	=	0x00ca
                           0000CB   552 _T3CTL	=	0x00cb
                           0000CC   553 _T3CCTL0	=	0x00cc
                           0000CD   554 _T3CC0	=	0x00cd
                           0000CE   555 _T3CCTL1	=	0x00ce
                           0000CF   556 _T3CC1	=	0x00cf
                           0000D0   557 _PSW	=	0x00d0
                           0000D1   558 _DMAIRQ	=	0x00d1
                           0000D2   559 _DMA1CFGL	=	0x00d2
                           0000D3   560 _DMA1CFGH	=	0x00d3
                           0000D4   561 _DMA0CFGL	=	0x00d4
                           0000D5   562 _DMA0CFGH	=	0x00d5
                           0000D6   563 _DMAARM	=	0x00d6
                           0000D7   564 _DMAREQ	=	0x00d7
                           0000D8   565 _TIMIF	=	0x00d8
                           0000D9   566 _RFD	=	0x00d9
                           0000DA   567 _T1CC0L	=	0x00da
                           0000DB   568 _T1CC0H	=	0x00db
                           0000DC   569 _T1CC1L	=	0x00dc
                           0000DD   570 _T1CC1H	=	0x00dd
                           0000DE   571 _T1CC2L	=	0x00de
                           0000DF   572 _T1CC2H	=	0x00df
                           0000E0   573 _ACC	=	0x00e0
                           0000E1   574 _RFST	=	0x00e1
                           0000E2   575 _T1CNTL	=	0x00e2
                           0000E3   576 _T1CNTH	=	0x00e3
                           0000E4   577 _T1CTL	=	0x00e4
                           0000E5   578 _T1CCTL0	=	0x00e5
                           0000E6   579 _T1CCTL1	=	0x00e6
                           0000E7   580 _T1CCTL2	=	0x00e7
                           0000E8   581 _IRCON2	=	0x00e8
                           0000E9   582 _RFIF	=	0x00e9
                           0000EA   583 _T4CNT	=	0x00ea
                           0000EB   584 _T4CTL	=	0x00eb
                           0000EC   585 _T4CCTL0	=	0x00ec
                           0000ED   586 _T4CC0	=	0x00ed
                           0000EE   587 _T4CCTL1	=	0x00ee
                           0000EF   588 _T4CC1	=	0x00ef
                           0000F0   589 _B	=	0x00f0
                           0000F1   590 _PERCFG	=	0x00f1
                           0000F2   591 _ADCCFG	=	0x00f2
                           0000F3   592 _P0SEL	=	0x00f3
                           0000F4   593 _P1SEL	=	0x00f4
                           0000F5   594 _P2SEL	=	0x00f5
                           0000F6   595 _P1INP	=	0x00f6
                           0000F7   596 _P2INP	=	0x00f7
                           0000F8   597 _U1CSR	=	0x00f8
                           0000F9   598 _U1DBUF	=	0x00f9
                           0000FA   599 _U1BAUD	=	0x00fa
                           0000FB   600 _U1UCR	=	0x00fb
                           0000FC   601 _U1GCR	=	0x00fc
                           0000FD   602 _P0DIR	=	0x00fd
                           0000FE   603 _P1DIR	=	0x00fe
                           0000FF   604 _P2DIR	=	0x00ff
                                    605 ;--------------------------------------------------------
                                    606 ; special function bits
                                    607 ;--------------------------------------------------------
                                    608 	.area RSEG    (ABS,DATA)
      000000                        609 	.org 0x0000
                           000080   610 _P0_0	=	0x0080
                           000081   611 _P0_1	=	0x0081
                           000082   612 _P0_2	=	0x0082
                           000083   613 _P0_3	=	0x0083
                           000084   614 _P0_4	=	0x0084
                           000085   615 _P0_5	=	0x0085
                           000086   616 _P0_6	=	0x0086
                           000087   617 _P0_7	=	0x0087
                           000088   618 _IT0	=	0x0088
                           000089   619 _RFTXRXIF	=	0x0089
                           00008A   620 _IT1	=	0x008a
                           00008B   621 _URX0IF	=	0x008b
                           00008D   622 _ADCIF	=	0x008d
                           00008F   623 _URX1IF	=	0x008f
                           000090   624 _P1_0	=	0x0090
                           000091   625 _P1_1	=	0x0091
                           000092   626 _P1_2	=	0x0092
                           000093   627 _P1_3	=	0x0093
                           000094   628 _P1_4	=	0x0094
                           000095   629 _P1_5	=	0x0095
                           000096   630 _P1_6	=	0x0096
                           000097   631 _P1_7	=	0x0097
                           000098   632 _ENCIF_0	=	0x0098
                           000099   633 _ENCIF_1	=	0x0099
                           0000A0   634 _P2_0	=	0x00a0
                           0000A1   635 _P2_1	=	0x00a1
                           0000A2   636 _P2_2	=	0x00a2
                           0000A3   637 _P2_3	=	0x00a3
                           0000A4   638 _P2_4	=	0x00a4
                           0000A5   639 _P2_5	=	0x00a5
                           0000A6   640 _P2_6	=	0x00a6
                           0000A7   641 _P2_7	=	0x00a7
                           0000A8   642 _RFTXRXIE	=	0x00a8
                           0000A9   643 _ADCIE	=	0x00a9
                           0000AA   644 _URX0IE	=	0x00aa
                           0000AB   645 _URX1IE	=	0x00ab
                           0000AC   646 _ENCIE	=	0x00ac
                           0000AD   647 _STIE	=	0x00ad
                           0000AF   648 _EA	=	0x00af
                           0000B8   649 _DMAIE	=	0x00b8
                           0000B9   650 _T1IE	=	0x00b9
                           0000BA   651 _T2IE	=	0x00ba
                           0000BB   652 _T3IE	=	0x00bb
                           0000BC   653 _T4IE	=	0x00bc
                           0000BD   654 _P0IE	=	0x00bd
                           0000C0   655 _DMAIF	=	0x00c0
                           0000C1   656 _T1IF	=	0x00c1
                           0000C2   657 _T2IF	=	0x00c2
                           0000C3   658 _T3IF	=	0x00c3
                           0000C4   659 _T4IF	=	0x00c4
                           0000C5   660 _P0IF	=	0x00c5
                           0000C7   661 _STIF	=	0x00c7
                           0000D0   662 _P	=	0x00d0
                           0000D1   663 _F1	=	0x00d1
                           0000D2   664 _OV	=	0x00d2
                           0000D3   665 _RS0	=	0x00d3
                           0000D4   666 _RS1	=	0x00d4
                           0000D5   667 _F0	=	0x00d5
                           0000D6   668 _AC	=	0x00d6
                           0000D7   669 _CY	=	0x00d7
                           0000D8   670 _T3OVFIF	=	0x00d8
                           0000D9   671 _T3CH0IF	=	0x00d9
                           0000DA   672 _T3CH1IF	=	0x00da
                           0000DB   673 _T4OVFIF	=	0x00db
                           0000DC   674 _T4CH0IF	=	0x00dc
                           0000DD   675 _T4CH1IF	=	0x00dd
                           0000DE   676 _OVFIM	=	0x00de
                           0000E0   677 _ACC_0	=	0x00e0
                           0000E1   678 _ACC_1	=	0x00e1
                           0000E2   679 _ACC_2	=	0x00e2
                           0000E3   680 _ACC_3	=	0x00e3
                           0000E4   681 _ACC_4	=	0x00e4
                           0000E5   682 _ACC_5	=	0x00e5
                           0000E6   683 _ACC_6	=	0x00e6
                           0000E7   684 _ACC_7	=	0x00e7
                           0000E8   685 _P2IF	=	0x00e8
                           0000E9   686 _UTX0IF	=	0x00e9
                           0000EA   687 _UTX1IF	=	0x00ea
                           0000EB   688 _P1IF	=	0x00eb
                           0000EC   689 _WDTIF	=	0x00ec
                           0000F0   690 _B_0	=	0x00f0
                           0000F1   691 _B_1	=	0x00f1
                           0000F2   692 _B_2	=	0x00f2
                           0000F3   693 _B_3	=	0x00f3
                           0000F4   694 _B_4	=	0x00f4
                           0000F5   695 _B_5	=	0x00f5
                           0000F6   696 _B_6	=	0x00f6
                           0000F7   697 _B_7	=	0x00f7
                           0000F8   698 _ACTIVE	=	0x00f8
                           0000F9   699 _TX_BYTE	=	0x00f9
                           0000FA   700 _RX_BYTE	=	0x00fa
                           0000FB   701 _ERR	=	0x00fb
                           0000FC   702 _FE	=	0x00fc
                           0000FD   703 _SLAVE	=	0x00fd
                           0000FE   704 _RE	=	0x00fe
                           0000FF   705 _MODE	=	0x00ff
                           0000E8   706 _USBIF	=	0x00e8
                                    707 ;--------------------------------------------------------
                                    708 ; overlayable register banks
                                    709 ;--------------------------------------------------------
                                    710 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        711 	.ds 8
                                    712 ;--------------------------------------------------------
                                    713 ; internal ram data
                                    714 ;--------------------------------------------------------
                                    715 	.area DSEG    (DATA)
      00001C                        716 _blink_binary_baby_lsb_PARM_2:
      00001C                        717 	.ds 1
                                    718 ;--------------------------------------------------------
                                    719 ; overlayable items in internal ram 
                                    720 ;--------------------------------------------------------
                                    721 	.area	OSEG    (OVR,DATA)
                                    722 	.area	OSEG    (OVR,DATA)
                                    723 ;--------------------------------------------------------
                                    724 ; indirectly addressable internal ram data
                                    725 ;--------------------------------------------------------
                                    726 	.area ISEG    (DATA)
                                    727 ;--------------------------------------------------------
                                    728 ; absolute internal ram data
                                    729 ;--------------------------------------------------------
                                    730 	.area IABS    (ABS,DATA)
                                    731 	.area IABS    (ABS,DATA)
                                    732 ;--------------------------------------------------------
                                    733 ; bit data
                                    734 ;--------------------------------------------------------
                                    735 	.area BSEG    (BIT)
                                    736 ;--------------------------------------------------------
                                    737 ; paged external ram data
                                    738 ;--------------------------------------------------------
                                    739 	.area PSEG    (PAG,XDATA)
                                    740 ;--------------------------------------------------------
                                    741 ; external ram data
                                    742 ;--------------------------------------------------------
                                    743 	.area XSEG    (XDATA)
                           00DF02   744 _MDMCTRL0H	=	0xdf02
                           00DF00   745 _SYNC1	=	0xdf00
                           00DF01   746 _SYNC0	=	0xdf01
                           00DF02   747 _PKTLEN	=	0xdf02
                           00DF03   748 _PKTCTRL1	=	0xdf03
                           00DF04   749 _PKTCTRL0	=	0xdf04
                           00DF05   750 _ADDR	=	0xdf05
                           00DF06   751 _CHANNR	=	0xdf06
                           00DF07   752 _FSCTRL1	=	0xdf07
                           00DF08   753 _FSCTRL0	=	0xdf08
                           00DF09   754 _FREQ2	=	0xdf09
                           00DF0A   755 _FREQ1	=	0xdf0a
                           00DF0B   756 _FREQ0	=	0xdf0b
                           00DF0C   757 _MDMCFG4	=	0xdf0c
                           00DF0D   758 _MDMCFG3	=	0xdf0d
                           00DF0E   759 _MDMCFG2	=	0xdf0e
                           00DF0F   760 _MDMCFG1	=	0xdf0f
                           00DF10   761 _MDMCFG0	=	0xdf10
                           00DF11   762 _DEVIATN	=	0xdf11
                           00DF12   763 _MCSM2	=	0xdf12
                           00DF13   764 _MCSM1	=	0xdf13
                           00DF14   765 _MCSM0	=	0xdf14
                           00DF15   766 _FOCCFG	=	0xdf15
                           00DF16   767 _BSCFG	=	0xdf16
                           00DF17   768 _AGCCTRL2	=	0xdf17
                           00DF18   769 _AGCCTRL1	=	0xdf18
                           00DF19   770 _AGCCTRL0	=	0xdf19
                           00DF1A   771 _FREND1	=	0xdf1a
                           00DF1B   772 _FREND0	=	0xdf1b
                           00DF1C   773 _FSCAL3	=	0xdf1c
                           00DF1D   774 _FSCAL2	=	0xdf1d
                           00DF1E   775 _FSCAL1	=	0xdf1e
                           00DF1F   776 _FSCAL0	=	0xdf1f
                           00DF20   777 __XREGDF20	=	0xdf20
                           00DF21   778 __XREGDF21	=	0xdf21
                           00DF22   779 __XREGDF22	=	0xdf22
                           00DF23   780 _TEST2	=	0xdf23
                           00DF24   781 _TEST1	=	0xdf24
                           00DF25   782 _TEST0	=	0xdf25
                           00DF26   783 __XREGDF26	=	0xdf26
                           00DF27   784 _PA_TABLE7	=	0xdf27
                           00DF28   785 _PA_TABLE6	=	0xdf28
                           00DF29   786 _PA_TABLE5	=	0xdf29
                           00DF2A   787 _PA_TABLE4	=	0xdf2a
                           00DF2B   788 _PA_TABLE3	=	0xdf2b
                           00DF2C   789 _PA_TABLE2	=	0xdf2c
                           00DF2D   790 _PA_TABLE1	=	0xdf2d
                           00DF2E   791 _PA_TABLE0	=	0xdf2e
                           00DF2F   792 _IOCFG2	=	0xdf2f
                           00DF30   793 _IOCFG1	=	0xdf30
                           00DF31   794 _IOCFG0	=	0xdf31
                           00DF32   795 __XREGDF32	=	0xdf32
                           00DF33   796 __XREGDF33	=	0xdf33
                           00DF34   797 __XREGDF34	=	0xdf34
                           00DF35   798 __XREGDF35	=	0xdf35
                           00DF36   799 _PARTNUM	=	0xdf36
                           00DF37   800 _VERSION	=	0xdf37
                           00DF38   801 _FREQEST	=	0xdf38
                           00DF39   802 _LQI	=	0xdf39
                           00DF3A   803 _RSSI	=	0xdf3a
                           00DF3B   804 _MARCSTATE	=	0xdf3b
                           00DF3C   805 _PKTSTATUS	=	0xdf3c
                           00DF3D   806 _VCO_VC_DAC	=	0xdf3d
                           00DF40   807 _I2SCFG0	=	0xdf40
                           00DF41   808 _I2SCFG1	=	0xdf41
                           00DF42   809 _I2SDATL	=	0xdf42
                           00DF43   810 _I2SDATH	=	0xdf43
                           00DF44   811 _I2SWCNT	=	0xdf44
                           00DF45   812 _I2SSTAT	=	0xdf45
                           00DF46   813 _I2SCLKF0	=	0xdf46
                           00DF47   814 _I2SCLKF1	=	0xdf47
                           00DF48   815 _I2SCLKF2	=	0xdf48
                           00DF80   816 __NA_P0	=	0xdf80
                           00DF81   817 __NA_SP	=	0xdf81
                           00DF82   818 __NA_DPL0	=	0xdf82
                           00DF83   819 __NA_DPH0	=	0xdf83
                           00DF84   820 __NA_DPL1	=	0xdf84
                           00DF85   821 __NA_DPH1	=	0xdf85
                           00DF86   822 _X_U0CSR	=	0xdf86
                           00DF87   823 __NA_PCON	=	0xdf87
                           00DF88   824 __NA_TCON	=	0xdf88
                           00DF89   825 _X_P0IFG	=	0xdf89
                           00DF8A   826 _X_P1IFG	=	0xdf8a
                           00DF8B   827 _X_P2IFG	=	0xdf8b
                           00DF8C   828 _X_PICTL	=	0xdf8c
                           00DF8D   829 _X_P1IEN	=	0xdf8d
                           00DF8E   830 __X_SFR8E	=	0xdf8e
                           00DF8F   831 _X_P0INP	=	0xdf8f
                           00DF90   832 __NA_P1	=	0xdf90
                           00DF91   833 _X_RFIM	=	0xdf91
                           00DF92   834 __NA_DPS	=	0xdf92
                           00DF93   835 _X_MPAGE	=	0xdf93
                           00DF94   836 __X_SFR94	=	0xdf94
                           00DF95   837 __X_SFR95	=	0xdf95
                           00DF96   838 __X_SFR96	=	0xdf96
                           00DF97   839 __X_SFR97	=	0xdf97
                           00DF98   840 __NA_S0CON	=	0xdf98
                           00DF99   841 __X_SFR99	=	0xdf99
                           00DF9A   842 __NA_IEN2	=	0xdf9a
                           00DF9B   843 __NA_S1CON	=	0xdf9b
                           00DF9C   844 _X_T2CT	=	0xdf9c
                           00DF9D   845 _X_T2PR	=	0xdf9d
                           00DF9E   846 _X_T2CTL	=	0xdf9e
                           00DF9F   847 __X_SFR9F	=	0xdf9f
                           00DFA0   848 __NA_P2	=	0xdfa0
                           00DFA1   849 _X_WORIRQ	=	0xdfa1
                           00DFA2   850 _X_WORCTRL	=	0xdfa2
                           00DFA3   851 _X_WOREVT0	=	0xdfa3
                           00DFA4   852 _X_WOREVT1	=	0xdfa4
                           00DFA5   853 _X_WORTIME0	=	0xdfa5
                           00DFA6   854 _X_WORTIME1	=	0xdfa6
                           00DFA7   855 __X_SFRA7	=	0xdfa7
                           00DFA8   856 __NA_IEN0	=	0xdfa8
                           00DFA9   857 __NA_IP0	=	0xdfa9
                           00DFAA   858 __X_SFRAA	=	0xdfaa
                           00DFAB   859 _X_FWT	=	0xdfab
                           00DFAC   860 _X_FADDRL	=	0xdfac
                           00DFAD   861 _X_FADDRH	=	0xdfad
                           00DFAE   862 _X_FCTL	=	0xdfae
                           00DFAF   863 _X_FWDATA	=	0xdfaf
                           00DFB0   864 __X_SFRB0	=	0xdfb0
                           00DFB1   865 _X_ENCDI	=	0xdfb1
                           00DFB2   866 _X_ENCDO	=	0xdfb2
                           00DFB3   867 _X_ENCCS	=	0xdfb3
                           00DFB4   868 _X_ADCCON1	=	0xdfb4
                           00DFB5   869 _X_ADCCON2	=	0xdfb5
                           00DFB6   870 _X_ADCCON3	=	0xdfb6
                           00DFB7   871 __X_SFRB7	=	0xdfb7
                           00DFB8   872 __NA_IEN1	=	0xdfb8
                           00DFB9   873 __NA_IP1	=	0xdfb9
                           00DFBA   874 _X_ADCL	=	0xdfba
                           00DFBB   875 _X_ADCH	=	0xdfbb
                           00DFBC   876 _X_RNDL	=	0xdfbc
                           00DFBD   877 _X_RNDH	=	0xdfbd
                           00DFBE   878 _X_SLEEP	=	0xdfbe
                           00DFBF   879 __X_SFRBF	=	0xdfbf
                           00DFC0   880 __NA_IRCON	=	0xdfc0
                           00DFC1   881 _X_U0DBUF	=	0xdfc1
                           00DFC2   882 _X_U0BAUD	=	0xdfc2
                           00DFC3   883 __X_SFRC3	=	0xdfc3
                           00DFC4   884 _X_U0UCR	=	0xdfc4
                           00DFC5   885 _X_U0GCR	=	0xdfc5
                           00DFC6   886 _X_CLKCON	=	0xdfc6
                           00DFC7   887 _X_MEMCTR	=	0xdfc7
                           00DFC8   888 __X_SFRC8	=	0xdfc8
                           00DFC9   889 _X_WDCTL	=	0xdfc9
                           00DFCA   890 _X_T3CNT	=	0xdfca
                           00DFCB   891 _X_T3CTL	=	0xdfcb
                           00DFCC   892 _X_T3CCTL0	=	0xdfcc
                           00DFCD   893 _X_T3CC0	=	0xdfcd
                           00DFCE   894 _X_T3CCTL1	=	0xdfce
                           00DFCF   895 _X_T3CC1	=	0xdfcf
                           00DFD0   896 __NA_PSW	=	0xdfd0
                           00DFD1   897 _X_DMAIRQ	=	0xdfd1
                           00DFD2   898 _X_DMA1CFGL	=	0xdfd2
                           00DFD3   899 _X_DMA1CFGH	=	0xdfd3
                           00DFD4   900 _X_DMA0CFGL	=	0xdfd4
                           00DFD5   901 _X_DMA0CFGH	=	0xdfd5
                           00DFD6   902 _X_DMAARM	=	0xdfd6
                           00DFD7   903 _X_DMAREQ	=	0xdfd7
                           00DFD8   904 _X_TIMIF	=	0xdfd8
                           00DFD9   905 _X_RFD	=	0xdfd9
                           00DFDA   906 _X_T1CC0L	=	0xdfda
                           00DFDB   907 _X_T1CC0H	=	0xdfdb
                           00DFDC   908 _X_T1CC1L	=	0xdfdc
                           00DFDD   909 _X_T1CC1H	=	0xdfdd
                           00DFDE   910 _X_T1CC2L	=	0xdfde
                           00DFDF   911 _X_T1CC2H	=	0xdfdf
                           00DFE0   912 __NA_ACC	=	0xdfe0
                           00DFE1   913 _X_RFST	=	0xdfe1
                           00DFE2   914 _X_T1CNTL	=	0xdfe2
                           00DFE3   915 _X_T1CNTH	=	0xdfe3
                           00DFE4   916 _X_T1CTL	=	0xdfe4
                           00DFE5   917 _X_T1CCTL0	=	0xdfe5
                           00DFE6   918 _X_T1CCTL1	=	0xdfe6
                           00DFE7   919 _X_T1CCTL2	=	0xdfe7
                           00DFE8   920 __NA_IRCON2	=	0xdfe8
                           00DFE9   921 _X_RFIF	=	0xdfe9
                           00DFEA   922 _X_T4CNT	=	0xdfea
                           00DFEB   923 _X_T4CTL	=	0xdfeb
                           00DFEC   924 _X_T4CCTL0	=	0xdfec
                           00DFED   925 _X_T4CC0	=	0xdfed
                           00DFEE   926 _X_T4CCTL1	=	0xdfee
                           00DFEF   927 _X_T4CC1	=	0xdfef
                           00DFF0   928 __NA_B	=	0xdff0
                           00DFF1   929 _X_PERCFG	=	0xdff1
                           00DFF2   930 _X_ADCCFG	=	0xdff2
                           00DFF3   931 _X_P0SEL	=	0xdff3
                           00DFF4   932 _X_P1SEL	=	0xdff4
                           00DFF5   933 _X_P2SEL	=	0xdff5
                           00DFF6   934 _X_P1INP	=	0xdff6
                           00DFF7   935 _X_P2INP	=	0xdff7
                           00DFF8   936 _X_U1CSR	=	0xdff8
                           00DFF9   937 _X_U1DBUF	=	0xdff9
                           00DFFA   938 _X_U1BAUD	=	0xdffa
                           00DFFB   939 _X_U1UCR	=	0xdffb
                           00DFFC   940 _X_U1GCR	=	0xdffc
                           00DFFD   941 _X_P0DIR	=	0xdffd
                           00DFFE   942 _X_P1DIR	=	0xdffe
                           00DFFF   943 _X_P2DIR	=	0xdfff
                           00DE00   944 _USBADDR	=	0xde00
                           00DE01   945 _USBPOW	=	0xde01
                           00DE02   946 _USBIIF	=	0xde02
                           00DE04   947 _USBOIF	=	0xde04
                           00DE06   948 _USBCIF	=	0xde06
                           00DE07   949 _USBIIE	=	0xde07
                           00DE09   950 _USBOIE	=	0xde09
                           00DE0B   951 _USBCIE	=	0xde0b
                           00DE0C   952 _USBFRML	=	0xde0c
                           00DE0D   953 _USBFRMH	=	0xde0d
                           00DE0E   954 _USBINDEX	=	0xde0e
                           00DE10   955 _USBMAXI	=	0xde10
                           00DE11   956 _USBCS0	=	0xde11
                           00DE11   957 _USBCSIL	=	0xde11
                           00DE12   958 _USBCSIH	=	0xde12
                           00DE13   959 _USBMAXO	=	0xde13
                           00DE14   960 _USBCSOL	=	0xde14
                           00DE15   961 _USBCSOH	=	0xde15
                           00DE16   962 _USBCNT0	=	0xde16
                           00DE16   963 _USBCNTL	=	0xde16
                           00DE17   964 _USBCNTH	=	0xde17
                           00DE20   965 _USBF0	=	0xde20
                           00DE22   966 _USBF1	=	0xde22
                           00DE24   967 _USBF2	=	0xde24
                           00DE26   968 _USBF3	=	0xde26
                           00DE28   969 _USBF4	=	0xde28
                           00DE2A   970 _USBF5	=	0xde2a
                           00DE20   971 _USBFIFO	=	0xde20
      00F71F                        972 _lastCode::
      00F71F                        973 	.ds 2
                                    974 ;--------------------------------------------------------
                                    975 ; absolute external ram data
                                    976 ;--------------------------------------------------------
                                    977 	.area XABS    (ABS,XDATA)
                                    978 ;--------------------------------------------------------
                                    979 ; external initialized ram data
                                    980 ;--------------------------------------------------------
                                    981 	.area XISEG   (XDATA)
                                    982 	.area HOME    (CODE)
                                    983 	.area GSINIT0 (CODE)
                                    984 	.area GSINIT1 (CODE)
                                    985 	.area GSINIT2 (CODE)
                                    986 	.area GSINIT3 (CODE)
                                    987 	.area GSINIT4 (CODE)
                                    988 	.area GSINIT5 (CODE)
                                    989 	.area GSINIT  (CODE)
                                    990 	.area GSFINAL (CODE)
                                    991 	.area CSEG    (CODE)
                                    992 ;--------------------------------------------------------
                                    993 ; global & static initialisations
                                    994 ;--------------------------------------------------------
                                    995 	.area HOME    (CODE)
                                    996 	.area GSINIT  (CODE)
                                    997 	.area GSFINAL (CODE)
                                    998 	.area GSINIT  (CODE)
                                    999 ;--------------------------------------------------------
                                   1000 ; Home
                                   1001 ;--------------------------------------------------------
                                   1002 	.area HOME    (CODE)
                                   1003 	.area HOME    (CODE)
                                   1004 ;--------------------------------------------------------
                                   1005 ; code
                                   1006 ;--------------------------------------------------------
                                   1007 	.area CSEG    (CODE)
                                   1008 ;------------------------------------------------------------
                                   1009 ;Allocation info for local variables in function 'sleepMillis'
                                   1010 ;------------------------------------------------------------
                                   1011 ;ms                        Allocated to registers 
                                   1012 ;j                         Allocated to registers r4 r5 
                                   1013 ;------------------------------------------------------------
                                   1014 ;	global.c:7: void sleepMillis(int ms) 
                                   1015 ;	-----------------------------------------
                                   1016 ;	 function sleepMillis
                                   1017 ;	-----------------------------------------
      001518                       1018 _sleepMillis:
                           000007  1019 	ar7 = 0x07
                           000006  1020 	ar6 = 0x06
                           000005  1021 	ar5 = 0x05
                           000004  1022 	ar4 = 0x04
                           000003  1023 	ar3 = 0x03
                           000002  1024 	ar2 = 0x02
                           000001  1025 	ar1 = 0x01
                           000000  1026 	ar0 = 0x00
      001518 AE 82            [24] 1027 	mov	r6,dpl
      00151A AF 83            [24] 1028 	mov	r7,dph
                                   1029 ;	global.c:10: while (--ms > 0) 
      00151C                       1030 00102$:
      00151C 1E               [12] 1031 	dec	r6
      00151D BE FF 01         [24] 1032 	cjne	r6,#0xFF,00124$
      001520 1F               [12] 1033 	dec	r7
      001521                       1034 00124$:
      001521 C3               [12] 1035 	clr	c
      001522 E4               [12] 1036 	clr	a
      001523 9E               [12] 1037 	subb	a,r6
      001524 74 80            [12] 1038 	mov	a,#(0x00 ^ 0x80)
      001526 8F F0            [24] 1039 	mov	b,r7
      001528 63 F0 80         [24] 1040 	xrl	b,#0x80
      00152B 95 F0            [12] 1041 	subb	a,b
      00152D 50 0F            [24] 1042 	jnc	00108$
                                   1043 ;	global.c:12: for (j=0; j<SLEEPTIMER;j++); // about 1 millisecond
      00152F 7C B0            [12] 1044 	mov	r4,#0xB0
      001531 7D 04            [12] 1045 	mov	r5,#0x04
      001533                       1046 00107$:
      001533 1C               [12] 1047 	dec	r4
      001534 BC FF 01         [24] 1048 	cjne	r4,#0xFF,00126$
      001537 1D               [12] 1049 	dec	r5
      001538                       1050 00126$:
      001538 EC               [12] 1051 	mov	a,r4
      001539 4D               [12] 1052 	orl	a,r5
      00153A 70 F7            [24] 1053 	jnz	00107$
      00153C 80 DE            [24] 1054 	sjmp	00102$
      00153E                       1055 00108$:
      00153E 22               [24] 1056 	ret
                                   1057 ;------------------------------------------------------------
                                   1058 ;Allocation info for local variables in function 'sleepMicros'
                                   1059 ;------------------------------------------------------------
                                   1060 ;us                        Allocated to registers 
                                   1061 ;------------------------------------------------------------
                                   1062 ;	global.c:17: void sleepMicros(int us) 
                                   1063 ;	-----------------------------------------
                                   1064 ;	 function sleepMicros
                                   1065 ;	-----------------------------------------
      00153F                       1066 _sleepMicros:
      00153F AE 82            [24] 1067 	mov	r6,dpl
      001541 AF 83            [24] 1068 	mov	r7,dph
                                   1069 ;	global.c:19: while (--us > 0) ;
      001543                       1070 00101$:
      001543 1E               [12] 1071 	dec	r6
      001544 BE FF 01         [24] 1072 	cjne	r6,#0xFF,00110$
      001547 1F               [12] 1073 	dec	r7
      001548                       1074 00110$:
      001548 C3               [12] 1075 	clr	c
      001549 E4               [12] 1076 	clr	a
      00154A 9E               [12] 1077 	subb	a,r6
      00154B 74 80            [12] 1078 	mov	a,#(0x00 ^ 0x80)
      00154D 8F F0            [24] 1079 	mov	b,r7
      00154F 63 F0 80         [24] 1080 	xrl	b,#0x80
      001552 95 F0            [12] 1081 	subb	a,b
      001554 40 ED            [24] 1082 	jc	00101$
      001556 22               [24] 1083 	ret
                                   1084 ;------------------------------------------------------------
                                   1085 ;Allocation info for local variables in function 'blink_binary_baby_lsb'
                                   1086 ;------------------------------------------------------------
                                   1087 ;bits                      Allocated with name '_blink_binary_baby_lsb_PARM_2'
                                   1088 ;num                       Allocated to registers r6 r7 
                                   1089 ;------------------------------------------------------------
                                   1090 ;	global.c:32: void blink_binary_baby_lsb(u16 num, char bits)
                                   1091 ;	-----------------------------------------
                                   1092 ;	 function blink_binary_baby_lsb
                                   1093 ;	-----------------------------------------
      001557                       1094 _blink_binary_baby_lsb:
      001557 AE 82            [24] 1095 	mov	r6,dpl
      001559 AF 83            [24] 1096 	mov	r7,dph
                                   1097 ;	global.c:34: EA=0;
      00155B C2 AF            [12] 1098 	clr	_EA
                                   1099 ;	global.c:35: LED = 1;
      00155D D2 90            [12] 1100 	setb	_P1_0
                                   1101 ;	global.c:36: sleepMillis(1000);
      00155F 90 03 E8         [24] 1102 	mov	dptr,#0x03E8
      001562 C0 07            [24] 1103 	push	ar7
      001564 C0 06            [24] 1104 	push	ar6
      001566 12 15 18         [24] 1105 	lcall	_sleepMillis
                                   1106 ;	global.c:37: LED = 0;
      001569 C2 90            [12] 1107 	clr	_P1_0
                                   1108 ;	global.c:38: sleepMillis(500);
      00156B 90 01 F4         [24] 1109 	mov	dptr,#0x01F4
      00156E 12 15 18         [24] 1110 	lcall	_sleepMillis
      001571 D0 06            [24] 1111 	pop	ar6
      001573 D0 07            [24] 1112 	pop	ar7
                                   1113 ;	global.c:39: bits -= 1;          // 16 bit numbers needs to start on bit 15, etc....
      001575 15 1C            [12] 1114 	dec	_blink_binary_baby_lsb_PARM_2
      001577 AD 1C            [24] 1115 	mov	r5,_blink_binary_baby_lsb_PARM_2
      001579                       1116 00106$:
                                   1117 ;	global.c:41: for (; bits>=0; bits--)
      001579 ED               [12] 1118 	mov	a,r5
      00157A 20 E7 54         [24] 1119 	jb	acc.7,00104$
                                   1120 ;	global.c:43: if (num & 1)
      00157D EE               [12] 1121 	mov	a,r6
      00157E 30 E0 24         [24] 1122 	jnb	acc.0,00102$
                                   1123 ;	global.c:45: sleepMillis(25);
      001581 90 00 19         [24] 1124 	mov	dptr,#0x0019
      001584 C0 07            [24] 1125 	push	ar7
      001586 C0 06            [24] 1126 	push	ar6
      001588 C0 05            [24] 1127 	push	ar5
      00158A 12 15 18         [24] 1128 	lcall	_sleepMillis
                                   1129 ;	global.c:46: LED = 1;
      00158D D2 90            [12] 1130 	setb	_P1_0
                                   1131 ;	global.c:47: sleepMillis(550);
      00158F 90 02 26         [24] 1132 	mov	dptr,#0x0226
      001592 12 15 18         [24] 1133 	lcall	_sleepMillis
                                   1134 ;	global.c:48: LED = 0;
      001595 C2 90            [12] 1135 	clr	_P1_0
                                   1136 ;	global.c:49: sleepMillis(25);
      001597 90 00 19         [24] 1137 	mov	dptr,#0x0019
      00159A 12 15 18         [24] 1138 	lcall	_sleepMillis
      00159D D0 05            [24] 1139 	pop	ar5
      00159F D0 06            [24] 1140 	pop	ar6
      0015A1 D0 07            [24] 1141 	pop	ar7
      0015A3 80 22            [24] 1142 	sjmp	00103$
      0015A5                       1143 00102$:
                                   1144 ;	global.c:53: sleepMillis(275);
      0015A5 90 01 13         [24] 1145 	mov	dptr,#0x0113
      0015A8 C0 07            [24] 1146 	push	ar7
      0015AA C0 06            [24] 1147 	push	ar6
      0015AC C0 05            [24] 1148 	push	ar5
      0015AE 12 15 18         [24] 1149 	lcall	_sleepMillis
                                   1150 ;	global.c:54: LED = 1;
      0015B1 D2 90            [12] 1151 	setb	_P1_0
                                   1152 ;	global.c:55: sleepMillis(50);
      0015B3 90 00 32         [24] 1153 	mov	dptr,#0x0032
      0015B6 12 15 18         [24] 1154 	lcall	_sleepMillis
                                   1155 ;	global.c:56: LED = 0;
      0015B9 C2 90            [12] 1156 	clr	_P1_0
                                   1157 ;	global.c:57: sleepMillis(275);
      0015BB 90 01 13         [24] 1158 	mov	dptr,#0x0113
      0015BE 12 15 18         [24] 1159 	lcall	_sleepMillis
      0015C1 D0 05            [24] 1160 	pop	ar5
      0015C3 D0 06            [24] 1161 	pop	ar6
      0015C5 D0 07            [24] 1162 	pop	ar7
      0015C7                       1163 00103$:
                                   1164 ;	global.c:59: num = num >> 1;
      0015C7 EF               [12] 1165 	mov	a,r7
      0015C8 C3               [12] 1166 	clr	c
      0015C9 13               [12] 1167 	rrc	a
      0015CA CE               [12] 1168 	xch	a,r6
      0015CB 13               [12] 1169 	rrc	a
      0015CC CE               [12] 1170 	xch	a,r6
      0015CD FF               [12] 1171 	mov	r7,a
                                   1172 ;	global.c:41: for (; bits>=0; bits--)
      0015CE 1D               [12] 1173 	dec	r5
      0015CF 80 A8            [24] 1174 	sjmp	00106$
      0015D1                       1175 00104$:
                                   1176 ;	global.c:61: LED = 0;
      0015D1 C2 90            [12] 1177 	clr	_P1_0
                                   1178 ;	global.c:62: sleepMillis(1000);
      0015D3 90 03 E8         [24] 1179 	mov	dptr,#0x03E8
      0015D6 12 15 18         [24] 1180 	lcall	_sleepMillis
                                   1181 ;	global.c:63: EA=1;
      0015D9 D2 AF            [12] 1182 	setb	_EA
      0015DB 22               [24] 1183 	ret
                                   1184 	.area CSEG    (CODE)
                                   1185 	.area CONST   (CODE)
                                   1186 	.area XINIT   (CODE)
                                   1187 	.area CABS    (ABS,CODE)
