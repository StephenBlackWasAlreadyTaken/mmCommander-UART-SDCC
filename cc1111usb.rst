                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ANSI-C Compiler
                                      3 ; Version 3.4.0 #8981 (Oct 10 2014) (Mac OS X x86_64)
                                      4 ; This file was generated Tue Apr 21 08:10:37 2015
                                      5 ;--------------------------------------------------------
                                      6 	.module cc1111usb
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 	
                                      9 ;--------------------------------------------------------
                                     10 ; Public variables in this module
                                     11 ;--------------------------------------------------------
                                     12 	.globl _usbGetDescriptorPrimitive_PARM_2
                                     13 	.globl _handleOUTEP5
                                     14 	.globl _handleCS0
                                     15 	.globl _usbGetDescriptor
                                     16 	.globl _usbGetDescriptorPrimitive
                                     17 	.globl _usbSetConfiguration
                                     18 	.globl _usbGetConfiguration
                                     19 	.globl _setup_recv_ep0
                                     20 	.globl _usb_arm_ep0IN
                                     21 	.globl _usb_init
                                     22 	.globl _transmit
                                     23 	.globl _RxOn
                                     24 	.globl _setRFIdle
                                     25 	.globl _appHandleEP5
                                     26 	.globl _appHandleEP0
                                     27 	.globl _appHandleEP0OUTdone
                                     28 	.globl _blink_binary_baby_lsb
                                     29 	.globl _sleepMillis
                                     30 	.globl _debugEP0Req
                                     31 	.globl _USBIF
                                     32 	.globl _MODE
                                     33 	.globl _RE
                                     34 	.globl _SLAVE
                                     35 	.globl _FE
                                     36 	.globl _ERR
                                     37 	.globl _RX_BYTE
                                     38 	.globl _TX_BYTE
                                     39 	.globl _ACTIVE
                                     40 	.globl _B_7
                                     41 	.globl _B_6
                                     42 	.globl _B_5
                                     43 	.globl _B_4
                                     44 	.globl _B_3
                                     45 	.globl _B_2
                                     46 	.globl _B_1
                                     47 	.globl _B_0
                                     48 	.globl _WDTIF
                                     49 	.globl _P1IF
                                     50 	.globl _UTX1IF
                                     51 	.globl _UTX0IF
                                     52 	.globl _P2IF
                                     53 	.globl _ACC_7
                                     54 	.globl _ACC_6
                                     55 	.globl _ACC_5
                                     56 	.globl _ACC_4
                                     57 	.globl _ACC_3
                                     58 	.globl _ACC_2
                                     59 	.globl _ACC_1
                                     60 	.globl _ACC_0
                                     61 	.globl _OVFIM
                                     62 	.globl _T4CH1IF
                                     63 	.globl _T4CH0IF
                                     64 	.globl _T4OVFIF
                                     65 	.globl _T3CH1IF
                                     66 	.globl _T3CH0IF
                                     67 	.globl _T3OVFIF
                                     68 	.globl _CY
                                     69 	.globl _AC
                                     70 	.globl _F0
                                     71 	.globl _RS1
                                     72 	.globl _RS0
                                     73 	.globl _OV
                                     74 	.globl _F1
                                     75 	.globl _P
                                     76 	.globl _STIF
                                     77 	.globl _P0IF
                                     78 	.globl _T4IF
                                     79 	.globl _T3IF
                                     80 	.globl _T2IF
                                     81 	.globl _T1IF
                                     82 	.globl _DMAIF
                                     83 	.globl _P0IE
                                     84 	.globl _T4IE
                                     85 	.globl _T3IE
                                     86 	.globl _T2IE
                                     87 	.globl _T1IE
                                     88 	.globl _DMAIE
                                     89 	.globl _EA
                                     90 	.globl _STIE
                                     91 	.globl _ENCIE
                                     92 	.globl _URX1IE
                                     93 	.globl _URX0IE
                                     94 	.globl _ADCIE
                                     95 	.globl _RFTXRXIE
                                     96 	.globl _P2_7
                                     97 	.globl _P2_6
                                     98 	.globl _P2_5
                                     99 	.globl _P2_4
                                    100 	.globl _P2_3
                                    101 	.globl _P2_2
                                    102 	.globl _P2_1
                                    103 	.globl _P2_0
                                    104 	.globl _ENCIF_1
                                    105 	.globl _ENCIF_0
                                    106 	.globl _P1_7
                                    107 	.globl _P1_6
                                    108 	.globl _P1_5
                                    109 	.globl _P1_4
                                    110 	.globl _P1_3
                                    111 	.globl _P1_2
                                    112 	.globl _P1_1
                                    113 	.globl _P1_0
                                    114 	.globl _URX1IF
                                    115 	.globl _ADCIF
                                    116 	.globl _URX0IF
                                    117 	.globl _IT1
                                    118 	.globl _RFTXRXIF
                                    119 	.globl _IT0
                                    120 	.globl _P0_7
                                    121 	.globl _P0_6
                                    122 	.globl _P0_5
                                    123 	.globl _P0_4
                                    124 	.globl _P0_3
                                    125 	.globl _P0_2
                                    126 	.globl _P0_1
                                    127 	.globl _P0_0
                                    128 	.globl _P2DIR
                                    129 	.globl _P1DIR
                                    130 	.globl _P0DIR
                                    131 	.globl _U1GCR
                                    132 	.globl _U1UCR
                                    133 	.globl _U1BAUD
                                    134 	.globl _U1DBUF
                                    135 	.globl _U1CSR
                                    136 	.globl _P2INP
                                    137 	.globl _P1INP
                                    138 	.globl _P2SEL
                                    139 	.globl _P1SEL
                                    140 	.globl _P0SEL
                                    141 	.globl _ADCCFG
                                    142 	.globl _PERCFG
                                    143 	.globl _B
                                    144 	.globl _T4CC1
                                    145 	.globl _T4CCTL1
                                    146 	.globl _T4CC0
                                    147 	.globl _T4CCTL0
                                    148 	.globl _T4CTL
                                    149 	.globl _T4CNT
                                    150 	.globl _RFIF
                                    151 	.globl _IRCON2
                                    152 	.globl _T1CCTL2
                                    153 	.globl _T1CCTL1
                                    154 	.globl _T1CCTL0
                                    155 	.globl _T1CTL
                                    156 	.globl _T1CNTH
                                    157 	.globl _T1CNTL
                                    158 	.globl _RFST
                                    159 	.globl _ACC
                                    160 	.globl _T1CC2H
                                    161 	.globl _T1CC2L
                                    162 	.globl _T1CC1H
                                    163 	.globl _T1CC1L
                                    164 	.globl _T1CC0H
                                    165 	.globl _T1CC0L
                                    166 	.globl _RFD
                                    167 	.globl _TIMIF
                                    168 	.globl _DMAREQ
                                    169 	.globl _DMAARM
                                    170 	.globl _DMA0CFGH
                                    171 	.globl _DMA0CFGL
                                    172 	.globl _DMA1CFGH
                                    173 	.globl _DMA1CFGL
                                    174 	.globl _DMAIRQ
                                    175 	.globl _PSW
                                    176 	.globl _T3CC1
                                    177 	.globl _T3CCTL1
                                    178 	.globl _T3CC0
                                    179 	.globl _T3CCTL0
                                    180 	.globl _T3CTL
                                    181 	.globl _T3CNT
                                    182 	.globl _WDCTL
                                    183 	.globl __SFRC8
                                    184 	.globl _MEMCTR
                                    185 	.globl _CLKCON
                                    186 	.globl _U0GCR
                                    187 	.globl _U0UCR
                                    188 	.globl __SFRC3
                                    189 	.globl _U0BAUD
                                    190 	.globl _U0DBUF
                                    191 	.globl _IRCON
                                    192 	.globl __SFRBF
                                    193 	.globl _SLEEP
                                    194 	.globl _RNDH
                                    195 	.globl _RNDL
                                    196 	.globl _ADCH
                                    197 	.globl _ADCL
                                    198 	.globl _IP1
                                    199 	.globl _IEN1
                                    200 	.globl __SFRB7
                                    201 	.globl _ADCCON3
                                    202 	.globl _ADCCON2
                                    203 	.globl _ADCCON1
                                    204 	.globl _ENCCS
                                    205 	.globl _ENCDO
                                    206 	.globl _ENCDI
                                    207 	.globl __SFRB0
                                    208 	.globl _FWDATA
                                    209 	.globl _FCTL
                                    210 	.globl _FADDRH
                                    211 	.globl _FADDRL
                                    212 	.globl _FWT
                                    213 	.globl __SFRAA
                                    214 	.globl _IP0
                                    215 	.globl _IEN0
                                    216 	.globl __SFRA7
                                    217 	.globl _WORTIME1
                                    218 	.globl _WORTIME0
                                    219 	.globl _WOREVT1
                                    220 	.globl _WOREVT0
                                    221 	.globl _WORCTRL
                                    222 	.globl _WORIRQ
                                    223 	.globl _P2
                                    224 	.globl __SFR9F
                                    225 	.globl _T2CTL
                                    226 	.globl _T2PR
                                    227 	.globl _T2CT
                                    228 	.globl _S1CON
                                    229 	.globl _IEN2
                                    230 	.globl __SFR99
                                    231 	.globl _S0CON
                                    232 	.globl __SFR97
                                    233 	.globl __SFR96
                                    234 	.globl __SFR95
                                    235 	.globl __SFR94
                                    236 	.globl __XPAGE
                                    237 	.globl _MPAGE
                                    238 	.globl _DPS
                                    239 	.globl _RFIM
                                    240 	.globl _P1
                                    241 	.globl _P0INP
                                    242 	.globl __SFR8E
                                    243 	.globl _P1IEN
                                    244 	.globl _PICTL
                                    245 	.globl _P2IFG
                                    246 	.globl _P1IFG
                                    247 	.globl _P0IFG
                                    248 	.globl _TCON
                                    249 	.globl _PCON
                                    250 	.globl _U0CSR
                                    251 	.globl _DPH1
                                    252 	.globl _DPL1
                                    253 	.globl _DPH0
                                    254 	.globl _DPL0
                                    255 	.globl _SP
                                    256 	.globl _P0
                                    257 	.globl _usbdma
                                    258 	.globl _appstatus
                                    259 	.globl _ep5iobuf
                                    260 	.globl _ep0iobuf
                                    261 	.globl _usb_ep5_OUTbuf
                                    262 	.globl _usb_ep0_OUTbuf
                                    263 	.globl _USBFIFO
                                    264 	.globl _USBF5
                                    265 	.globl _USBF4
                                    266 	.globl _USBF3
                                    267 	.globl _USBF2
                                    268 	.globl _USBF1
                                    269 	.globl _USBF0
                                    270 	.globl _USBCNTH
                                    271 	.globl _USBCNTL
                                    272 	.globl _USBCNT0
                                    273 	.globl _USBCSOH
                                    274 	.globl _USBCSOL
                                    275 	.globl _USBMAXO
                                    276 	.globl _USBCSIH
                                    277 	.globl _USBCSIL
                                    278 	.globl _USBCS0
                                    279 	.globl _USBMAXI
                                    280 	.globl _USBINDEX
                                    281 	.globl _USBFRMH
                                    282 	.globl _USBFRML
                                    283 	.globl _USBCIE
                                    284 	.globl _USBOIE
                                    285 	.globl _USBIIE
                                    286 	.globl _USBCIF
                                    287 	.globl _USBOIF
                                    288 	.globl _USBIIF
                                    289 	.globl _USBPOW
                                    290 	.globl _USBADDR
                                    291 	.globl _X_P2DIR
                                    292 	.globl _X_P1DIR
                                    293 	.globl _X_P0DIR
                                    294 	.globl _X_U1GCR
                                    295 	.globl _X_U1UCR
                                    296 	.globl _X_U1BAUD
                                    297 	.globl _X_U1DBUF
                                    298 	.globl _X_U1CSR
                                    299 	.globl _X_P2INP
                                    300 	.globl _X_P1INP
                                    301 	.globl _X_P2SEL
                                    302 	.globl _X_P1SEL
                                    303 	.globl _X_P0SEL
                                    304 	.globl _X_ADCCFG
                                    305 	.globl _X_PERCFG
                                    306 	.globl __NA_B
                                    307 	.globl _X_T4CC1
                                    308 	.globl _X_T4CCTL1
                                    309 	.globl _X_T4CC0
                                    310 	.globl _X_T4CCTL0
                                    311 	.globl _X_T4CTL
                                    312 	.globl _X_T4CNT
                                    313 	.globl _X_RFIF
                                    314 	.globl __NA_IRCON2
                                    315 	.globl _X_T1CCTL2
                                    316 	.globl _X_T1CCTL1
                                    317 	.globl _X_T1CCTL0
                                    318 	.globl _X_T1CTL
                                    319 	.globl _X_T1CNTH
                                    320 	.globl _X_T1CNTL
                                    321 	.globl _X_RFST
                                    322 	.globl __NA_ACC
                                    323 	.globl _X_T1CC2H
                                    324 	.globl _X_T1CC2L
                                    325 	.globl _X_T1CC1H
                                    326 	.globl _X_T1CC1L
                                    327 	.globl _X_T1CC0H
                                    328 	.globl _X_T1CC0L
                                    329 	.globl _X_RFD
                                    330 	.globl _X_TIMIF
                                    331 	.globl _X_DMAREQ
                                    332 	.globl _X_DMAARM
                                    333 	.globl _X_DMA0CFGH
                                    334 	.globl _X_DMA0CFGL
                                    335 	.globl _X_DMA1CFGH
                                    336 	.globl _X_DMA1CFGL
                                    337 	.globl _X_DMAIRQ
                                    338 	.globl __NA_PSW
                                    339 	.globl _X_T3CC1
                                    340 	.globl _X_T3CCTL1
                                    341 	.globl _X_T3CC0
                                    342 	.globl _X_T3CCTL0
                                    343 	.globl _X_T3CTL
                                    344 	.globl _X_T3CNT
                                    345 	.globl _X_WDCTL
                                    346 	.globl __X_SFRC8
                                    347 	.globl _X_MEMCTR
                                    348 	.globl _X_CLKCON
                                    349 	.globl _X_U0GCR
                                    350 	.globl _X_U0UCR
                                    351 	.globl __X_SFRC3
                                    352 	.globl _X_U0BAUD
                                    353 	.globl _X_U0DBUF
                                    354 	.globl __NA_IRCON
                                    355 	.globl __X_SFRBF
                                    356 	.globl _X_SLEEP
                                    357 	.globl _X_RNDH
                                    358 	.globl _X_RNDL
                                    359 	.globl _X_ADCH
                                    360 	.globl _X_ADCL
                                    361 	.globl __NA_IP1
                                    362 	.globl __NA_IEN1
                                    363 	.globl __X_SFRB7
                                    364 	.globl _X_ADCCON3
                                    365 	.globl _X_ADCCON2
                                    366 	.globl _X_ADCCON1
                                    367 	.globl _X_ENCCS
                                    368 	.globl _X_ENCDO
                                    369 	.globl _X_ENCDI
                                    370 	.globl __X_SFRB0
                                    371 	.globl _X_FWDATA
                                    372 	.globl _X_FCTL
                                    373 	.globl _X_FADDRH
                                    374 	.globl _X_FADDRL
                                    375 	.globl _X_FWT
                                    376 	.globl __X_SFRAA
                                    377 	.globl __NA_IP0
                                    378 	.globl __NA_IEN0
                                    379 	.globl __X_SFRA7
                                    380 	.globl _X_WORTIME1
                                    381 	.globl _X_WORTIME0
                                    382 	.globl _X_WOREVT1
                                    383 	.globl _X_WOREVT0
                                    384 	.globl _X_WORCTRL
                                    385 	.globl _X_WORIRQ
                                    386 	.globl __NA_P2
                                    387 	.globl __X_SFR9F
                                    388 	.globl _X_T2CTL
                                    389 	.globl _X_T2PR
                                    390 	.globl _X_T2CT
                                    391 	.globl __NA_S1CON
                                    392 	.globl __NA_IEN2
                                    393 	.globl __X_SFR99
                                    394 	.globl __NA_S0CON
                                    395 	.globl __X_SFR97
                                    396 	.globl __X_SFR96
                                    397 	.globl __X_SFR95
                                    398 	.globl __X_SFR94
                                    399 	.globl _X_MPAGE
                                    400 	.globl __NA_DPS
                                    401 	.globl _X_RFIM
                                    402 	.globl __NA_P1
                                    403 	.globl _X_P0INP
                                    404 	.globl __X_SFR8E
                                    405 	.globl _X_P1IEN
                                    406 	.globl _X_PICTL
                                    407 	.globl _X_P2IFG
                                    408 	.globl _X_P1IFG
                                    409 	.globl _X_P0IFG
                                    410 	.globl __NA_TCON
                                    411 	.globl __NA_PCON
                                    412 	.globl _X_U0CSR
                                    413 	.globl __NA_DPH1
                                    414 	.globl __NA_DPL1
                                    415 	.globl __NA_DPH0
                                    416 	.globl __NA_DPL0
                                    417 	.globl __NA_SP
                                    418 	.globl __NA_P0
                                    419 	.globl _I2SCLKF2
                                    420 	.globl _I2SCLKF1
                                    421 	.globl _I2SCLKF0
                                    422 	.globl _I2SSTAT
                                    423 	.globl _I2SWCNT
                                    424 	.globl _I2SDATH
                                    425 	.globl _I2SDATL
                                    426 	.globl _I2SCFG1
                                    427 	.globl _I2SCFG0
                                    428 	.globl _VCO_VC_DAC
                                    429 	.globl _PKTSTATUS
                                    430 	.globl _MARCSTATE
                                    431 	.globl _RSSI
                                    432 	.globl _LQI
                                    433 	.globl _FREQEST
                                    434 	.globl _VERSION
                                    435 	.globl _PARTNUM
                                    436 	.globl __XREGDF35
                                    437 	.globl __XREGDF34
                                    438 	.globl __XREGDF33
                                    439 	.globl __XREGDF32
                                    440 	.globl _IOCFG0
                                    441 	.globl _IOCFG1
                                    442 	.globl _IOCFG2
                                    443 	.globl _PA_TABLE0
                                    444 	.globl _PA_TABLE1
                                    445 	.globl _PA_TABLE2
                                    446 	.globl _PA_TABLE3
                                    447 	.globl _PA_TABLE4
                                    448 	.globl _PA_TABLE5
                                    449 	.globl _PA_TABLE6
                                    450 	.globl _PA_TABLE7
                                    451 	.globl __XREGDF26
                                    452 	.globl _TEST0
                                    453 	.globl _TEST1
                                    454 	.globl _TEST2
                                    455 	.globl __XREGDF22
                                    456 	.globl __XREGDF21
                                    457 	.globl __XREGDF20
                                    458 	.globl _FSCAL0
                                    459 	.globl _FSCAL1
                                    460 	.globl _FSCAL2
                                    461 	.globl _FSCAL3
                                    462 	.globl _FREND0
                                    463 	.globl _FREND1
                                    464 	.globl _AGCCTRL0
                                    465 	.globl _AGCCTRL1
                                    466 	.globl _AGCCTRL2
                                    467 	.globl _BSCFG
                                    468 	.globl _FOCCFG
                                    469 	.globl _MCSM0
                                    470 	.globl _MCSM1
                                    471 	.globl _MCSM2
                                    472 	.globl _DEVIATN
                                    473 	.globl _MDMCFG0
                                    474 	.globl _MDMCFG1
                                    475 	.globl _MDMCFG2
                                    476 	.globl _MDMCFG3
                                    477 	.globl _MDMCFG4
                                    478 	.globl _FREQ0
                                    479 	.globl _FREQ1
                                    480 	.globl _FREQ2
                                    481 	.globl _FSCTRL0
                                    482 	.globl _FSCTRL1
                                    483 	.globl _CHANNR
                                    484 	.globl _ADDR
                                    485 	.globl _PKTCTRL0
                                    486 	.globl _PKTCTRL1
                                    487 	.globl _PKTLEN
                                    488 	.globl _SYNC0
                                    489 	.globl _SYNC1
                                    490 	.globl _MDMCTRL0H
                                    491 	.globl _setup_sendx_ep0_PARM_2
                                    492 	.globl _setup_send_ep0_PARM_2
                                    493 	.globl _txdata_PARM_4
                                    494 	.globl _txdata_PARM_3
                                    495 	.globl _txdata_PARM_2
                                    496 	.globl _txdataold_PARM_4
                                    497 	.globl _txdataold_PARM_3
                                    498 	.globl _txdataold_PARM_2
                                    499 	.globl _usb_data
                                    500 	.globl _txdataold
                                    501 	.globl _txdata
                                    502 	.globl _waitForUSBsetup
                                    503 	.globl _initUSB
                                    504 	.globl _usb_up
                                    505 	.globl _usb_down
                                    506 	.globl _setup_send_ep0
                                    507 	.globl _setup_sendx_ep0
                                    508 	.globl _usb_recv_ep0OUT
                                    509 	.globl _usbProcessEvents
                                    510 	.globl _usbIntHandler
                                    511 	.globl _p0IntHandler
                                    512 	.globl _USBDESCBEGIN
                                    513 ;--------------------------------------------------------
                                    514 ; special function registers
                                    515 ;--------------------------------------------------------
                                    516 	.area RSEG    (ABS,DATA)
      000000                        517 	.org 0x0000
                           000080   518 _P0	=	0x0080
                           000081   519 _SP	=	0x0081
                           000082   520 _DPL0	=	0x0082
                           000083   521 _DPH0	=	0x0083
                           000084   522 _DPL1	=	0x0084
                           000085   523 _DPH1	=	0x0085
                           000086   524 _U0CSR	=	0x0086
                           000087   525 _PCON	=	0x0087
                           000088   526 _TCON	=	0x0088
                           000089   527 _P0IFG	=	0x0089
                           00008A   528 _P1IFG	=	0x008a
                           00008B   529 _P2IFG	=	0x008b
                           00008C   530 _PICTL	=	0x008c
                           00008D   531 _P1IEN	=	0x008d
                           00008E   532 __SFR8E	=	0x008e
                           00008F   533 _P0INP	=	0x008f
                           000090   534 _P1	=	0x0090
                           000091   535 _RFIM	=	0x0091
                           000092   536 _DPS	=	0x0092
                           000093   537 _MPAGE	=	0x0093
                           000093   538 __XPAGE	=	0x0093
                           000094   539 __SFR94	=	0x0094
                           000095   540 __SFR95	=	0x0095
                           000096   541 __SFR96	=	0x0096
                           000097   542 __SFR97	=	0x0097
                           000098   543 _S0CON	=	0x0098
                           000099   544 __SFR99	=	0x0099
                           00009A   545 _IEN2	=	0x009a
                           00009B   546 _S1CON	=	0x009b
                           00009C   547 _T2CT	=	0x009c
                           00009D   548 _T2PR	=	0x009d
                           00009E   549 _T2CTL	=	0x009e
                           00009F   550 __SFR9F	=	0x009f
                           0000A0   551 _P2	=	0x00a0
                           0000A1   552 _WORIRQ	=	0x00a1
                           0000A2   553 _WORCTRL	=	0x00a2
                           0000A3   554 _WOREVT0	=	0x00a3
                           0000A4   555 _WOREVT1	=	0x00a4
                           0000A5   556 _WORTIME0	=	0x00a5
                           0000A6   557 _WORTIME1	=	0x00a6
                           0000A7   558 __SFRA7	=	0x00a7
                           0000A8   559 _IEN0	=	0x00a8
                           0000A9   560 _IP0	=	0x00a9
                           0000AA   561 __SFRAA	=	0x00aa
                           0000AB   562 _FWT	=	0x00ab
                           0000AC   563 _FADDRL	=	0x00ac
                           0000AD   564 _FADDRH	=	0x00ad
                           0000AE   565 _FCTL	=	0x00ae
                           0000AF   566 _FWDATA	=	0x00af
                           0000B0   567 __SFRB0	=	0x00b0
                           0000B1   568 _ENCDI	=	0x00b1
                           0000B2   569 _ENCDO	=	0x00b2
                           0000B3   570 _ENCCS	=	0x00b3
                           0000B4   571 _ADCCON1	=	0x00b4
                           0000B5   572 _ADCCON2	=	0x00b5
                           0000B6   573 _ADCCON3	=	0x00b6
                           0000B7   574 __SFRB7	=	0x00b7
                           0000B8   575 _IEN1	=	0x00b8
                           0000B9   576 _IP1	=	0x00b9
                           0000BA   577 _ADCL	=	0x00ba
                           0000BB   578 _ADCH	=	0x00bb
                           0000BC   579 _RNDL	=	0x00bc
                           0000BD   580 _RNDH	=	0x00bd
                           0000BE   581 _SLEEP	=	0x00be
                           0000BF   582 __SFRBF	=	0x00bf
                           0000C0   583 _IRCON	=	0x00c0
                           0000C1   584 _U0DBUF	=	0x00c1
                           0000C2   585 _U0BAUD	=	0x00c2
                           0000C3   586 __SFRC3	=	0x00c3
                           0000C4   587 _U0UCR	=	0x00c4
                           0000C5   588 _U0GCR	=	0x00c5
                           0000C6   589 _CLKCON	=	0x00c6
                           0000C7   590 _MEMCTR	=	0x00c7
                           0000C8   591 __SFRC8	=	0x00c8
                           0000C9   592 _WDCTL	=	0x00c9
                           0000CA   593 _T3CNT	=	0x00ca
                           0000CB   594 _T3CTL	=	0x00cb
                           0000CC   595 _T3CCTL0	=	0x00cc
                           0000CD   596 _T3CC0	=	0x00cd
                           0000CE   597 _T3CCTL1	=	0x00ce
                           0000CF   598 _T3CC1	=	0x00cf
                           0000D0   599 _PSW	=	0x00d0
                           0000D1   600 _DMAIRQ	=	0x00d1
                           0000D2   601 _DMA1CFGL	=	0x00d2
                           0000D3   602 _DMA1CFGH	=	0x00d3
                           0000D4   603 _DMA0CFGL	=	0x00d4
                           0000D5   604 _DMA0CFGH	=	0x00d5
                           0000D6   605 _DMAARM	=	0x00d6
                           0000D7   606 _DMAREQ	=	0x00d7
                           0000D8   607 _TIMIF	=	0x00d8
                           0000D9   608 _RFD	=	0x00d9
                           0000DA   609 _T1CC0L	=	0x00da
                           0000DB   610 _T1CC0H	=	0x00db
                           0000DC   611 _T1CC1L	=	0x00dc
                           0000DD   612 _T1CC1H	=	0x00dd
                           0000DE   613 _T1CC2L	=	0x00de
                           0000DF   614 _T1CC2H	=	0x00df
                           0000E0   615 _ACC	=	0x00e0
                           0000E1   616 _RFST	=	0x00e1
                           0000E2   617 _T1CNTL	=	0x00e2
                           0000E3   618 _T1CNTH	=	0x00e3
                           0000E4   619 _T1CTL	=	0x00e4
                           0000E5   620 _T1CCTL0	=	0x00e5
                           0000E6   621 _T1CCTL1	=	0x00e6
                           0000E7   622 _T1CCTL2	=	0x00e7
                           0000E8   623 _IRCON2	=	0x00e8
                           0000E9   624 _RFIF	=	0x00e9
                           0000EA   625 _T4CNT	=	0x00ea
                           0000EB   626 _T4CTL	=	0x00eb
                           0000EC   627 _T4CCTL0	=	0x00ec
                           0000ED   628 _T4CC0	=	0x00ed
                           0000EE   629 _T4CCTL1	=	0x00ee
                           0000EF   630 _T4CC1	=	0x00ef
                           0000F0   631 _B	=	0x00f0
                           0000F1   632 _PERCFG	=	0x00f1
                           0000F2   633 _ADCCFG	=	0x00f2
                           0000F3   634 _P0SEL	=	0x00f3
                           0000F4   635 _P1SEL	=	0x00f4
                           0000F5   636 _P2SEL	=	0x00f5
                           0000F6   637 _P1INP	=	0x00f6
                           0000F7   638 _P2INP	=	0x00f7
                           0000F8   639 _U1CSR	=	0x00f8
                           0000F9   640 _U1DBUF	=	0x00f9
                           0000FA   641 _U1BAUD	=	0x00fa
                           0000FB   642 _U1UCR	=	0x00fb
                           0000FC   643 _U1GCR	=	0x00fc
                           0000FD   644 _P0DIR	=	0x00fd
                           0000FE   645 _P1DIR	=	0x00fe
                           0000FF   646 _P2DIR	=	0x00ff
                                    647 ;--------------------------------------------------------
                                    648 ; special function bits
                                    649 ;--------------------------------------------------------
                                    650 	.area RSEG    (ABS,DATA)
      000000                        651 	.org 0x0000
                           000080   652 _P0_0	=	0x0080
                           000081   653 _P0_1	=	0x0081
                           000082   654 _P0_2	=	0x0082
                           000083   655 _P0_3	=	0x0083
                           000084   656 _P0_4	=	0x0084
                           000085   657 _P0_5	=	0x0085
                           000086   658 _P0_6	=	0x0086
                           000087   659 _P0_7	=	0x0087
                           000088   660 _IT0	=	0x0088
                           000089   661 _RFTXRXIF	=	0x0089
                           00008A   662 _IT1	=	0x008a
                           00008B   663 _URX0IF	=	0x008b
                           00008D   664 _ADCIF	=	0x008d
                           00008F   665 _URX1IF	=	0x008f
                           000090   666 _P1_0	=	0x0090
                           000091   667 _P1_1	=	0x0091
                           000092   668 _P1_2	=	0x0092
                           000093   669 _P1_3	=	0x0093
                           000094   670 _P1_4	=	0x0094
                           000095   671 _P1_5	=	0x0095
                           000096   672 _P1_6	=	0x0096
                           000097   673 _P1_7	=	0x0097
                           000098   674 _ENCIF_0	=	0x0098
                           000099   675 _ENCIF_1	=	0x0099
                           0000A0   676 _P2_0	=	0x00a0
                           0000A1   677 _P2_1	=	0x00a1
                           0000A2   678 _P2_2	=	0x00a2
                           0000A3   679 _P2_3	=	0x00a3
                           0000A4   680 _P2_4	=	0x00a4
                           0000A5   681 _P2_5	=	0x00a5
                           0000A6   682 _P2_6	=	0x00a6
                           0000A7   683 _P2_7	=	0x00a7
                           0000A8   684 _RFTXRXIE	=	0x00a8
                           0000A9   685 _ADCIE	=	0x00a9
                           0000AA   686 _URX0IE	=	0x00aa
                           0000AB   687 _URX1IE	=	0x00ab
                           0000AC   688 _ENCIE	=	0x00ac
                           0000AD   689 _STIE	=	0x00ad
                           0000AF   690 _EA	=	0x00af
                           0000B8   691 _DMAIE	=	0x00b8
                           0000B9   692 _T1IE	=	0x00b9
                           0000BA   693 _T2IE	=	0x00ba
                           0000BB   694 _T3IE	=	0x00bb
                           0000BC   695 _T4IE	=	0x00bc
                           0000BD   696 _P0IE	=	0x00bd
                           0000C0   697 _DMAIF	=	0x00c0
                           0000C1   698 _T1IF	=	0x00c1
                           0000C2   699 _T2IF	=	0x00c2
                           0000C3   700 _T3IF	=	0x00c3
                           0000C4   701 _T4IF	=	0x00c4
                           0000C5   702 _P0IF	=	0x00c5
                           0000C7   703 _STIF	=	0x00c7
                           0000D0   704 _P	=	0x00d0
                           0000D1   705 _F1	=	0x00d1
                           0000D2   706 _OV	=	0x00d2
                           0000D3   707 _RS0	=	0x00d3
                           0000D4   708 _RS1	=	0x00d4
                           0000D5   709 _F0	=	0x00d5
                           0000D6   710 _AC	=	0x00d6
                           0000D7   711 _CY	=	0x00d7
                           0000D8   712 _T3OVFIF	=	0x00d8
                           0000D9   713 _T3CH0IF	=	0x00d9
                           0000DA   714 _T3CH1IF	=	0x00da
                           0000DB   715 _T4OVFIF	=	0x00db
                           0000DC   716 _T4CH0IF	=	0x00dc
                           0000DD   717 _T4CH1IF	=	0x00dd
                           0000DE   718 _OVFIM	=	0x00de
                           0000E0   719 _ACC_0	=	0x00e0
                           0000E1   720 _ACC_1	=	0x00e1
                           0000E2   721 _ACC_2	=	0x00e2
                           0000E3   722 _ACC_3	=	0x00e3
                           0000E4   723 _ACC_4	=	0x00e4
                           0000E5   724 _ACC_5	=	0x00e5
                           0000E6   725 _ACC_6	=	0x00e6
                           0000E7   726 _ACC_7	=	0x00e7
                           0000E8   727 _P2IF	=	0x00e8
                           0000E9   728 _UTX0IF	=	0x00e9
                           0000EA   729 _UTX1IF	=	0x00ea
                           0000EB   730 _P1IF	=	0x00eb
                           0000EC   731 _WDTIF	=	0x00ec
                           0000F0   732 _B_0	=	0x00f0
                           0000F1   733 _B_1	=	0x00f1
                           0000F2   734 _B_2	=	0x00f2
                           0000F3   735 _B_3	=	0x00f3
                           0000F4   736 _B_4	=	0x00f4
                           0000F5   737 _B_5	=	0x00f5
                           0000F6   738 _B_6	=	0x00f6
                           0000F7   739 _B_7	=	0x00f7
                           0000F8   740 _ACTIVE	=	0x00f8
                           0000F9   741 _TX_BYTE	=	0x00f9
                           0000FA   742 _RX_BYTE	=	0x00fa
                           0000FB   743 _ERR	=	0x00fb
                           0000FC   744 _FE	=	0x00fc
                           0000FD   745 _SLAVE	=	0x00fd
                           0000FE   746 _RE	=	0x00fe
                           0000FF   747 _MODE	=	0x00ff
                           0000E8   748 _USBIF	=	0x00e8
                                    749 ;--------------------------------------------------------
                                    750 ; overlayable register banks
                                    751 ;--------------------------------------------------------
                                    752 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        753 	.ds 8
                                    754 ;--------------------------------------------------------
                                    755 ; internal ram data
                                    756 ;--------------------------------------------------------
                                    757 	.area DSEG    (DATA)
      000022                        758 _usb_data::
      000022                        759 	.ds 4
      000026                        760 _txdataold_PARM_2:
      000026                        761 	.ds 1
      000027                        762 _txdataold_PARM_3:
      000027                        763 	.ds 2
      000029                        764 _txdataold_PARM_4:
      000029                        765 	.ds 3
      00002C                        766 _txdata_PARM_2:
      00002C                        767 	.ds 1
      00002D                        768 _txdata_PARM_3:
      00002D                        769 	.ds 2
      00002F                        770 _txdata_PARM_4:
      00002F                        771 	.ds 2
      000031                        772 _setup_send_ep0_PARM_2:
      000031                        773 	.ds 2
      000033                        774 _setup_sendx_ep0_PARM_2:
      000033                        775 	.ds 2
      000035                        776 _usbGetDescriptor_pReq_1_89:
      000035                        777 	.ds 3
      000038                        778 _usbGetDescriptor_buffer_1_90:
      000038                        779 	.ds 3
      00003B                        780 _usbGetDescriptor_length_1_90:
      00003B                        781 	.ds 2
      00003D                        782 _usbGetDescriptor_sloc0_1_0:
      00003D                        783 	.ds 2
      00003F                        784 _usbGetDescriptor_sloc1_1_0:
      00003F                        785 	.ds 3
      000042                        786 _handleCS0_req_1_95:
      000042                        787 	.ds 8
      00004A                        788 _handleCS0_val_1_95:
      00004A                        789 	.ds 2
      00004C                        790 _handleOUTEP5_loop_1_125:
      00004C                        791 	.ds 2
      00004E                        792 _handleOUTEP5_len_1_125:
      00004E                        793 	.ds 2
      000050                        794 _handleOUTEP5_cmd_1_125:
      000050                        795 	.ds 1
      000051                        796 _handleOUTEP5_app_1_125:
      000051                        797 	.ds 1
      000052                        798 _handleOUTEP5_dptr_1_125:
      000052                        799 	.ds 2
      000054                        800 _handleOUTEP5_sloc0_1_0:
      000054                        801 	.ds 3
                                    802 ;--------------------------------------------------------
                                    803 ; overlayable items in internal ram 
                                    804 ;--------------------------------------------------------
                                    805 	.area	OSEG    (OVR,DATA)
                                    806 	.area	OSEG    (OVR,DATA)
                                    807 	.area	OSEG    (OVR,DATA)
      00000E                        808 _usbGetDescriptorPrimitive_PARM_2:
      00000E                        809 	.ds 1
      00000F                        810 _usbGetDescriptorPrimitive_wantedType_1_82:
      00000F                        811 	.ds 1
                                    812 ;--------------------------------------------------------
                                    813 ; indirectly addressable internal ram data
                                    814 ;--------------------------------------------------------
                                    815 	.area ISEG    (DATA)
                                    816 ;--------------------------------------------------------
                                    817 ; absolute internal ram data
                                    818 ;--------------------------------------------------------
                                    819 	.area IABS    (ABS,DATA)
                                    820 	.area IABS    (ABS,DATA)
                                    821 ;--------------------------------------------------------
                                    822 ; bit data
                                    823 ;--------------------------------------------------------
                                    824 	.area BSEG    (BIT)
                                    825 ;--------------------------------------------------------
                                    826 ; paged external ram data
                                    827 ;--------------------------------------------------------
                                    828 	.area PSEG    (PAG,XDATA)
                                    829 ;--------------------------------------------------------
                                    830 ; external ram data
                                    831 ;--------------------------------------------------------
                                    832 	.area XSEG    (XDATA)
                           00DF02   833 _MDMCTRL0H	=	0xdf02
                           00DF00   834 _SYNC1	=	0xdf00
                           00DF01   835 _SYNC0	=	0xdf01
                           00DF02   836 _PKTLEN	=	0xdf02
                           00DF03   837 _PKTCTRL1	=	0xdf03
                           00DF04   838 _PKTCTRL0	=	0xdf04
                           00DF05   839 _ADDR	=	0xdf05
                           00DF06   840 _CHANNR	=	0xdf06
                           00DF07   841 _FSCTRL1	=	0xdf07
                           00DF08   842 _FSCTRL0	=	0xdf08
                           00DF09   843 _FREQ2	=	0xdf09
                           00DF0A   844 _FREQ1	=	0xdf0a
                           00DF0B   845 _FREQ0	=	0xdf0b
                           00DF0C   846 _MDMCFG4	=	0xdf0c
                           00DF0D   847 _MDMCFG3	=	0xdf0d
                           00DF0E   848 _MDMCFG2	=	0xdf0e
                           00DF0F   849 _MDMCFG1	=	0xdf0f
                           00DF10   850 _MDMCFG0	=	0xdf10
                           00DF11   851 _DEVIATN	=	0xdf11
                           00DF12   852 _MCSM2	=	0xdf12
                           00DF13   853 _MCSM1	=	0xdf13
                           00DF14   854 _MCSM0	=	0xdf14
                           00DF15   855 _FOCCFG	=	0xdf15
                           00DF16   856 _BSCFG	=	0xdf16
                           00DF17   857 _AGCCTRL2	=	0xdf17
                           00DF18   858 _AGCCTRL1	=	0xdf18
                           00DF19   859 _AGCCTRL0	=	0xdf19
                           00DF1A   860 _FREND1	=	0xdf1a
                           00DF1B   861 _FREND0	=	0xdf1b
                           00DF1C   862 _FSCAL3	=	0xdf1c
                           00DF1D   863 _FSCAL2	=	0xdf1d
                           00DF1E   864 _FSCAL1	=	0xdf1e
                           00DF1F   865 _FSCAL0	=	0xdf1f
                           00DF20   866 __XREGDF20	=	0xdf20
                           00DF21   867 __XREGDF21	=	0xdf21
                           00DF22   868 __XREGDF22	=	0xdf22
                           00DF23   869 _TEST2	=	0xdf23
                           00DF24   870 _TEST1	=	0xdf24
                           00DF25   871 _TEST0	=	0xdf25
                           00DF26   872 __XREGDF26	=	0xdf26
                           00DF27   873 _PA_TABLE7	=	0xdf27
                           00DF28   874 _PA_TABLE6	=	0xdf28
                           00DF29   875 _PA_TABLE5	=	0xdf29
                           00DF2A   876 _PA_TABLE4	=	0xdf2a
                           00DF2B   877 _PA_TABLE3	=	0xdf2b
                           00DF2C   878 _PA_TABLE2	=	0xdf2c
                           00DF2D   879 _PA_TABLE1	=	0xdf2d
                           00DF2E   880 _PA_TABLE0	=	0xdf2e
                           00DF2F   881 _IOCFG2	=	0xdf2f
                           00DF30   882 _IOCFG1	=	0xdf30
                           00DF31   883 _IOCFG0	=	0xdf31
                           00DF32   884 __XREGDF32	=	0xdf32
                           00DF33   885 __XREGDF33	=	0xdf33
                           00DF34   886 __XREGDF34	=	0xdf34
                           00DF35   887 __XREGDF35	=	0xdf35
                           00DF36   888 _PARTNUM	=	0xdf36
                           00DF37   889 _VERSION	=	0xdf37
                           00DF38   890 _FREQEST	=	0xdf38
                           00DF39   891 _LQI	=	0xdf39
                           00DF3A   892 _RSSI	=	0xdf3a
                           00DF3B   893 _MARCSTATE	=	0xdf3b
                           00DF3C   894 _PKTSTATUS	=	0xdf3c
                           00DF3D   895 _VCO_VC_DAC	=	0xdf3d
                           00DF40   896 _I2SCFG0	=	0xdf40
                           00DF41   897 _I2SCFG1	=	0xdf41
                           00DF42   898 _I2SDATL	=	0xdf42
                           00DF43   899 _I2SDATH	=	0xdf43
                           00DF44   900 _I2SWCNT	=	0xdf44
                           00DF45   901 _I2SSTAT	=	0xdf45
                           00DF46   902 _I2SCLKF0	=	0xdf46
                           00DF47   903 _I2SCLKF1	=	0xdf47
                           00DF48   904 _I2SCLKF2	=	0xdf48
                           00DF80   905 __NA_P0	=	0xdf80
                           00DF81   906 __NA_SP	=	0xdf81
                           00DF82   907 __NA_DPL0	=	0xdf82
                           00DF83   908 __NA_DPH0	=	0xdf83
                           00DF84   909 __NA_DPL1	=	0xdf84
                           00DF85   910 __NA_DPH1	=	0xdf85
                           00DF86   911 _X_U0CSR	=	0xdf86
                           00DF87   912 __NA_PCON	=	0xdf87
                           00DF88   913 __NA_TCON	=	0xdf88
                           00DF89   914 _X_P0IFG	=	0xdf89
                           00DF8A   915 _X_P1IFG	=	0xdf8a
                           00DF8B   916 _X_P2IFG	=	0xdf8b
                           00DF8C   917 _X_PICTL	=	0xdf8c
                           00DF8D   918 _X_P1IEN	=	0xdf8d
                           00DF8E   919 __X_SFR8E	=	0xdf8e
                           00DF8F   920 _X_P0INP	=	0xdf8f
                           00DF90   921 __NA_P1	=	0xdf90
                           00DF91   922 _X_RFIM	=	0xdf91
                           00DF92   923 __NA_DPS	=	0xdf92
                           00DF93   924 _X_MPAGE	=	0xdf93
                           00DF94   925 __X_SFR94	=	0xdf94
                           00DF95   926 __X_SFR95	=	0xdf95
                           00DF96   927 __X_SFR96	=	0xdf96
                           00DF97   928 __X_SFR97	=	0xdf97
                           00DF98   929 __NA_S0CON	=	0xdf98
                           00DF99   930 __X_SFR99	=	0xdf99
                           00DF9A   931 __NA_IEN2	=	0xdf9a
                           00DF9B   932 __NA_S1CON	=	0xdf9b
                           00DF9C   933 _X_T2CT	=	0xdf9c
                           00DF9D   934 _X_T2PR	=	0xdf9d
                           00DF9E   935 _X_T2CTL	=	0xdf9e
                           00DF9F   936 __X_SFR9F	=	0xdf9f
                           00DFA0   937 __NA_P2	=	0xdfa0
                           00DFA1   938 _X_WORIRQ	=	0xdfa1
                           00DFA2   939 _X_WORCTRL	=	0xdfa2
                           00DFA3   940 _X_WOREVT0	=	0xdfa3
                           00DFA4   941 _X_WOREVT1	=	0xdfa4
                           00DFA5   942 _X_WORTIME0	=	0xdfa5
                           00DFA6   943 _X_WORTIME1	=	0xdfa6
                           00DFA7   944 __X_SFRA7	=	0xdfa7
                           00DFA8   945 __NA_IEN0	=	0xdfa8
                           00DFA9   946 __NA_IP0	=	0xdfa9
                           00DFAA   947 __X_SFRAA	=	0xdfaa
                           00DFAB   948 _X_FWT	=	0xdfab
                           00DFAC   949 _X_FADDRL	=	0xdfac
                           00DFAD   950 _X_FADDRH	=	0xdfad
                           00DFAE   951 _X_FCTL	=	0xdfae
                           00DFAF   952 _X_FWDATA	=	0xdfaf
                           00DFB0   953 __X_SFRB0	=	0xdfb0
                           00DFB1   954 _X_ENCDI	=	0xdfb1
                           00DFB2   955 _X_ENCDO	=	0xdfb2
                           00DFB3   956 _X_ENCCS	=	0xdfb3
                           00DFB4   957 _X_ADCCON1	=	0xdfb4
                           00DFB5   958 _X_ADCCON2	=	0xdfb5
                           00DFB6   959 _X_ADCCON3	=	0xdfb6
                           00DFB7   960 __X_SFRB7	=	0xdfb7
                           00DFB8   961 __NA_IEN1	=	0xdfb8
                           00DFB9   962 __NA_IP1	=	0xdfb9
                           00DFBA   963 _X_ADCL	=	0xdfba
                           00DFBB   964 _X_ADCH	=	0xdfbb
                           00DFBC   965 _X_RNDL	=	0xdfbc
                           00DFBD   966 _X_RNDH	=	0xdfbd
                           00DFBE   967 _X_SLEEP	=	0xdfbe
                           00DFBF   968 __X_SFRBF	=	0xdfbf
                           00DFC0   969 __NA_IRCON	=	0xdfc0
                           00DFC1   970 _X_U0DBUF	=	0xdfc1
                           00DFC2   971 _X_U0BAUD	=	0xdfc2
                           00DFC3   972 __X_SFRC3	=	0xdfc3
                           00DFC4   973 _X_U0UCR	=	0xdfc4
                           00DFC5   974 _X_U0GCR	=	0xdfc5
                           00DFC6   975 _X_CLKCON	=	0xdfc6
                           00DFC7   976 _X_MEMCTR	=	0xdfc7
                           00DFC8   977 __X_SFRC8	=	0xdfc8
                           00DFC9   978 _X_WDCTL	=	0xdfc9
                           00DFCA   979 _X_T3CNT	=	0xdfca
                           00DFCB   980 _X_T3CTL	=	0xdfcb
                           00DFCC   981 _X_T3CCTL0	=	0xdfcc
                           00DFCD   982 _X_T3CC0	=	0xdfcd
                           00DFCE   983 _X_T3CCTL1	=	0xdfce
                           00DFCF   984 _X_T3CC1	=	0xdfcf
                           00DFD0   985 __NA_PSW	=	0xdfd0
                           00DFD1   986 _X_DMAIRQ	=	0xdfd1
                           00DFD2   987 _X_DMA1CFGL	=	0xdfd2
                           00DFD3   988 _X_DMA1CFGH	=	0xdfd3
                           00DFD4   989 _X_DMA0CFGL	=	0xdfd4
                           00DFD5   990 _X_DMA0CFGH	=	0xdfd5
                           00DFD6   991 _X_DMAARM	=	0xdfd6
                           00DFD7   992 _X_DMAREQ	=	0xdfd7
                           00DFD8   993 _X_TIMIF	=	0xdfd8
                           00DFD9   994 _X_RFD	=	0xdfd9
                           00DFDA   995 _X_T1CC0L	=	0xdfda
                           00DFDB   996 _X_T1CC0H	=	0xdfdb
                           00DFDC   997 _X_T1CC1L	=	0xdfdc
                           00DFDD   998 _X_T1CC1H	=	0xdfdd
                           00DFDE   999 _X_T1CC2L	=	0xdfde
                           00DFDF  1000 _X_T1CC2H	=	0xdfdf
                           00DFE0  1001 __NA_ACC	=	0xdfe0
                           00DFE1  1002 _X_RFST	=	0xdfe1
                           00DFE2  1003 _X_T1CNTL	=	0xdfe2
                           00DFE3  1004 _X_T1CNTH	=	0xdfe3
                           00DFE4  1005 _X_T1CTL	=	0xdfe4
                           00DFE5  1006 _X_T1CCTL0	=	0xdfe5
                           00DFE6  1007 _X_T1CCTL1	=	0xdfe6
                           00DFE7  1008 _X_T1CCTL2	=	0xdfe7
                           00DFE8  1009 __NA_IRCON2	=	0xdfe8
                           00DFE9  1010 _X_RFIF	=	0xdfe9
                           00DFEA  1011 _X_T4CNT	=	0xdfea
                           00DFEB  1012 _X_T4CTL	=	0xdfeb
                           00DFEC  1013 _X_T4CCTL0	=	0xdfec
                           00DFED  1014 _X_T4CC0	=	0xdfed
                           00DFEE  1015 _X_T4CCTL1	=	0xdfee
                           00DFEF  1016 _X_T4CC1	=	0xdfef
                           00DFF0  1017 __NA_B	=	0xdff0
                           00DFF1  1018 _X_PERCFG	=	0xdff1
                           00DFF2  1019 _X_ADCCFG	=	0xdff2
                           00DFF3  1020 _X_P0SEL	=	0xdff3
                           00DFF4  1021 _X_P1SEL	=	0xdff4
                           00DFF5  1022 _X_P2SEL	=	0xdff5
                           00DFF6  1023 _X_P1INP	=	0xdff6
                           00DFF7  1024 _X_P2INP	=	0xdff7
                           00DFF8  1025 _X_U1CSR	=	0xdff8
                           00DFF9  1026 _X_U1DBUF	=	0xdff9
                           00DFFA  1027 _X_U1BAUD	=	0xdffa
                           00DFFB  1028 _X_U1UCR	=	0xdffb
                           00DFFC  1029 _X_U1GCR	=	0xdffc
                           00DFFD  1030 _X_P0DIR	=	0xdffd
                           00DFFE  1031 _X_P1DIR	=	0xdffe
                           00DFFF  1032 _X_P2DIR	=	0xdfff
                           00DE00  1033 _USBADDR	=	0xde00
                           00DE01  1034 _USBPOW	=	0xde01
                           00DE02  1035 _USBIIF	=	0xde02
                           00DE04  1036 _USBOIF	=	0xde04
                           00DE06  1037 _USBCIF	=	0xde06
                           00DE07  1038 _USBIIE	=	0xde07
                           00DE09  1039 _USBOIE	=	0xde09
                           00DE0B  1040 _USBCIE	=	0xde0b
                           00DE0C  1041 _USBFRML	=	0xde0c
                           00DE0D  1042 _USBFRMH	=	0xde0d
                           00DE0E  1043 _USBINDEX	=	0xde0e
                           00DE10  1044 _USBMAXI	=	0xde10
                           00DE11  1045 _USBCS0	=	0xde11
                           00DE11  1046 _USBCSIL	=	0xde11
                           00DE12  1047 _USBCSIH	=	0xde12
                           00DE13  1048 _USBMAXO	=	0xde13
                           00DE14  1049 _USBCSOL	=	0xde14
                           00DE15  1050 _USBCSOH	=	0xde15
                           00DE16  1051 _USBCNT0	=	0xde16
                           00DE16  1052 _USBCNTL	=	0xde16
                           00DE17  1053 _USBCNTH	=	0xde17
                           00DE20  1054 _USBF0	=	0xde20
                           00DE22  1055 _USBF1	=	0xde22
                           00DE24  1056 _USBF2	=	0xde24
                           00DE26  1057 _USBF3	=	0xde26
                           00DE28  1058 _USBF4	=	0xde28
                           00DE2A  1059 _USBF5	=	0xde2a
                           00DE20  1060 _USBFIFO	=	0xde20
      00F0D4                       1061 _usb_ep0_OUTbuf::
      00F0D4                       1062 	.ds 64
      00F114                       1063 _usb_ep5_OUTbuf::
      00F114                       1064 	.ds 64
      00F154                       1065 _ep0iobuf::
      00F154                       1066 	.ds 14
      00F162                       1067 _ep5iobuf::
      00F162                       1068 	.ds 14
      00F170                       1069 _appstatus::
      00F170                       1070 	.ds 1
      00F171                       1071 _usbdma::
      00F171                       1072 	.ds 8
                                   1073 ;--------------------------------------------------------
                                   1074 ; absolute external ram data
                                   1075 ;--------------------------------------------------------
                                   1076 	.area XABS    (ABS,XDATA)
                                   1077 ;--------------------------------------------------------
                                   1078 ; external initialized ram data
                                   1079 ;--------------------------------------------------------
                                   1080 	.area XISEG   (XDATA)
                                   1081 	.area HOME    (CODE)
                                   1082 	.area GSINIT0 (CODE)
                                   1083 	.area GSINIT1 (CODE)
                                   1084 	.area GSINIT2 (CODE)
                                   1085 	.area GSINIT3 (CODE)
                                   1086 	.area GSINIT4 (CODE)
                                   1087 	.area GSINIT5 (CODE)
                                   1088 	.area GSINIT  (CODE)
                                   1089 	.area GSFINAL (CODE)
                                   1090 	.area CSEG    (CODE)
                                   1091 ;--------------------------------------------------------
                                   1092 ; global & static initialisations
                                   1093 ;--------------------------------------------------------
                                   1094 	.area HOME    (CODE)
                                   1095 	.area GSINIT  (CODE)
                                   1096 	.area GSFINAL (CODE)
                                   1097 	.area GSINIT  (CODE)
                                   1098 ;--------------------------------------------------------
                                   1099 ; Home
                                   1100 ;--------------------------------------------------------
                                   1101 	.area HOME    (CODE)
                                   1102 	.area HOME    (CODE)
                                   1103 ;--------------------------------------------------------
                                   1104 ; code
                                   1105 ;--------------------------------------------------------
                                   1106 	.area CSEG    (CODE)
                                   1107 ;------------------------------------------------------------
                                   1108 ;Allocation info for local variables in function 'txdataold'
                                   1109 ;------------------------------------------------------------
                                   1110 ;cmd                       Allocated with name '_txdataold_PARM_2'
                                   1111 ;len                       Allocated with name '_txdataold_PARM_3'
                                   1112 ;dataptr                   Allocated with name '_txdataold_PARM_4'
                                   1113 ;app                       Allocated to registers r7 
                                   1114 ;loop                      Allocated to registers r4 r5 
                                   1115 ;firsttime                 Allocated to registers r6 
                                   1116 ;------------------------------------------------------------
                                   1117 ;	cc1111usb.c:41: void txdataold(u8 app, u8 cmd, u16 len, u8* dataptr)      // assumed EP5 for application use
                                   1118 ;	-----------------------------------------
                                   1119 ;	 function txdataold
                                   1120 ;	-----------------------------------------
      000A27                       1121 _txdataold:
                           000007  1122 	ar7 = 0x07
                           000006  1123 	ar6 = 0x06
                           000005  1124 	ar5 = 0x05
                           000004  1125 	ar4 = 0x04
                           000003  1126 	ar3 = 0x03
                           000002  1127 	ar2 = 0x02
                           000001  1128 	ar1 = 0x01
                           000000  1129 	ar0 = 0x00
      000A27 AF 82            [24] 1130 	mov	r7,dpl
                                   1131 ;	cc1111usb.c:46: u8 firsttime=1;
      000A29 7E 01            [12] 1132 	mov	r6,#0x01
                                   1133 ;	cc1111usb.c:47: USBINDEX=5;
      000A2B 90 DE 0E         [24] 1134 	mov	dptr,#_USBINDEX
      000A2E 74 05            [12] 1135 	mov	a,#0x05
      000A30 F0               [24] 1136 	movx	@dptr,a
                                   1137 ;	cc1111usb.c:49: while (len>0)
      000A31                       1138 00115$:
      000A31 E5 27            [12] 1139 	mov	a,_txdataold_PARM_3
      000A33 45 28            [12] 1140 	orl	a,(_txdataold_PARM_3 + 1)
      000A35 70 01            [24] 1141 	jnz	00156$
      000A37 22               [24] 1142 	ret
      000A38                       1143 00156$:
                                   1144 ;	cc1111usb.c:53: loop = TXDATA_MAX_WAIT;
      000A38 7C 64            [12] 1145 	mov	r4,#0x64
      000A3A 7D 00            [12] 1146 	mov	r5,#0x00
                                   1147 ;	cc1111usb.c:54: while (ep5iobuf.flags & EP_INBUF_WRITTEN && loop>0)                   // has last msg been recvd?
      000A3C                       1148 00102$:
      000A3C 90 F1 6E         [24] 1149 	mov	dptr,#(_ep5iobuf + 0x000c)
      000A3F E0               [24] 1150 	movx	a,@dptr
      000A40 FB               [12] 1151 	mov	r3,a
      000A41 30 E0 2C         [24] 1152 	jnb	acc.0,00104$
      000A44 EC               [12] 1153 	mov	a,r4
      000A45 4D               [12] 1154 	orl	a,r5
      000A46 60 28            [24] 1155 	jz	00104$
                                   1156 ;	cc1111usb.c:58: REALLYFASTBLINK();
      000A48 D2 90            [12] 1157 	setb	_P1_0
      000A4A 90 00 02         [24] 1158 	mov	dptr,#0x0002
      000A4D C0 07            [24] 1159 	push	ar7
      000A4F C0 06            [24] 1160 	push	ar6
      000A51 C0 05            [24] 1161 	push	ar5
      000A53 C0 04            [24] 1162 	push	ar4
      000A55 12 09 63         [24] 1163 	lcall	_sleepMillis
      000A58 C2 90            [12] 1164 	clr	_P1_0
      000A5A 90 00 0A         [24] 1165 	mov	dptr,#0x000A
      000A5D 12 09 63         [24] 1166 	lcall	_sleepMillis
      000A60 D0 04            [24] 1167 	pop	ar4
      000A62 D0 05            [24] 1168 	pop	ar5
      000A64 D0 06            [24] 1169 	pop	ar6
      000A66 D0 07            [24] 1170 	pop	ar7
                                   1171 ;	cc1111usb.c:60: lastCode[1] = 1;
      000A68 90 F0 D3         [24] 1172 	mov	dptr,#(_lastCode + 0x0001)
      000A6B 74 01            [12] 1173 	mov	a,#0x01
      000A6D F0               [24] 1174 	movx	@dptr,a
      000A6E 80 CC            [24] 1175 	sjmp	00102$
      000A70                       1176 00104$:
                                   1177 ;	cc1111usb.c:65: if (firsttime==1){                                             // first time through only please
      000A70 BE 01 2D         [24] 1178 	cjne	r6,#0x01,00112$
                                   1179 ;	cc1111usb.c:68: firsttime=0;
      000A73 7E 00            [12] 1180 	mov	r6,#0x00
                                   1181 ;	cc1111usb.c:69: USBF5 = 0x40;
      000A75 90 DE 2A         [24] 1182 	mov	dptr,#_USBF5
      000A78 74 40            [12] 1183 	mov	a,#0x40
      000A7A F0               [24] 1184 	movx	@dptr,a
                                   1185 ;	cc1111usb.c:70: USBF5 = app;
      000A7B EF               [12] 1186 	mov	a,r7
      000A7C F0               [24] 1187 	movx	@dptr,a
                                   1188 ;	cc1111usb.c:71: USBF5 = cmd;
      000A7D E5 26            [12] 1189 	mov	a,_txdataold_PARM_2
      000A7F F0               [24] 1190 	movx	@dptr,a
                                   1191 ;	cc1111usb.c:72: USBF5 = len & 0xff;
      000A80 AA 27            [24] 1192 	mov	r2,_txdataold_PARM_3
      000A82 7B 00            [12] 1193 	mov	r3,#0x00
      000A84 EA               [12] 1194 	mov	a,r2
      000A85 F0               [24] 1195 	movx	@dptr,a
                                   1196 ;	cc1111usb.c:73: USBF5 = len >> 8;
      000A86 E5 28            [12] 1197 	mov	a,(_txdataold_PARM_3 + 1)
      000A88 F0               [24] 1198 	movx	@dptr,a
                                   1199 ;	cc1111usb.c:74: if (len>EP5IN_MAX_PACKET_SIZE-5)
      000A89 C3               [12] 1200 	clr	c
      000A8A 74 EF            [12] 1201 	mov	a,#0xEF
      000A8C 95 27            [12] 1202 	subb	a,_txdataold_PARM_3
      000A8E 74 01            [12] 1203 	mov	a,#0x01
      000A90 95 28            [12] 1204 	subb	a,(_txdataold_PARM_3 + 1)
      000A92 50 06            [24] 1205 	jnc	00106$
                                   1206 ;	cc1111usb.c:75: loop=EP5IN_MAX_PACKET_SIZE-5;
      000A94 7C EF            [12] 1207 	mov	r4,#0xEF
      000A96 7D 01            [12] 1208 	mov	r5,#0x01
      000A98 80 1B            [24] 1209 	sjmp	00113$
      000A9A                       1210 00106$:
                                   1211 ;	cc1111usb.c:77: loop=len;
      000A9A AC 27            [24] 1212 	mov	r4,_txdataold_PARM_3
      000A9C AD 28            [24] 1213 	mov	r5,(_txdataold_PARM_3 + 1)
      000A9E 80 15            [24] 1214 	sjmp	00113$
      000AA0                       1215 00112$:
                                   1216 ;	cc1111usb.c:80: if (len>EP5IN_MAX_PACKET_SIZE)
      000AA0 C3               [12] 1217 	clr	c
      000AA1 74 F4            [12] 1218 	mov	a,#0xF4
      000AA3 95 27            [12] 1219 	subb	a,_txdataold_PARM_3
      000AA5 74 01            [12] 1220 	mov	a,#0x01
      000AA7 95 28            [12] 1221 	subb	a,(_txdataold_PARM_3 + 1)
      000AA9 50 06            [24] 1222 	jnc	00109$
                                   1223 ;	cc1111usb.c:81: loop=EP5IN_MAX_PACKET_SIZE;
      000AAB 7C F4            [12] 1224 	mov	r4,#0xF4
      000AAD 7D 01            [12] 1225 	mov	r5,#0x01
      000AAF 80 04            [24] 1226 	sjmp	00113$
      000AB1                       1227 00109$:
                                   1228 ;	cc1111usb.c:83: loop=len;
      000AB1 AC 27            [24] 1229 	mov	r4,_txdataold_PARM_3
      000AB3 AD 28            [24] 1230 	mov	r5,(_txdataold_PARM_3 + 1)
      000AB5                       1231 00113$:
                                   1232 ;	cc1111usb.c:87: len -= loop;
      000AB5 E5 27            [12] 1233 	mov	a,_txdataold_PARM_3
      000AB7 C3               [12] 1234 	clr	c
      000AB8 9C               [12] 1235 	subb	a,r4
      000AB9 F5 27            [12] 1236 	mov	_txdataold_PARM_3,a
      000ABB E5 28            [12] 1237 	mov	a,(_txdataold_PARM_3 + 1)
      000ABD 9D               [12] 1238 	subb	a,r5
      000ABE F5 28            [12] 1239 	mov	(_txdataold_PARM_3 + 1),a
      000AC0 A9 29            [24] 1240 	mov	r1,_txdataold_PARM_4
      000AC2 AA 2A            [24] 1241 	mov	r2,(_txdataold_PARM_4 + 1)
      000AC4 AB 2B            [24] 1242 	mov	r3,(_txdataold_PARM_4 + 2)
      000AC6                       1243 00119$:
                                   1244 ;	cc1111usb.c:90: for (;loop>0;loop--)
      000AC6 EC               [12] 1245 	mov	a,r4
      000AC7 4D               [12] 1246 	orl	a,r5
      000AC8 70 08            [24] 1247 	jnz	00118$
      000ACA 89 29            [24] 1248 	mov	_txdataold_PARM_4,r1
      000ACC 8A 2A            [24] 1249 	mov	(_txdataold_PARM_4 + 1),r2
      000ACE 8B 2B            [24] 1250 	mov	(_txdataold_PARM_4 + 2),r3
      000AD0 80 1B            [24] 1251 	sjmp	00114$
      000AD2                       1252 00118$:
                                   1253 ;	cc1111usb.c:92: USBF5 = *dataptr++;
      000AD2 89 82            [24] 1254 	mov	dpl,r1
      000AD4 8A 83            [24] 1255 	mov	dph,r2
      000AD6 8B F0            [24] 1256 	mov	b,r3
      000AD8 12 1A 67         [24] 1257 	lcall	__gptrget
      000ADB F8               [12] 1258 	mov	r0,a
      000ADC A3               [24] 1259 	inc	dptr
      000ADD A9 82            [24] 1260 	mov	r1,dpl
      000ADF AA 83            [24] 1261 	mov	r2,dph
      000AE1 90 DE 2A         [24] 1262 	mov	dptr,#_USBF5
      000AE4 E8               [12] 1263 	mov	a,r0
      000AE5 F0               [24] 1264 	movx	@dptr,a
                                   1265 ;	cc1111usb.c:90: for (;loop>0;loop--)
      000AE6 1C               [12] 1266 	dec	r4
      000AE7 BC FF 01         [24] 1267 	cjne	r4,#0xFF,00164$
      000AEA 1D               [12] 1268 	dec	r5
      000AEB                       1269 00164$:
      000AEB 80 D9            [24] 1270 	sjmp	00119$
      000AED                       1271 00114$:
                                   1272 ;	cc1111usb.c:95: USBCSIL |= USBCSIL_INPKT_RDY;
      000AED 90 DE 11         [24] 1273 	mov	dptr,#_USBCSIL
      000AF0 E0               [24] 1274 	movx	a,@dptr
      000AF1 FD               [12] 1275 	mov	r5,a
      000AF2 74 01            [12] 1276 	mov	a,#0x01
      000AF4 4D               [12] 1277 	orl	a,r5
      000AF5 F0               [24] 1278 	movx	@dptr,a
                                   1279 ;	cc1111usb.c:96: ep5iobuf.flags |= EP_INBUF_WRITTEN;                         // set the 'written' flag
      000AF6 90 F1 6E         [24] 1280 	mov	dptr,#(_ep5iobuf + 0x000c)
      000AF9 E0               [24] 1281 	movx	a,@dptr
      000AFA 44 01            [12] 1282 	orl	a,#0x01
      000AFC FD               [12] 1283 	mov	r5,a
      000AFD F0               [24] 1284 	movx	@dptr,a
      000AFE 02 0A 31         [24] 1285 	ljmp	00115$
                                   1286 ;------------------------------------------------------------
                                   1287 ;Allocation info for local variables in function 'txdata'
                                   1288 ;------------------------------------------------------------
                                   1289 ;cmd                       Allocated with name '_txdata_PARM_2'
                                   1290 ;len                       Allocated with name '_txdata_PARM_3'
                                   1291 ;dataptr                   Allocated with name '_txdata_PARM_4'
                                   1292 ;app                       Allocated to registers r7 
                                   1293 ;loop                      Allocated to registers r4 r5 
                                   1294 ;firsttime                 Allocated to registers r6 
                                   1295 ;------------------------------------------------------------
                                   1296 ;	cc1111usb.c:101: void txdata(u8 app, u8 cmd, u16 len, __xdata u8* dataptr)      // assumed EP5 for application use
                                   1297 ;	-----------------------------------------
                                   1298 ;	 function txdata
                                   1299 ;	-----------------------------------------
      000B01                       1300 _txdata:
      000B01 AF 82            [24] 1301 	mov	r7,dpl
                                   1302 ;	cc1111usb.c:106: u8 firsttime=1;
      000B03 7E 01            [12] 1303 	mov	r6,#0x01
                                   1304 ;	cc1111usb.c:107: USBINDEX=5;
      000B05 90 DE 0E         [24] 1305 	mov	dptr,#_USBINDEX
      000B08 74 05            [12] 1306 	mov	a,#0x05
      000B0A F0               [24] 1307 	movx	@dptr,a
                                   1308 ;	cc1111usb.c:109: while (len>0)
      000B0B                       1309 00117$:
      000B0B E5 2D            [12] 1310 	mov	a,_txdata_PARM_3
      000B0D 45 2E            [12] 1311 	orl	a,(_txdata_PARM_3 + 1)
      000B0F 70 01            [24] 1312 	jnz	00153$
      000B11 22               [24] 1313 	ret
      000B12                       1314 00153$:
                                   1315 ;	cc1111usb.c:114: while (ep5iobuf.flags & EP_INBUF_WRITTEN && loop>0)                   // has last msg been recvd?
      000B12 7C 64            [12] 1316 	mov	r4,#0x64
      000B14 7D 00            [12] 1317 	mov	r5,#0x00
      000B16                       1318 00102$:
      000B16 90 F1 6E         [24] 1319 	mov	dptr,#(_ep5iobuf + 0x000c)
      000B19 E0               [24] 1320 	movx	a,@dptr
      000B1A FB               [12] 1321 	mov	r3,a
      000B1B 30 E0 31         [24] 1322 	jnb	acc.0,00104$
      000B1E EC               [12] 1323 	mov	a,r4
      000B1F 4D               [12] 1324 	orl	a,r5
      000B20 60 2D            [24] 1325 	jz	00104$
                                   1326 ;	cc1111usb.c:118: REALLYFASTBLINK();
      000B22 D2 90            [12] 1327 	setb	_P1_0
      000B24 90 00 02         [24] 1328 	mov	dptr,#0x0002
      000B27 C0 07            [24] 1329 	push	ar7
      000B29 C0 06            [24] 1330 	push	ar6
      000B2B C0 05            [24] 1331 	push	ar5
      000B2D C0 04            [24] 1332 	push	ar4
      000B2F 12 09 63         [24] 1333 	lcall	_sleepMillis
      000B32 C2 90            [12] 1334 	clr	_P1_0
      000B34 90 00 0A         [24] 1335 	mov	dptr,#0x000A
      000B37 12 09 63         [24] 1336 	lcall	_sleepMillis
      000B3A D0 04            [24] 1337 	pop	ar4
      000B3C D0 05            [24] 1338 	pop	ar5
      000B3E D0 06            [24] 1339 	pop	ar6
      000B40 D0 07            [24] 1340 	pop	ar7
                                   1341 ;	cc1111usb.c:120: lastCode[1] = 1;
      000B42 90 F0 D3         [24] 1342 	mov	dptr,#(_lastCode + 0x0001)
      000B45 74 01            [12] 1343 	mov	a,#0x01
      000B47 F0               [24] 1344 	movx	@dptr,a
                                   1345 ;	cc1111usb.c:121: loop--;
      000B48 1C               [12] 1346 	dec	r4
      000B49 BC FF 01         [24] 1347 	cjne	r4,#0xFF,00156$
      000B4C 1D               [12] 1348 	dec	r5
      000B4D                       1349 00156$:
      000B4D 80 C7            [24] 1350 	sjmp	00102$
      000B4F                       1351 00104$:
                                   1352 ;	cc1111usb.c:125: if (firsttime==1){                                             // first time through only please
      000B4F BE 01 2D         [24] 1353 	cjne	r6,#0x01,00112$
                                   1354 ;	cc1111usb.c:128: firsttime=0;
      000B52 7E 00            [12] 1355 	mov	r6,#0x00
                                   1356 ;	cc1111usb.c:129: USBF5 = 0x40;
      000B54 90 DE 2A         [24] 1357 	mov	dptr,#_USBF5
      000B57 74 40            [12] 1358 	mov	a,#0x40
      000B59 F0               [24] 1359 	movx	@dptr,a
                                   1360 ;	cc1111usb.c:130: USBF5 = app;
      000B5A EF               [12] 1361 	mov	a,r7
      000B5B F0               [24] 1362 	movx	@dptr,a
                                   1363 ;	cc1111usb.c:131: USBF5 = cmd;
      000B5C E5 2C            [12] 1364 	mov	a,_txdata_PARM_2
      000B5E F0               [24] 1365 	movx	@dptr,a
                                   1366 ;	cc1111usb.c:132: USBF5 = len & 0xff;
      000B5F AC 2D            [24] 1367 	mov	r4,_txdata_PARM_3
      000B61 7D 00            [12] 1368 	mov	r5,#0x00
      000B63 EC               [12] 1369 	mov	a,r4
      000B64 F0               [24] 1370 	movx	@dptr,a
                                   1371 ;	cc1111usb.c:133: USBF5 = len >> 8;
      000B65 E5 2E            [12] 1372 	mov	a,(_txdata_PARM_3 + 1)
      000B67 F0               [24] 1373 	movx	@dptr,a
                                   1374 ;	cc1111usb.c:134: if (len>EP5IN_MAX_PACKET_SIZE-5)
      000B68 C3               [12] 1375 	clr	c
      000B69 74 EF            [12] 1376 	mov	a,#0xEF
      000B6B 95 2D            [12] 1377 	subb	a,_txdata_PARM_3
      000B6D 74 01            [12] 1378 	mov	a,#0x01
      000B6F 95 2E            [12] 1379 	subb	a,(_txdata_PARM_3 + 1)
      000B71 50 06            [24] 1380 	jnc	00106$
                                   1381 ;	cc1111usb.c:135: loop=EP5IN_MAX_PACKET_SIZE-5;
      000B73 7C EF            [12] 1382 	mov	r4,#0xEF
      000B75 7D 01            [12] 1383 	mov	r5,#0x01
      000B77 80 1B            [24] 1384 	sjmp	00113$
      000B79                       1385 00106$:
                                   1386 ;	cc1111usb.c:137: loop=len;
      000B79 AC 2D            [24] 1387 	mov	r4,_txdata_PARM_3
      000B7B AD 2E            [24] 1388 	mov	r5,(_txdata_PARM_3 + 1)
      000B7D 80 15            [24] 1389 	sjmp	00113$
      000B7F                       1390 00112$:
                                   1391 ;	cc1111usb.c:140: if (len>EP5IN_MAX_PACKET_SIZE)
      000B7F C3               [12] 1392 	clr	c
      000B80 74 F4            [12] 1393 	mov	a,#0xF4
      000B82 95 2D            [12] 1394 	subb	a,_txdata_PARM_3
      000B84 74 01            [12] 1395 	mov	a,#0x01
      000B86 95 2E            [12] 1396 	subb	a,(_txdata_PARM_3 + 1)
      000B88 50 06            [24] 1397 	jnc	00109$
                                   1398 ;	cc1111usb.c:141: loop=EP5IN_MAX_PACKET_SIZE;
      000B8A 7C F4            [12] 1399 	mov	r4,#0xF4
      000B8C 7D 01            [12] 1400 	mov	r5,#0x01
      000B8E 80 04            [24] 1401 	sjmp	00113$
      000B90                       1402 00109$:
                                   1403 ;	cc1111usb.c:143: loop=len;
      000B90 AC 2D            [24] 1404 	mov	r4,_txdata_PARM_3
      000B92 AD 2E            [24] 1405 	mov	r5,(_txdata_PARM_3 + 1)
      000B94                       1406 00113$:
                                   1407 ;	cc1111usb.c:147: len -= loop;
      000B94 E5 2D            [12] 1408 	mov	a,_txdata_PARM_3
      000B96 C3               [12] 1409 	clr	c
      000B97 9C               [12] 1410 	subb	a,r4
      000B98 F5 2D            [12] 1411 	mov	_txdata_PARM_3,a
      000B9A E5 2E            [12] 1412 	mov	a,(_txdata_PARM_3 + 1)
      000B9C 9D               [12] 1413 	subb	a,r5
      000B9D F5 2E            [12] 1414 	mov	(_txdata_PARM_3 + 1),a
                                   1415 ;	cc1111usb.c:149: DMAARM |= 0x80 + DMAARM1;
      000B9F 43 D6 82         [24] 1416 	orl	_DMAARM,#0x82
                                   1417 ;	cc1111usb.c:150: usbdma.srcAddrH = ((u16)dataptr)>>8;
      000BA2 AA 2F            [24] 1418 	mov	r2,_txdata_PARM_4
      000BA4 AB 30            [24] 1419 	mov	r3,(_txdata_PARM_4 + 1)
      000BA6 8B 01            [24] 1420 	mov	ar1,r3
      000BA8 90 F1 71         [24] 1421 	mov	dptr,#_usbdma
      000BAB E9               [12] 1422 	mov	a,r1
      000BAC F0               [24] 1423 	movx	@dptr,a
                                   1424 ;	cc1111usb.c:151: usbdma.srcAddrL = ((u16)dataptr)&0xff;
      000BAD 7B 00            [12] 1425 	mov	r3,#0x00
      000BAF 90 F1 72         [24] 1426 	mov	dptr,#(_usbdma + 0x0001)
      000BB2 EA               [12] 1427 	mov	a,r2
      000BB3 F0               [24] 1428 	movx	@dptr,a
                                   1429 ;	cc1111usb.c:152: usbdma.destAddrH = 0xde;     //USBF5 == 0xde2a
      000BB4 90 F1 73         [24] 1430 	mov	dptr,#(_usbdma + 0x0002)
      000BB7 74 DE            [12] 1431 	mov	a,#0xDE
      000BB9 F0               [24] 1432 	movx	@dptr,a
                                   1433 ;	cc1111usb.c:153: usbdma.destAddrL = 0x2a;
      000BBA 90 F1 74         [24] 1434 	mov	dptr,#(_usbdma + 0x0003)
      000BBD 74 2A            [12] 1435 	mov	a,#0x2A
      000BBF F0               [24] 1436 	movx	@dptr,a
                                   1437 ;	cc1111usb.c:154: usbdma.lenL = loop;
      000BC0 90 F1 76         [24] 1438 	mov	dptr,#(_usbdma + 0x0005)
      000BC3 EC               [12] 1439 	mov	a,r4
      000BC4 F0               [24] 1440 	movx	@dptr,a
                                   1441 ;	cc1111usb.c:155: usbdma.lenH = 0;
      000BC5 90 F1 75         [24] 1442 	mov	dptr,#(_usbdma + 0x0004)
      000BC8 E0               [24] 1443 	movx	a,@dptr
      000BC9 54 E0            [12] 1444 	anl	a,#0xE0
      000BCB F0               [24] 1445 	movx	@dptr,a
                                   1446 ;	cc1111usb.c:156: usbdma.srcInc = 1;
      000BCC 90 F1 78         [24] 1447 	mov	dptr,#(_usbdma + 0x0007)
      000BCF E0               [24] 1448 	movx	a,@dptr
      000BD0 54 3F            [12] 1449 	anl	a,#0x3F
      000BD2 44 40            [12] 1450 	orl	a,#0x40
      000BD4 F0               [24] 1451 	movx	@dptr,a
                                   1452 ;	cc1111usb.c:157: usbdma.destInc = 0;
      000BD5 90 F1 78         [24] 1453 	mov	dptr,#(_usbdma + 0x0007)
      000BD8 E0               [24] 1454 	movx	a,@dptr
      000BD9 54 CF            [12] 1455 	anl	a,#0xCF
      000BDB F0               [24] 1456 	movx	@dptr,a
                                   1457 ;	cc1111usb.c:158: DMAARM |= DMAARM1;
      000BDC 43 D6 02         [24] 1458 	orl	_DMAARM,#0x02
                                   1459 ;	cc1111usb.c:159: DMAREQ |= DMAARM1;
      000BDF 43 D7 02         [24] 1460 	orl	_DMAREQ,#0x02
                                   1461 ;	cc1111usb.c:161: while (!(DMAIRQ & DMAARM1));
      000BE2                       1462 00114$:
      000BE2 E5 D1            [12] 1463 	mov	a,_DMAIRQ
      000BE4 30 E1 FB         [24] 1464 	jnb	acc.1,00114$
                                   1465 ;	cc1111usb.c:162: DMAIRQ &= ~DMAARM1;             // FIXME: superfuous?
      000BE7 AD D1            [24] 1466 	mov	r5,_DMAIRQ
      000BE9 74 FD            [12] 1467 	mov	a,#0xFD
      000BEB 5D               [12] 1468 	anl	a,r5
      000BEC F5 D1            [12] 1469 	mov	_DMAIRQ,a
                                   1470 ;	cc1111usb.c:164: USBCSIL |= USBCSIL_INPKT_RDY;
      000BEE 90 DE 11         [24] 1471 	mov	dptr,#_USBCSIL
      000BF1 E0               [24] 1472 	movx	a,@dptr
      000BF2 FD               [12] 1473 	mov	r5,a
      000BF3 74 01            [12] 1474 	mov	a,#0x01
      000BF5 4D               [12] 1475 	orl	a,r5
      000BF6 F0               [24] 1476 	movx	@dptr,a
                                   1477 ;	cc1111usb.c:165: ep5iobuf.flags |= EP_INBUF_WRITTEN;                         // set the 'written' flag
      000BF7 90 F1 6E         [24] 1478 	mov	dptr,#(_ep5iobuf + 0x000c)
      000BFA E0               [24] 1479 	movx	a,@dptr
      000BFB 44 01            [12] 1480 	orl	a,#0x01
      000BFD FD               [12] 1481 	mov	r5,a
      000BFE F0               [24] 1482 	movx	@dptr,a
      000BFF 02 0B 0B         [24] 1483 	ljmp	00117$
                                   1484 ;------------------------------------------------------------
                                   1485 ;Allocation info for local variables in function 'waitForUSBsetup'
                                   1486 ;------------------------------------------------------------
                                   1487 ;	cc1111usb.c:172: void waitForUSBsetup() 
                                   1488 ;	-----------------------------------------
                                   1489 ;	 function waitForUSBsetup
                                   1490 ;	-----------------------------------------
      000C02                       1491 _waitForUSBsetup:
                                   1492 ;	cc1111usb.c:174: while (USBADDR==0 && (appstatus<1))
      000C02                       1493 00102$:
      000C02 90 DE 00         [24] 1494 	mov	dptr,#_USBADDR
      000C05 E0               [24] 1495 	movx	a,@dptr
      000C06 FF               [12] 1496 	mov	r7,a
      000C07 70 0F            [24] 1497 	jnz	00104$
      000C09 90 F1 70         [24] 1498 	mov	dptr,#_appstatus
      000C0C E0               [24] 1499 	movx	a,@dptr
      000C0D FF               [12] 1500 	mov	r7,a
      000C0E BF 01 00         [24] 1501 	cjne	r7,#0x01,00117$
      000C11                       1502 00117$:
      000C11 50 05            [24] 1503 	jnc	00104$
                                   1504 ;	cc1111usb.c:176: usbProcessEvents();
      000C13 12 17 7B         [24] 1505 	lcall	_usbProcessEvents
      000C16 80 EA            [24] 1506 	sjmp	00102$
      000C18                       1507 00104$:
                                   1508 ;	cc1111usb.c:179: blink(200,200);
      000C18 D2 90            [12] 1509 	setb	_P1_0
      000C1A 90 00 C8         [24] 1510 	mov	dptr,#0x00C8
      000C1D 12 09 63         [24] 1511 	lcall	_sleepMillis
      000C20 C2 90            [12] 1512 	clr	_P1_0
      000C22 90 00 C8         [24] 1513 	mov	dptr,#0x00C8
      000C25 02 09 63         [24] 1514 	ljmp	_sleepMillis
                                   1515 ;------------------------------------------------------------
                                   1516 ;Allocation info for local variables in function 'usb_init'
                                   1517 ;------------------------------------------------------------
                                   1518 ;	cc1111usb.c:189: void usb_init(void)
                                   1519 ;	-----------------------------------------
                                   1520 ;	 function usb_init
                                   1521 ;	-----------------------------------------
      000C28                       1522 _usb_init:
                                   1523 ;	cc1111usb.c:191: USB_RESET();
      000C28 AF BE            [24] 1524 	mov	r7,_SLEEP
      000C2A 74 7F            [12] 1525 	mov	a,#0x7F
      000C2C 5F               [12] 1526 	anl	a,r7
      000C2D F5 BE            [12] 1527 	mov	_SLEEP,a
                                   1528 ; nop; 
      000C2F 43 BE 80         [24] 1529 	orl	_SLEEP,#0x80
                                   1530 ;	cc1111usb.c:194: DMA1CFGH = ((u16)(&usbdma))>>8;
      000C32 7E 71            [12] 1531 	mov	r6,#_usbdma
      000C34 7F F1            [12] 1532 	mov	r7,#(_usbdma >> 8)
      000C36 8F D3            [24] 1533 	mov	_DMA1CFGH,r7
                                   1534 ;	cc1111usb.c:195: DMA1CFGL = ((u16)(&usbdma))&0xff;
      000C38 7E 71            [12] 1535 	mov	r6,#_usbdma
      000C3A 7F F1            [12] 1536 	mov	r7,#(_usbdma >> 8)
      000C3C 8E D2            [24] 1537 	mov	_DMA1CFGL,r6
                                   1538 ;	cc1111usb.c:196: usbdma.vlen = 0;
      000C3E 90 F1 75         [24] 1539 	mov	dptr,#(_usbdma + 0x0004)
      000C41 E0               [24] 1540 	movx	a,@dptr
      000C42 54 1F            [12] 1541 	anl	a,#0x1F
      000C44 F0               [24] 1542 	movx	@dptr,a
                                   1543 ;	cc1111usb.c:197: usbdma.wordSize = 0;
      000C45 90 F1 77         [24] 1544 	mov	dptr,#(_usbdma + 0x0006)
      000C48 E0               [24] 1545 	movx	a,@dptr
      000C49 54 7F            [12] 1546 	anl	a,#0x7F
      000C4B F0               [24] 1547 	movx	@dptr,a
                                   1548 ;	cc1111usb.c:198: usbdma.lenH = 0;
      000C4C 90 F1 75         [24] 1549 	mov	dptr,#(_usbdma + 0x0004)
      000C4F E0               [24] 1550 	movx	a,@dptr
      000C50 54 E0            [12] 1551 	anl	a,#0xE0
      000C52 F0               [24] 1552 	movx	@dptr,a
                                   1553 ;	cc1111usb.c:199: usbdma.tMode = 1;
      000C53 90 F1 77         [24] 1554 	mov	dptr,#(_usbdma + 0x0006)
      000C56 E0               [24] 1555 	movx	a,@dptr
      000C57 54 9F            [12] 1556 	anl	a,#0x9F
      000C59 44 20            [12] 1557 	orl	a,#0x20
      000C5B F0               [24] 1558 	movx	@dptr,a
                                   1559 ;	cc1111usb.c:200: usbdma.trig = 0;
      000C5C 90 F1 77         [24] 1560 	mov	dptr,#(_usbdma + 0x0006)
      000C5F E0               [24] 1561 	movx	a,@dptr
      000C60 54 E0            [12] 1562 	anl	a,#0xE0
      000C62 F0               [24] 1563 	movx	@dptr,a
                                   1564 ;	cc1111usb.c:201: usbdma.irqMask = 1;
                                   1565 ;	cc1111usb.c:202: usbdma.m8 = 0;
      000C63 90 F1 78         [24] 1566 	mov	dptr,#(_usbdma + 0x0007)
      000C66 E0               [24] 1567 	movx	a,@dptr
      000C67 44 08            [12] 1568 	orl	a,#0x08
      000C69 F0               [24] 1569 	movx	@dptr,a
      000C6A E0               [24] 1570 	movx	a,@dptr
      000C6B 54 FB            [12] 1571 	anl	a,#0xFB
      000C6D F0               [24] 1572 	movx	@dptr,a
                                   1573 ;	cc1111usb.c:203: usbdma.priority = 1;
      000C6E 90 F1 78         [24] 1574 	mov	dptr,#(_usbdma + 0x0007)
      000C71 E0               [24] 1575 	movx	a,@dptr
      000C72 54 FC            [12] 1576 	anl	a,#0xFC
      000C74 44 01            [12] 1577 	orl	a,#0x01
      000C76 F0               [24] 1578 	movx	@dptr,a
                                   1579 ;	cc1111usb.c:214: USBPOW &= ~USBPOW_SUSPEND_EN;           // i don't *wanna* go to sleep if the usb bus is idle for 3ms.  at least not yet.
      000C77 90 DE 01         [24] 1580 	mov	dptr,#_USBPOW
      000C7A E0               [24] 1581 	movx	a,@dptr
      000C7B FF               [12] 1582 	mov	r7,a
      000C7C 74 FE            [12] 1583 	mov	a,#0xFE
      000C7E 5F               [12] 1584 	anl	a,r7
      000C7F F0               [24] 1585 	movx	@dptr,a
                                   1586 ;	cc1111usb.c:216: usb_data.config = 0;                    // start out unconfigured
                                   1587 ;	cc1111usb.c:217: usb_data.event = 0;
      000C80 E4               [12] 1588 	clr	a
      000C81 F5 25            [12] 1589 	mov	(_usb_data + 0x0003),a
      000C83 F5 23            [12] 1590 	mov	((_usb_data + 0x0001) + 0),a
      000C85 F5 24            [12] 1591 	mov	((_usb_data + 0x0001) + 1),a
                                   1592 ;	cc1111usb.c:218: usb_data.usbstatus  = USB_STATE_IDLE;   // this tracks the status of our USB Controller
                                   1593 ;	1-genFromRTrack replaced	mov	_usb_data,#0x00
      000C87 F5 22            [12] 1594 	mov	_usb_data,a
                                   1595 ;	cc1111usb.c:222: USBINDEX = 0;
      000C89 90 DE 0E         [24] 1596 	mov	dptr,#_USBINDEX
      000C8C F0               [24] 1597 	movx	@dptr,a
                                   1598 ;	cc1111usb.c:223: USBMAXI  = (EP0_MAX_PACKET_SIZE+7)>>3;      // these registers live in incrememnts of 8 bytes.  
      000C8D 90 DE 10         [24] 1599 	mov	dptr,#_USBMAXI
      000C90 74 08            [12] 1600 	mov	a,#0x08
      000C92 F0               [24] 1601 	movx	@dptr,a
                                   1602 ;	cc1111usb.c:224: USBMAXO  = (EP0_MAX_PACKET_SIZE+7)>>3;      // these registers live in incrememnts of 8 bytes.  
      000C93 90 DE 13         [24] 1603 	mov	dptr,#_USBMAXO
      000C96 F0               [24] 1604 	movx	@dptr,a
                                   1605 ;	cc1111usb.c:225: ep0iobuf.epstatus   =  EP_STATE_IDLE;       // this tracks the status of our endpoint 0
      000C97 90 F1 61         [24] 1606 	mov	dptr,#(_ep0iobuf + 0x000d)
      000C9A E4               [12] 1607 	clr	a
      000C9B F0               [24] 1608 	movx	@dptr,a
                                   1609 ;	cc1111usb.c:226: ep0iobuf.flags      =  0;                   // reset flags for the OUT (recv) buffer
      000C9C 90 F1 60         [24] 1610 	mov	dptr,#(_ep0iobuf + 0x000c)
      000C9F F0               [24] 1611 	movx	@dptr,a
                                   1612 ;	cc1111usb.c:227: ep0iobuf.INbytesleft=  0;
      000CA0 90 F1 57         [24] 1613 	mov	dptr,#(_ep0iobuf + 0x0003)
      000CA3 F0               [24] 1614 	movx	@dptr,a
      000CA4 A3               [24] 1615 	inc	dptr
      000CA5 F0               [24] 1616 	movx	@dptr,a
                                   1617 ;	cc1111usb.c:228: ep0iobuf.OUTbuf     =  &usb_ep0_OUTbuf[0];
      000CA6 90 F1 59         [24] 1618 	mov	dptr,#(_ep0iobuf + 0x0005)
      000CA9 74 D4            [12] 1619 	mov	a,#_usb_ep0_OUTbuf
      000CAB F0               [24] 1620 	movx	@dptr,a
      000CAC 74 F0            [12] 1621 	mov	a,#(_usb_ep0_OUTbuf >> 8)
      000CAE A3               [24] 1622 	inc	dptr
      000CAF F0               [24] 1623 	movx	@dptr,a
      000CB0 E4               [12] 1624 	clr	a
      000CB1 A3               [24] 1625 	inc	dptr
      000CB2 F0               [24] 1626 	movx	@dptr,a
                                   1627 ;	cc1111usb.c:229: ep0iobuf.OUTlen     =  0;
      000CB3 90 F1 5C         [24] 1628 	mov	dptr,#(_ep0iobuf + 0x0008)
      000CB6 F0               [24] 1629 	movx	@dptr,a
      000CB7 A3               [24] 1630 	inc	dptr
      000CB8 F0               [24] 1631 	movx	@dptr,a
                                   1632 ;	cc1111usb.c:230: ep0iobuf.BUFmaxlen  =  EP0_MAX_PACKET_SIZE;
      000CB9 90 F1 5E         [24] 1633 	mov	dptr,#(_ep0iobuf + 0x000a)
      000CBC 74 40            [12] 1634 	mov	a,#0x40
      000CBE F0               [24] 1635 	movx	@dptr,a
      000CBF E4               [12] 1636 	clr	a
      000CC0 A3               [24] 1637 	inc	dptr
      000CC1 F0               [24] 1638 	movx	@dptr,a
                                   1639 ;	cc1111usb.c:234: USBINDEX = 5;
      000CC2 90 DE 0E         [24] 1640 	mov	dptr,#_USBINDEX
      000CC5 74 05            [12] 1641 	mov	a,#0x05
      000CC7 F0               [24] 1642 	movx	@dptr,a
                                   1643 ;	cc1111usb.c:235: USBMAXI  = (EP5IN_MAX_PACKET_SIZE+7)>>3;    // these registers live in incrememnts of 8 bytes.  
      000CC8 90 DE 10         [24] 1644 	mov	dptr,#_USBMAXI
      000CCB 74 3F            [12] 1645 	mov	a,#0x3F
      000CCD F0               [24] 1646 	movx	@dptr,a
                                   1647 ;	cc1111usb.c:236: USBMAXO  = (EP5OUT_MAX_PACKET_SIZE+7)>>3;   // these registers live in incrememnts of 8 bytes.  
      000CCE 90 DE 13         [24] 1648 	mov	dptr,#_USBMAXO
      000CD1 74 08            [12] 1649 	mov	a,#0x08
      000CD3 F0               [24] 1650 	movx	@dptr,a
                                   1651 ;	cc1111usb.c:237: USBCSOH |= USBCSOH_AUTOCLEAR;               // when we drain the FIFO, automagically tell host
      000CD4 90 DE 15         [24] 1652 	mov	dptr,#_USBCSOH
      000CD7 E0               [24] 1653 	movx	a,@dptr
      000CD8 FF               [12] 1654 	mov	r7,a
      000CD9 74 80            [12] 1655 	mov	a,#0x80
      000CDB 4F               [12] 1656 	orl	a,r7
      000CDC F0               [24] 1657 	movx	@dptr,a
                                   1658 ;	cc1111usb.c:238: USBCSIH |= USBCSIH_AUTOSET;                 // when the buffer is full, automagically tell host
      000CDD 90 DE 12         [24] 1659 	mov	dptr,#_USBCSIH
      000CE0 E0               [24] 1660 	movx	a,@dptr
      000CE1 FF               [12] 1661 	mov	r7,a
      000CE2 74 80            [12] 1662 	mov	a,#0x80
      000CE4 4F               [12] 1663 	orl	a,r7
      000CE5 F0               [24] 1664 	movx	@dptr,a
                                   1665 ;	cc1111usb.c:239: ep5iobuf.epstatus   =  EP_STATE_IDLE;       // this tracks the status of our endpoint 5
      000CE6 90 F1 6F         [24] 1666 	mov	dptr,#(_ep5iobuf + 0x000d)
      000CE9 E4               [12] 1667 	clr	a
      000CEA F0               [24] 1668 	movx	@dptr,a
                                   1669 ;	cc1111usb.c:240: ep5iobuf.flags      =  0;
      000CEB 90 F1 6E         [24] 1670 	mov	dptr,#(_ep5iobuf + 0x000c)
      000CEE F0               [24] 1671 	movx	@dptr,a
                                   1672 ;	cc1111usb.c:241: ep5iobuf.INbytesleft=  0;
      000CEF 90 F1 65         [24] 1673 	mov	dptr,#(_ep5iobuf + 0x0003)
      000CF2 F0               [24] 1674 	movx	@dptr,a
      000CF3 A3               [24] 1675 	inc	dptr
      000CF4 F0               [24] 1676 	movx	@dptr,a
                                   1677 ;	cc1111usb.c:242: ep5iobuf.OUTbuf     =  &usb_ep5_OUTbuf[0];
      000CF5 90 F1 67         [24] 1678 	mov	dptr,#(_ep5iobuf + 0x0005)
      000CF8 74 14            [12] 1679 	mov	a,#_usb_ep5_OUTbuf
      000CFA F0               [24] 1680 	movx	@dptr,a
      000CFB 74 F1            [12] 1681 	mov	a,#(_usb_ep5_OUTbuf >> 8)
      000CFD A3               [24] 1682 	inc	dptr
      000CFE F0               [24] 1683 	movx	@dptr,a
      000CFF E4               [12] 1684 	clr	a
      000D00 A3               [24] 1685 	inc	dptr
      000D01 F0               [24] 1686 	movx	@dptr,a
                                   1687 ;	cc1111usb.c:243: ep5iobuf.OUTlen     =  0;
      000D02 90 F1 6A         [24] 1688 	mov	dptr,#(_ep5iobuf + 0x0008)
      000D05 F0               [24] 1689 	movx	@dptr,a
      000D06 A3               [24] 1690 	inc	dptr
      000D07 F0               [24] 1691 	movx	@dptr,a
                                   1692 ;	cc1111usb.c:244: ep5iobuf.BUFmaxlen  =  EP5OUT_MAX_PACKET_SIZE;
      000D08 90 F1 6C         [24] 1693 	mov	dptr,#(_ep5iobuf + 0x000a)
      000D0B 74 40            [12] 1694 	mov	a,#0x40
      000D0D F0               [24] 1695 	movx	@dptr,a
      000D0E E4               [12] 1696 	clr	a
      000D0F A3               [24] 1697 	inc	dptr
      000D10 F0               [24] 1698 	movx	@dptr,a
                                   1699 ;	cc1111usb.c:249: USBCIE = 0xf7;          // skip Start Of Frame (SOFIF).  it's basically a keep-alive packet to keep the device from entering SUSPEND.  
      000D11 90 DE 0B         [24] 1700 	mov	dptr,#_USBCIE
      000D14 74 F7            [12] 1701 	mov	a,#0xF7
      000D16 F0               [24] 1702 	movx	@dptr,a
                                   1703 ;	cc1111usb.c:250: USBIIE = 0xff;
      000D17 90 DE 07         [24] 1704 	mov	dptr,#_USBIIE
      000D1A 74 FF            [12] 1705 	mov	a,#0xFF
      000D1C F0               [24] 1706 	movx	@dptr,a
                                   1707 ;	cc1111usb.c:251: USBOIE = 0xff;
      000D1D 90 DE 09         [24] 1708 	mov	dptr,#_USBOIE
      000D20 F0               [24] 1709 	movx	@dptr,a
                                   1710 ;	cc1111usb.c:254: PICTL   |= PICTL_P0IENH;                // must have this enabled to resume from suspend
      000D21 43 8C 10         [24] 1711 	orl	_PICTL,#0x10
                                   1712 ;	cc1111usb.c:255: PICTL   &= ~PICTL_P0ICON;               // enable interrupts on rising edge
      000D24 AF 8C            [24] 1713 	mov	r7,_PICTL
      000D26 74 FE            [12] 1714 	mov	a,#0xFE
      000D28 5F               [12] 1715 	anl	a,r7
      000D29 F5 8C            [12] 1716 	mov	_PICTL,a
                                   1717 ;	cc1111usb.c:256: P0IE    = 1;                            // enable the p0 interrupt flag  (IEN1 is bit-accessible)
      000D2B D2 BD            [12] 1718 	setb	_P0IE
                                   1719 ;	cc1111usb.c:257: IEN2    |= IEN2_USBIE;                  // enable the USB interrupt flag (IEN2 is *not* bit-accessible)
      000D2D 43 9A 02         [24] 1720 	orl	_IEN2,#0x02
                                   1721 ;	cc1111usb.c:259: USB_RESUME_INT_CLEAR();                 // P0IFG= 0; P0IF= 0
      000D30 75 89 00         [24] 1722 	mov	_P0IFG,#0x00
      000D33 C2 C5            [12] 1723 	clr	_P0IF
                                   1724 ;	cc1111usb.c:260: USB_INT_CLEAR();                        // P2IFG= 0; P2IF= 0;
      000D35 75 8B 00         [24] 1725 	mov	_P2IFG,#0x00
      000D38 C2 E8            [12] 1726 	clr	_P2IF
                                   1727 ;	cc1111usb.c:263: USB_INT_ENABLE();     // Enables USB Interrupts to call an ISR
      000D3A 43 9A 02         [24] 1728 	orl	_IEN2,#0x02
      000D3D 22               [24] 1729 	ret
                                   1730 ;------------------------------------------------------------
                                   1731 ;Allocation info for local variables in function 'initUSB'
                                   1732 ;------------------------------------------------------------
                                   1733 ;	cc1111usb.c:273: void initUSB(void)
                                   1734 ;	-----------------------------------------
                                   1735 ;	 function initUSB
                                   1736 ;	-----------------------------------------
      000D3E                       1737 _initUSB:
                                   1738 ;	cc1111usb.c:275: lastCode[0] = 2;
      000D3E 90 F0 D2         [24] 1739 	mov	dptr,#_lastCode
      000D41 74 02            [12] 1740 	mov	a,#0x02
      000D43 F0               [24] 1741 	movx	@dptr,a
                                   1742 ;	cc1111usb.c:276: USB_ENABLE();                       // enable our usb controller
      000D44 43 BE 80         [24] 1743 	orl	_SLEEP,#0x80
                                   1744 ;	cc1111usb.c:277: usb_init();                         // setup the usb controller settings
      000D47 02 0C 28         [24] 1745 	ljmp	_usb_init
                                   1746 ;------------------------------------------------------------
                                   1747 ;Allocation info for local variables in function 'usb_up'
                                   1748 ;------------------------------------------------------------
                                   1749 ;	cc1111usb.c:282: void usb_up(void)
                                   1750 ;	-----------------------------------------
                                   1751 ;	 function usb_up
                                   1752 ;	-----------------------------------------
      000D4A                       1753 _usb_up:
                                   1754 ;	cc1111usb.c:284: USB_PULLUP_ENABLE();                // enable pullup resistor indicating that we are a real usb device
      000D4A D2 90            [12] 1755 	setb	_P1_0
      000D4C 22               [24] 1756 	ret
                                   1757 ;------------------------------------------------------------
                                   1758 ;Allocation info for local variables in function 'usb_down'
                                   1759 ;------------------------------------------------------------
                                   1760 ;	cc1111usb.c:288: void usb_down(void)
                                   1761 ;	-----------------------------------------
                                   1762 ;	 function usb_down
                                   1763 ;	-----------------------------------------
      000D4D                       1764 _usb_down:
                                   1765 ;	cc1111usb.c:290: USB_PULLUP_DISABLE();                // enable pullup resistor indicating that we are a real usb device
      000D4D C2 90            [12] 1766 	clr	_P1_0
      000D4F 22               [24] 1767 	ret
                                   1768 ;------------------------------------------------------------
                                   1769 ;Allocation info for local variables in function 'setup_send_ep0'
                                   1770 ;------------------------------------------------------------
                                   1771 ;length                    Allocated with name '_setup_send_ep0_PARM_2'
                                   1772 ;payload                   Allocated to registers r5 r6 r7 
                                   1773 ;------------------------------------------------------------
                                   1774 ;	cc1111usb.c:296: int setup_send_ep0(u8* payload, u16 length)
                                   1775 ;	-----------------------------------------
                                   1776 ;	 function setup_send_ep0
                                   1777 ;	-----------------------------------------
      000D50                       1778 _setup_send_ep0:
      000D50 AD 82            [24] 1779 	mov	r5,dpl
      000D52 AE 83            [24] 1780 	mov	r6,dph
      000D54 AF F0            [24] 1781 	mov	r7,b
                                   1782 ;	cc1111usb.c:298: if (ep0iobuf.epstatus != EP_STATE_IDLE)
      000D56 90 F1 61         [24] 1783 	mov	dptr,#(_ep0iobuf + 0x000d)
      000D59 E0               [24] 1784 	movx	a,@dptr
      000D5A 60 34            [24] 1785 	jz	00102$
                                   1786 ;	cc1111usb.c:301: blink(1000,1000);
      000D5C D2 90            [12] 1787 	setb	_P1_0
      000D5E 90 03 E8         [24] 1788 	mov	dptr,#0x03E8
      000D61 12 09 63         [24] 1789 	lcall	_sleepMillis
      000D64 C2 90            [12] 1790 	clr	_P1_0
      000D66 90 03 E8         [24] 1791 	mov	dptr,#0x03E8
      000D69 12 09 63         [24] 1792 	lcall	_sleepMillis
                                   1793 ;	cc1111usb.c:302: blink(1000,1000);
      000D6C D2 90            [12] 1794 	setb	_P1_0
      000D6E 90 03 E8         [24] 1795 	mov	dptr,#0x03E8
      000D71 12 09 63         [24] 1796 	lcall	_sleepMillis
      000D74 C2 90            [12] 1797 	clr	_P1_0
      000D76 90 03 E8         [24] 1798 	mov	dptr,#0x03E8
      000D79 12 09 63         [24] 1799 	lcall	_sleepMillis
                                   1800 ;	cc1111usb.c:303: blink(1000,1000);
      000D7C D2 90            [12] 1801 	setb	_P1_0
      000D7E 90 03 E8         [24] 1802 	mov	dptr,#0x03E8
      000D81 12 09 63         [24] 1803 	lcall	_sleepMillis
      000D84 C2 90            [12] 1804 	clr	_P1_0
      000D86 90 03 E8         [24] 1805 	mov	dptr,#0x03E8
      000D89 12 09 63         [24] 1806 	lcall	_sleepMillis
                                   1807 ;	cc1111usb.c:304: return -1;
      000D8C 90 FF FF         [24] 1808 	mov	dptr,#0xFFFF
      000D8F 22               [24] 1809 	ret
      000D90                       1810 00102$:
                                   1811 ;	cc1111usb.c:307: ep0iobuf.INbuf = payload;
      000D90 90 F1 54         [24] 1812 	mov	dptr,#_ep0iobuf
      000D93 ED               [12] 1813 	mov	a,r5
      000D94 F0               [24] 1814 	movx	@dptr,a
      000D95 EE               [12] 1815 	mov	a,r6
      000D96 A3               [24] 1816 	inc	dptr
      000D97 F0               [24] 1817 	movx	@dptr,a
      000D98 EF               [12] 1818 	mov	a,r7
      000D99 A3               [24] 1819 	inc	dptr
      000D9A F0               [24] 1820 	movx	@dptr,a
                                   1821 ;	cc1111usb.c:308: ep0iobuf.INbytesleft = length;
      000D9B 90 F1 57         [24] 1822 	mov	dptr,#(_ep0iobuf + 0x0003)
      000D9E E5 31            [12] 1823 	mov	a,_setup_send_ep0_PARM_2
      000DA0 F0               [24] 1824 	movx	@dptr,a
      000DA1 E5 32            [12] 1825 	mov	a,(_setup_send_ep0_PARM_2 + 1)
      000DA3 A3               [24] 1826 	inc	dptr
      000DA4 F0               [24] 1827 	movx	@dptr,a
                                   1828 ;	cc1111usb.c:309: ep0iobuf.epstatus = EP_STATE_TX;
      000DA5 90 F1 61         [24] 1829 	mov	dptr,#(_ep0iobuf + 0x000d)
      000DA8 74 01            [12] 1830 	mov	a,#0x01
      000DAA F0               [24] 1831 	movx	@dptr,a
                                   1832 ;	cc1111usb.c:311: return 0;
      000DAB 90 00 00         [24] 1833 	mov	dptr,#0x0000
      000DAE 22               [24] 1834 	ret
                                   1835 ;------------------------------------------------------------
                                   1836 ;Allocation info for local variables in function 'setup_sendx_ep0'
                                   1837 ;------------------------------------------------------------
                                   1838 ;length                    Allocated with name '_setup_sendx_ep0_PARM_2'
                                   1839 ;payload                   Allocated to registers r6 r7 
                                   1840 ;------------------------------------------------------------
                                   1841 ;	cc1111usb.c:315: int setup_sendx_ep0(__xdata u8* payload, u16 length)
                                   1842 ;	-----------------------------------------
                                   1843 ;	 function setup_sendx_ep0
                                   1844 ;	-----------------------------------------
      000DAF                       1845 _setup_sendx_ep0:
      000DAF AE 82            [24] 1846 	mov	r6,dpl
      000DB1 AF 83            [24] 1847 	mov	r7,dph
                                   1848 ;	cc1111usb.c:317: if (ep0iobuf.epstatus != EP_STATE_IDLE)
      000DB3 90 F1 61         [24] 1849 	mov	dptr,#(_ep0iobuf + 0x000d)
      000DB6 E0               [24] 1850 	movx	a,@dptr
      000DB7 60 34            [24] 1851 	jz	00102$
                                   1852 ;	cc1111usb.c:320: blink(1000,1000);
      000DB9 D2 90            [12] 1853 	setb	_P1_0
      000DBB 90 03 E8         [24] 1854 	mov	dptr,#0x03E8
      000DBE 12 09 63         [24] 1855 	lcall	_sleepMillis
      000DC1 C2 90            [12] 1856 	clr	_P1_0
      000DC3 90 03 E8         [24] 1857 	mov	dptr,#0x03E8
      000DC6 12 09 63         [24] 1858 	lcall	_sleepMillis
                                   1859 ;	cc1111usb.c:321: blink(1000,1000);
      000DC9 D2 90            [12] 1860 	setb	_P1_0
      000DCB 90 03 E8         [24] 1861 	mov	dptr,#0x03E8
      000DCE 12 09 63         [24] 1862 	lcall	_sleepMillis
      000DD1 C2 90            [12] 1863 	clr	_P1_0
      000DD3 90 03 E8         [24] 1864 	mov	dptr,#0x03E8
      000DD6 12 09 63         [24] 1865 	lcall	_sleepMillis
                                   1866 ;	cc1111usb.c:322: blink(1000,1000);
      000DD9 D2 90            [12] 1867 	setb	_P1_0
      000DDB 90 03 E8         [24] 1868 	mov	dptr,#0x03E8
      000DDE 12 09 63         [24] 1869 	lcall	_sleepMillis
      000DE1 C2 90            [12] 1870 	clr	_P1_0
      000DE3 90 03 E8         [24] 1871 	mov	dptr,#0x03E8
      000DE6 12 09 63         [24] 1872 	lcall	_sleepMillis
                                   1873 ;	cc1111usb.c:323: return -1;
      000DE9 90 FF FF         [24] 1874 	mov	dptr,#0xFFFF
      000DEC 22               [24] 1875 	ret
      000DED                       1876 00102$:
                                   1877 ;	cc1111usb.c:326: ep0iobuf.INbuf = payload;
      000DED 7D 00            [12] 1878 	mov	r5,#0x00
      000DEF 90 F1 54         [24] 1879 	mov	dptr,#_ep0iobuf
      000DF2 EE               [12] 1880 	mov	a,r6
      000DF3 F0               [24] 1881 	movx	@dptr,a
      000DF4 EF               [12] 1882 	mov	a,r7
      000DF5 A3               [24] 1883 	inc	dptr
      000DF6 F0               [24] 1884 	movx	@dptr,a
      000DF7 ED               [12] 1885 	mov	a,r5
      000DF8 A3               [24] 1886 	inc	dptr
      000DF9 F0               [24] 1887 	movx	@dptr,a
                                   1888 ;	cc1111usb.c:327: ep0iobuf.INbytesleft = length;
      000DFA 90 F1 57         [24] 1889 	mov	dptr,#(_ep0iobuf + 0x0003)
      000DFD E5 33            [12] 1890 	mov	a,_setup_sendx_ep0_PARM_2
      000DFF F0               [24] 1891 	movx	@dptr,a
      000E00 E5 34            [12] 1892 	mov	a,(_setup_sendx_ep0_PARM_2 + 1)
      000E02 A3               [24] 1893 	inc	dptr
      000E03 F0               [24] 1894 	movx	@dptr,a
                                   1895 ;	cc1111usb.c:328: ep0iobuf.epstatus = EP_STATE_TX;
      000E04 90 F1 61         [24] 1896 	mov	dptr,#(_ep0iobuf + 0x000d)
      000E07 74 01            [12] 1897 	mov	a,#0x01
      000E09 F0               [24] 1898 	movx	@dptr,a
                                   1899 ;	cc1111usb.c:330: return 0;
      000E0A 90 00 00         [24] 1900 	mov	dptr,#0x0000
      000E0D 22               [24] 1901 	ret
                                   1902 ;------------------------------------------------------------
                                   1903 ;Allocation info for local variables in function 'usb_arm_ep0IN'
                                   1904 ;------------------------------------------------------------
                                   1905 ;tlen                      Allocated to registers r4 
                                   1906 ;csReg                     Allocated to registers r7 
                                   1907 ;------------------------------------------------------------
                                   1908 ;	cc1111usb.c:347: void usb_arm_ep0IN(){
                                   1909 ;	-----------------------------------------
                                   1910 ;	 function usb_arm_ep0IN
                                   1911 ;	-----------------------------------------
      000E0E                       1912 _usb_arm_ep0IN:
                                   1913 ;	cc1111usb.c:352: u8  csReg = USBCS0_INPKT_RDY;
      000E0E 7F 02            [12] 1914 	mov	r7,#0x02
                                   1915 ;	cc1111usb.c:354: USBINDEX = 0;
      000E10 90 DE 0E         [24] 1916 	mov	dptr,#_USBINDEX
      000E13 E4               [12] 1917 	clr	a
      000E14 F0               [24] 1918 	movx	@dptr,a
                                   1919 ;	cc1111usb.c:356: if (ep0iobuf.INbytesleft > EP0_MAX_PACKET_SIZE)
      000E15 90 F1 57         [24] 1920 	mov	dptr,#(_ep0iobuf + 0x0003)
      000E18 E0               [24] 1921 	movx	a,@dptr
      000E19 FD               [12] 1922 	mov	r5,a
      000E1A A3               [24] 1923 	inc	dptr
      000E1B E0               [24] 1924 	movx	a,@dptr
      000E1C FE               [12] 1925 	mov	r6,a
      000E1D C3               [12] 1926 	clr	c
      000E1E 74 40            [12] 1927 	mov	a,#0x40
      000E20 9D               [12] 1928 	subb	a,r5
      000E21 E4               [12] 1929 	clr	a
      000E22 9E               [12] 1930 	subb	a,r6
      000E23 50 04            [24] 1931 	jnc	00102$
                                   1932 ;	cc1111usb.c:357: tlen = EP0_MAX_PACKET_SIZE;
      000E25 7C 40            [12] 1933 	mov	r4,#0x40
      000E27 80 04            [24] 1934 	sjmp	00103$
      000E29                       1935 00102$:
                                   1936 ;	cc1111usb.c:360: tlen = ep0iobuf.INbytesleft;
      000E29 8D 04            [24] 1937 	mov	ar4,r5
                                   1938 ;	cc1111usb.c:361: csReg |= USBCS0_DATA_END;
      000E2B 7F 0A            [12] 1939 	mov	r7,#0x0A
      000E2D                       1940 00103$:
                                   1941 ;	cc1111usb.c:365: ep0iobuf.INbytesleft -= tlen;
      000E2D 8C 02            [24] 1942 	mov	ar2,r4
      000E2F 7B 00            [12] 1943 	mov	r3,#0x00
      000E31 ED               [12] 1944 	mov	a,r5
      000E32 C3               [12] 1945 	clr	c
      000E33 9A               [12] 1946 	subb	a,r2
      000E34 FD               [12] 1947 	mov	r5,a
      000E35 EE               [12] 1948 	mov	a,r6
      000E36 9B               [12] 1949 	subb	a,r3
      000E37 FE               [12] 1950 	mov	r6,a
      000E38 90 F1 57         [24] 1951 	mov	dptr,#(_ep0iobuf + 0x0003)
      000E3B ED               [12] 1952 	mov	a,r5
      000E3C F0               [24] 1953 	movx	@dptr,a
      000E3D EE               [12] 1954 	mov	a,r6
      000E3E A3               [24] 1955 	inc	dptr
      000E3F F0               [24] 1956 	movx	@dptr,a
      000E40 8C 06            [24] 1957 	mov	ar6,r4
      000E42                       1958 00108$:
                                   1959 ;	cc1111usb.c:366: for (; tlen>0; tlen--) {               // FIXME: Use DMA
      000E42 EE               [12] 1960 	mov	a,r6
      000E43 60 36            [24] 1961 	jz	00104$
                                   1962 ;	cc1111usb.c:367: USBF0 = *ep0iobuf.INbuf;
      000E45 90 F1 54         [24] 1963 	mov	dptr,#_ep0iobuf
      000E48 E0               [24] 1964 	movx	a,@dptr
      000E49 FB               [12] 1965 	mov	r3,a
      000E4A A3               [24] 1966 	inc	dptr
      000E4B E0               [24] 1967 	movx	a,@dptr
      000E4C FC               [12] 1968 	mov	r4,a
      000E4D A3               [24] 1969 	inc	dptr
      000E4E E0               [24] 1970 	movx	a,@dptr
      000E4F FD               [12] 1971 	mov	r5,a
      000E50 8B 82            [24] 1972 	mov	dpl,r3
      000E52 8C 83            [24] 1973 	mov	dph,r4
      000E54 8D F0            [24] 1974 	mov	b,r5
      000E56 12 1A 67         [24] 1975 	lcall	__gptrget
      000E59 90 DE 20         [24] 1976 	mov	dptr,#_USBF0
      000E5C F0               [24] 1977 	movx	@dptr,a
                                   1978 ;	cc1111usb.c:368: ep0iobuf.INbuf++;
      000E5D 90 F1 54         [24] 1979 	mov	dptr,#_ep0iobuf
      000E60 E0               [24] 1980 	movx	a,@dptr
      000E61 FB               [12] 1981 	mov	r3,a
      000E62 A3               [24] 1982 	inc	dptr
      000E63 E0               [24] 1983 	movx	a,@dptr
      000E64 FC               [12] 1984 	mov	r4,a
      000E65 A3               [24] 1985 	inc	dptr
      000E66 E0               [24] 1986 	movx	a,@dptr
      000E67 FD               [12] 1987 	mov	r5,a
      000E68 0B               [12] 1988 	inc	r3
      000E69 BB 00 01         [24] 1989 	cjne	r3,#0x00,00129$
      000E6C 0C               [12] 1990 	inc	r4
      000E6D                       1991 00129$:
      000E6D 90 F1 54         [24] 1992 	mov	dptr,#_ep0iobuf
      000E70 EB               [12] 1993 	mov	a,r3
      000E71 F0               [24] 1994 	movx	@dptr,a
      000E72 EC               [12] 1995 	mov	a,r4
      000E73 A3               [24] 1996 	inc	dptr
      000E74 F0               [24] 1997 	movx	@dptr,a
      000E75 ED               [12] 1998 	mov	a,r5
      000E76 A3               [24] 1999 	inc	dptr
      000E77 F0               [24] 2000 	movx	@dptr,a
                                   2001 ;	cc1111usb.c:366: for (; tlen>0; tlen--) {               // FIXME: Use DMA
      000E78 1E               [12] 2002 	dec	r6
      000E79 80 C7            [24] 2003 	sjmp	00108$
      000E7B                       2004 00104$:
                                   2005 ;	cc1111usb.c:370: USBCS0  |= csReg;
      000E7B 90 DE 11         [24] 2006 	mov	dptr,#_USBCS0
      000E7E E0               [24] 2007 	movx	a,@dptr
      000E7F 4F               [12] 2008 	orl	a,r7
      000E80 F0               [24] 2009 	movx	@dptr,a
                                   2010 ;	cc1111usb.c:371: if (ep0iobuf.INbytesleft == 0)
      000E81 90 F1 57         [24] 2011 	mov	dptr,#(_ep0iobuf + 0x0003)
      000E84 E0               [24] 2012 	movx	a,@dptr
      000E85 FE               [12] 2013 	mov	r6,a
      000E86 A3               [24] 2014 	inc	dptr
      000E87 E0               [24] 2015 	movx	a,@dptr
      000E88 FF               [12] 2016 	mov	r7,a
      000E89 4E               [12] 2017 	orl	a,r6
      000E8A 70 05            [24] 2018 	jnz	00110$
                                   2019 ;	cc1111usb.c:372: ep0iobuf.epstatus = EP_STATE_IDLE;
      000E8C 90 F1 61         [24] 2020 	mov	dptr,#(_ep0iobuf + 0x000d)
      000E8F E4               [12] 2021 	clr	a
      000E90 F0               [24] 2022 	movx	@dptr,a
      000E91                       2023 00110$:
      000E91 22               [24] 2024 	ret
                                   2025 ;------------------------------------------------------------
                                   2026 ;Allocation info for local variables in function 'setup_recv_ep0'
                                   2027 ;------------------------------------------------------------
                                   2028 ;	cc1111usb.c:376: u8 setup_recv_ep0(){
                                   2029 ;	-----------------------------------------
                                   2030 ;	 function setup_recv_ep0
                                   2031 ;	-----------------------------------------
      000E92                       2032 _setup_recv_ep0:
                                   2033 ;	cc1111usb.c:377: ep0iobuf.epstatus = EP_STATE_RX;
      000E92 90 F1 61         [24] 2034 	mov	dptr,#(_ep0iobuf + 0x000d)
      000E95 74 02            [12] 2035 	mov	a,#0x02
      000E97 F0               [24] 2036 	movx	@dptr,a
                                   2037 ;	cc1111usb.c:378: return 0;
      000E98 75 82 00         [24] 2038 	mov	dpl,#0x00
      000E9B 22               [24] 2039 	ret
                                   2040 ;------------------------------------------------------------
                                   2041 ;Allocation info for local variables in function 'usb_recv_ep0OUT'
                                   2042 ;------------------------------------------------------------
                                   2043 ;loop                      Allocated to registers 
                                   2044 ;payload                   Allocated to registers r5 r6 r7 
                                   2045 ;------------------------------------------------------------
                                   2046 ;	cc1111usb.c:381: u16 usb_recv_ep0OUT(){
                                   2047 ;	-----------------------------------------
                                   2048 ;	 function usb_recv_ep0OUT
                                   2049 ;	-----------------------------------------
      000E9C                       2050 _usb_recv_ep0OUT:
                                   2051 ;	cc1111usb.c:389: u8* payload = &ep0iobuf.OUTbuf[0];
      000E9C 90 F1 59         [24] 2052 	mov	dptr,#(_ep0iobuf + 0x0005)
      000E9F E0               [24] 2053 	movx	a,@dptr
      000EA0 FD               [12] 2054 	mov	r5,a
      000EA1 A3               [24] 2055 	inc	dptr
      000EA2 E0               [24] 2056 	movx	a,@dptr
      000EA3 FE               [12] 2057 	mov	r6,a
      000EA4 A3               [24] 2058 	inc	dptr
      000EA5 E0               [24] 2059 	movx	a,@dptr
      000EA6 FF               [12] 2060 	mov	r7,a
                                   2061 ;	cc1111usb.c:390: ep0iobuf.OUTlen = (u16)USBCNT0;
      000EA7 90 DE 16         [24] 2062 	mov	dptr,#_USBCNT0
      000EAA E0               [24] 2063 	movx	a,@dptr
      000EAB FC               [12] 2064 	mov	r4,a
      000EAC 7B 00            [12] 2065 	mov	r3,#0x00
      000EAE 90 F1 5C         [24] 2066 	mov	dptr,#(_ep0iobuf + 0x0008)
      000EB1 EC               [12] 2067 	mov	a,r4
      000EB2 F0               [24] 2068 	movx	@dptr,a
      000EB3 EB               [12] 2069 	mov	a,r3
      000EB4 A3               [24] 2070 	inc	dptr
      000EB5 F0               [24] 2071 	movx	@dptr,a
                                   2072 ;	cc1111usb.c:392: if (ep0iobuf.flags & EP_OUTBUF_WRITTEN)
      000EB6 90 F1 60         [24] 2073 	mov	dptr,#(_ep0iobuf + 0x000c)
      000EB9 E0               [24] 2074 	movx	a,@dptr
      000EBA FC               [12] 2075 	mov	r4,a
      000EBB 30 E1 0A         [24] 2076 	jnb	acc.1,00102$
                                   2077 ;	cc1111usb.c:394: ep0iobuf.epstatus = EP_STATE_STALL;            // FIXME: don't currently handle stall->idle...
      000EBE 90 F1 61         [24] 2078 	mov	dptr,#(_ep0iobuf + 0x000d)
      000EC1 74 03            [12] 2079 	mov	a,#0x03
      000EC3 F0               [24] 2080 	movx	@dptr,a
                                   2081 ;	cc1111usb.c:395: return -1;
      000EC4 90 FF FF         [24] 2082 	mov	dptr,#0xFFFF
      000EC7 22               [24] 2083 	ret
      000EC8                       2084 00102$:
                                   2085 ;	cc1111usb.c:397: ep0iobuf.flags |= EP_OUTBUF_WRITTEN;            // hey, we've written here, don't write again until this is cleared by a application handler
      000EC8 90 F1 60         [24] 2086 	mov	dptr,#(_ep0iobuf + 0x000c)
      000ECB E0               [24] 2087 	movx	a,@dptr
      000ECC 44 02            [12] 2088 	orl	a,#0x02
      000ECE F0               [24] 2089 	movx	@dptr,a
                                   2090 ;	cc1111usb.c:399: if (ep0iobuf.OUTlen>EP0_MAX_PACKET_SIZE)
      000ECF 90 F1 5C         [24] 2091 	mov	dptr,#(_ep0iobuf + 0x0008)
      000ED2 E0               [24] 2092 	movx	a,@dptr
      000ED3 FB               [12] 2093 	mov	r3,a
      000ED4 A3               [24] 2094 	inc	dptr
      000ED5 E0               [24] 2095 	movx	a,@dptr
      000ED6 FC               [12] 2096 	mov	r4,a
      000ED7 C3               [12] 2097 	clr	c
      000ED8 74 40            [12] 2098 	mov	a,#0x40
      000EDA 9B               [12] 2099 	subb	a,r3
      000EDB E4               [12] 2100 	clr	a
      000EDC 9C               [12] 2101 	subb	a,r4
      000EDD 50 09            [24] 2102 	jnc	00104$
                                   2103 ;	cc1111usb.c:400: ep0iobuf.OUTlen = EP0_MAX_PACKET_SIZE;
      000EDF 90 F1 5C         [24] 2104 	mov	dptr,#(_ep0iobuf + 0x0008)
      000EE2 74 40            [12] 2105 	mov	a,#0x40
      000EE4 F0               [24] 2106 	movx	@dptr,a
      000EE5 E4               [12] 2107 	clr	a
      000EE6 A3               [24] 2108 	inc	dptr
      000EE7 F0               [24] 2109 	movx	@dptr,a
      000EE8                       2110 00104$:
                                   2111 ;	cc1111usb.c:403: for (loop=ep0iobuf.OUTlen; loop>0; loop--){
      000EE8 90 F1 5C         [24] 2112 	mov	dptr,#(_ep0iobuf + 0x0008)
      000EEB E0               [24] 2113 	movx	a,@dptr
      000EEC FB               [12] 2114 	mov	r3,a
      000EED A3               [24] 2115 	inc	dptr
      000EEE E0               [24] 2116 	movx	a,@dptr
      000EEF FC               [12] 2117 	mov	r4,a
      000EF0                       2118 00109$:
      000EF0 EB               [12] 2119 	mov	a,r3
      000EF1 4C               [12] 2120 	orl	a,r4
      000EF2 60 1A            [24] 2121 	jz	00105$
                                   2122 ;	cc1111usb.c:404: *payload = USBF0;
      000EF4 90 DE 20         [24] 2123 	mov	dptr,#_USBF0
      000EF7 E0               [24] 2124 	movx	a,@dptr
      000EF8 FA               [12] 2125 	mov	r2,a
      000EF9 8D 82            [24] 2126 	mov	dpl,r5
      000EFB 8E 83            [24] 2127 	mov	dph,r6
      000EFD 8F F0            [24] 2128 	mov	b,r7
      000EFF 12 1A 4C         [24] 2129 	lcall	__gptrput
      000F02 A3               [24] 2130 	inc	dptr
      000F03 AD 82            [24] 2131 	mov	r5,dpl
      000F05 AE 83            [24] 2132 	mov	r6,dph
                                   2133 ;	cc1111usb.c:405: payload++;
                                   2134 ;	cc1111usb.c:403: for (loop=ep0iobuf.OUTlen; loop>0; loop--){
      000F07 1B               [12] 2135 	dec	r3
      000F08 BB FF 01         [24] 2136 	cjne	r3,#0xFF,00134$
      000F0B 1C               [12] 2137 	dec	r4
      000F0C                       2138 00134$:
      000F0C 80 E2            [24] 2139 	sjmp	00109$
      000F0E                       2140 00105$:
                                   2141 ;	cc1111usb.c:409: if (ep0iobuf.OUTlen < EP0_MAX_PACKET_SIZE)
      000F0E 90 F1 5C         [24] 2142 	mov	dptr,#(_ep0iobuf + 0x0008)
      000F11 E0               [24] 2143 	movx	a,@dptr
      000F12 FE               [12] 2144 	mov	r6,a
      000F13 A3               [24] 2145 	inc	dptr
      000F14 E0               [24] 2146 	movx	a,@dptr
      000F15 FF               [12] 2147 	mov	r7,a
      000F16 C3               [12] 2148 	clr	c
      000F17 EE               [12] 2149 	mov	a,r6
      000F18 94 40            [12] 2150 	subb	a,#0x40
      000F1A EF               [12] 2151 	mov	a,r7
      000F1B 94 00            [12] 2152 	subb	a,#0x00
      000F1D 50 03            [24] 2153 	jnc	00107$
                                   2154 ;	cc1111usb.c:410: appHandleEP0OUTdone();
      000F1F 12 01 8F         [24] 2155 	lcall	_appHandleEP0OUTdone
      000F22                       2156 00107$:
                                   2157 ;	cc1111usb.c:411: return ep0iobuf.OUTlen;
      000F22 90 F1 5C         [24] 2158 	mov	dptr,#(_ep0iobuf + 0x0008)
      000F25 E0               [24] 2159 	movx	a,@dptr
      000F26 FE               [12] 2160 	mov	r6,a
      000F27 A3               [24] 2161 	inc	dptr
      000F28 E0               [24] 2162 	movx	a,@dptr
      000F29 8E 82            [24] 2163 	mov	dpl,r6
      000F2B F5 83            [12] 2164 	mov	dph,a
      000F2D 22               [24] 2165 	ret
                                   2166 ;------------------------------------------------------------
                                   2167 ;Allocation info for local variables in function 'usbGetConfiguration'
                                   2168 ;------------------------------------------------------------
                                   2169 ;	cc1111usb.c:472: void usbGetConfiguration()
                                   2170 ;	-----------------------------------------
                                   2171 ;	 function usbGetConfiguration
                                   2172 ;	-----------------------------------------
      000F2E                       2173 _usbGetConfiguration:
                                   2174 ;	cc1111usb.c:474: setup_send_ep0(&usb_data.config, 1);
      000F2E 75 31 01         [24] 2175 	mov	_setup_send_ep0_PARM_2,#0x01
      000F31 75 32 00         [24] 2176 	mov	(_setup_send_ep0_PARM_2 + 1),#0x00
      000F34 90 00 25         [24] 2177 	mov	dptr,#(_usb_data + 0x0003)
      000F37 75 F0 40         [24] 2178 	mov	b,#0x40
      000F3A 02 0D 50         [24] 2179 	ljmp	_setup_send_ep0
                                   2180 ;------------------------------------------------------------
                                   2181 ;Allocation info for local variables in function 'usbSetConfiguration'
                                   2182 ;------------------------------------------------------------
                                   2183 ;pReq                      Allocated to registers r5 r6 r7 
                                   2184 ;------------------------------------------------------------
                                   2185 ;	cc1111usb.c:477: void usbSetConfiguration(USB_Setup_Header* pReq)
                                   2186 ;	-----------------------------------------
                                   2187 ;	 function usbSetConfiguration
                                   2188 ;	-----------------------------------------
      000F3D                       2189 _usbSetConfiguration:
      000F3D AD 82            [24] 2190 	mov	r5,dpl
      000F3F AE 83            [24] 2191 	mov	r6,dph
      000F41 AF F0            [24] 2192 	mov	r7,b
                                   2193 ;	cc1111usb.c:479: usb_data.config = pReq->wValue & 0xff;
      000F43 74 02            [12] 2194 	mov	a,#0x02
      000F45 2D               [12] 2195 	add	a,r5
      000F46 FD               [12] 2196 	mov	r5,a
      000F47 E4               [12] 2197 	clr	a
      000F48 3E               [12] 2198 	addc	a,r6
      000F49 FE               [12] 2199 	mov	r6,a
      000F4A 8D 82            [24] 2200 	mov	dpl,r5
      000F4C 8E 83            [24] 2201 	mov	dph,r6
      000F4E 8F F0            [24] 2202 	mov	b,r7
      000F50 12 1A 67         [24] 2203 	lcall	__gptrget
      000F53 FD               [12] 2204 	mov	r5,a
      000F54 A3               [24] 2205 	inc	dptr
      000F55 12 1A 67         [24] 2206 	lcall	__gptrget
      000F58 8D 25            [24] 2207 	mov	(_usb_data + 0x0003),r5
      000F5A 22               [24] 2208 	ret
                                   2209 ;------------------------------------------------------------
                                   2210 ;Allocation info for local variables in function 'usbGetDescriptorPrimitive'
                                   2211 ;------------------------------------------------------------
                                   2212 ;index                     Allocated with name '_usbGetDescriptorPrimitive_PARM_2'
                                   2213 ;wantedType                Allocated with name '_usbGetDescriptorPrimitive_wantedType_1_82'
                                   2214 ;descType                  Allocated to registers r3 
                                   2215 ;descPtr                   Allocated to registers r4 r5 r6 
                                   2216 ;------------------------------------------------------------
                                   2217 ;	cc1111usb.c:483: u8* usbGetDescriptorPrimitive(u8 wantedType, u8 index){
                                   2218 ;	-----------------------------------------
                                   2219 ;	 function usbGetDescriptorPrimitive
                                   2220 ;	-----------------------------------------
      000F5B                       2221 _usbGetDescriptorPrimitive:
      000F5B 85 82 0F         [24] 2222 	mov	_usbGetDescriptorPrimitive_wantedType_1_82,dpl
                                   2223 ;	cc1111usb.c:486: u8* descPtr = (u8*)&USBDESCBEGIN;                 // start of data... sorta
      000F5E 7C 2E            [12] 2224 	mov	r4,#_USBDESCBEGIN
      000F60 7D 19            [12] 2225 	mov	r5,#(_USBDESCBEGIN >> 8)
      000F62 7E 80            [12] 2226 	mov	r6,#0x80
                                   2227 ;	cc1111usb.c:488: descType = *(descPtr+1);
      000F64 74 01            [12] 2228 	mov	a,#0x01
      000F66 2C               [12] 2229 	add	a,r4
      000F67 F9               [12] 2230 	mov	r1,a
      000F68 E4               [12] 2231 	clr	a
      000F69 3D               [12] 2232 	addc	a,r5
      000F6A FA               [12] 2233 	mov	r2,a
      000F6B 8E 03            [24] 2234 	mov	ar3,r6
      000F6D 89 82            [24] 2235 	mov	dpl,r1
      000F6F 8A 83            [24] 2236 	mov	dph,r2
      000F71 8B F0            [24] 2237 	mov	b,r3
      000F73 12 1A 67         [24] 2238 	lcall	__gptrget
      000F76 FB               [12] 2239 	mov	r3,a
                                   2240 ;	cc1111usb.c:491: while (descType != 0xff ){
      000F77 AA 0E            [24] 2241 	mov	r2,_usbGetDescriptorPrimitive_PARM_2
      000F79                       2242 00107$:
      000F79 BB FF 02         [24] 2243 	cjne	r3,#0xFF,00125$
      000F7C 80 52            [24] 2244 	sjmp	00109$
      000F7E                       2245 00125$:
                                   2246 ;	cc1111usb.c:493: if (descType == wantedType){
      000F7E EB               [12] 2247 	mov	a,r3
      000F7F B5 0F 2B         [24] 2248 	cjne	a,_usbGetDescriptorPrimitive_wantedType_1_82,00105$
                                   2249 ;	cc1111usb.c:494: if (index == 0){
      000F82 EA               [12] 2250 	mov	a,r2
      000F83 70 04            [24] 2251 	jnz	00102$
                                   2252 ;	cc1111usb.c:495: descType = 0xff;                            // WARNING: destructive.  go directly to ret, do not pass go, do not collect $200
      000F85 7B FF            [12] 2253 	mov	r3,#0xFF
      000F87 80 F0            [24] 2254 	sjmp	00107$
      000F89                       2255 00102$:
                                   2256 ;	cc1111usb.c:497: index--;
      000F89 1A               [12] 2257 	dec	r2
                                   2258 ;	cc1111usb.c:498: descPtr = descPtr + (u8)*descPtr;
      000F8A 8C 82            [24] 2259 	mov	dpl,r4
      000F8C 8D 83            [24] 2260 	mov	dph,r5
      000F8E 8E F0            [24] 2261 	mov	b,r6
      000F90 12 1A 67         [24] 2262 	lcall	__gptrget
      000F93 2C               [12] 2263 	add	a,r4
      000F94 FC               [12] 2264 	mov	r4,a
      000F95 E4               [12] 2265 	clr	a
      000F96 3D               [12] 2266 	addc	a,r5
      000F97 FD               [12] 2267 	mov	r5,a
                                   2268 ;	cc1111usb.c:499: descType = *(descPtr+1);
      000F98 74 01            [12] 2269 	mov	a,#0x01
      000F9A 2C               [12] 2270 	add	a,r4
      000F9B F8               [12] 2271 	mov	r0,a
      000F9C E4               [12] 2272 	clr	a
      000F9D 3D               [12] 2273 	addc	a,r5
      000F9E F9               [12] 2274 	mov	r1,a
      000F9F 8E 07            [24] 2275 	mov	ar7,r6
      000FA1 88 82            [24] 2276 	mov	dpl,r0
      000FA3 89 83            [24] 2277 	mov	dph,r1
      000FA5 8F F0            [24] 2278 	mov	b,r7
      000FA7 12 1A 67         [24] 2279 	lcall	__gptrget
      000FAA FB               [12] 2280 	mov	r3,a
      000FAB 80 CC            [24] 2281 	sjmp	00107$
      000FAD                       2282 00105$:
                                   2283 ;	cc1111usb.c:503: descPtr = descPtr + (u8)*descPtr;
      000FAD 8C 82            [24] 2284 	mov	dpl,r4
      000FAF 8D 83            [24] 2285 	mov	dph,r5
      000FB1 8E F0            [24] 2286 	mov	b,r6
      000FB3 12 1A 67         [24] 2287 	lcall	__gptrget
      000FB6 2C               [12] 2288 	add	a,r4
      000FB7 FC               [12] 2289 	mov	r4,a
      000FB8 E4               [12] 2290 	clr	a
      000FB9 3D               [12] 2291 	addc	a,r5
      000FBA FD               [12] 2292 	mov	r5,a
                                   2293 ;	cc1111usb.c:504: descType = *(descPtr+1);
      000FBB 74 01            [12] 2294 	mov	a,#0x01
      000FBD 2C               [12] 2295 	add	a,r4
      000FBE F8               [12] 2296 	mov	r0,a
      000FBF E4               [12] 2297 	clr	a
      000FC0 3D               [12] 2298 	addc	a,r5
      000FC1 F9               [12] 2299 	mov	r1,a
      000FC2 8E 07            [24] 2300 	mov	ar7,r6
      000FC4 88 82            [24] 2301 	mov	dpl,r0
      000FC6 89 83            [24] 2302 	mov	dph,r1
      000FC8 8F F0            [24] 2303 	mov	b,r7
      000FCA 12 1A 67         [24] 2304 	lcall	__gptrget
      000FCD FB               [12] 2305 	mov	r3,a
      000FCE 80 A9            [24] 2306 	sjmp	00107$
      000FD0                       2307 00109$:
                                   2308 ;	cc1111usb.c:507: return descPtr;
      000FD0 8C 82            [24] 2309 	mov	dpl,r4
      000FD2 8D 83            [24] 2310 	mov	dph,r5
      000FD4 8E F0            [24] 2311 	mov	b,r6
      000FD6 22               [24] 2312 	ret
                                   2313 ;------------------------------------------------------------
                                   2314 ;Allocation info for local variables in function 'usbGetDescriptor'
                                   2315 ;------------------------------------------------------------
                                   2316 ;pReq                      Allocated with name '_usbGetDescriptor_pReq_1_89'
                                   2317 ;buffer                    Allocated with name '_usbGetDescriptor_buffer_1_90'
                                   2318 ;length                    Allocated with name '_usbGetDescriptor_length_1_90'
                                   2319 ;sloc0                     Allocated with name '_usbGetDescriptor_sloc0_1_0'
                                   2320 ;sloc1                     Allocated with name '_usbGetDescriptor_sloc1_1_0'
                                   2321 ;------------------------------------------------------------
                                   2322 ;	cc1111usb.c:510: void usbGetDescriptor(USB_Setup_Header* pReq)
                                   2323 ;	-----------------------------------------
                                   2324 ;	 function usbGetDescriptor
                                   2325 ;	-----------------------------------------
      000FD7                       2326 _usbGetDescriptor:
      000FD7 85 82 35         [24] 2327 	mov	_usbGetDescriptor_pReq_1_89,dpl
      000FDA 85 83 36         [24] 2328 	mov	(_usbGetDescriptor_pReq_1_89 + 1),dph
      000FDD 85 F0 37         [24] 2329 	mov	(_usbGetDescriptor_pReq_1_89 + 2),b
                                   2330 ;	cc1111usb.c:515: switch ((pReq->wValue)>>8){
      000FE0 74 02            [12] 2331 	mov	a,#0x02
      000FE2 25 35            [12] 2332 	add	a,_usbGetDescriptor_pReq_1_89
      000FE4 F5 3F            [12] 2333 	mov	_usbGetDescriptor_sloc1_1_0,a
      000FE6 E4               [12] 2334 	clr	a
      000FE7 35 36            [12] 2335 	addc	a,(_usbGetDescriptor_pReq_1_89 + 1)
      000FE9 F5 40            [12] 2336 	mov	(_usbGetDescriptor_sloc1_1_0 + 1),a
      000FEB 85 37 41         [24] 2337 	mov	(_usbGetDescriptor_sloc1_1_0 + 2),(_usbGetDescriptor_pReq_1_89 + 2)
      000FEE 85 3F 82         [24] 2338 	mov	dpl,_usbGetDescriptor_sloc1_1_0
      000FF1 85 40 83         [24] 2339 	mov	dph,(_usbGetDescriptor_sloc1_1_0 + 1)
      000FF4 85 41 F0         [24] 2340 	mov	b,(_usbGetDescriptor_sloc1_1_0 + 2)
      000FF7 12 1A 67         [24] 2341 	lcall	__gptrget
      000FFA F8               [12] 2342 	mov	r0,a
      000FFB A3               [24] 2343 	inc	dptr
      000FFC 12 1A 67         [24] 2344 	lcall	__gptrget
      000FFF F9               [12] 2345 	mov	r1,a
      001000 89 3D            [24] 2346 	mov	_usbGetDescriptor_sloc0_1_0,r1
      001002 75 3E 00         [24] 2347 	mov	(_usbGetDescriptor_sloc0_1_0 + 1),#0x00
      001005 74 01            [12] 2348 	mov	a,#0x01
      001007 B5 3D 06         [24] 2349 	cjne	a,_usbGetDescriptor_sloc0_1_0,00135$
      00100A E4               [12] 2350 	clr	a
      00100B B5 3E 02         [24] 2351 	cjne	a,(_usbGetDescriptor_sloc0_1_0 + 1),00135$
      00100E 80 1A            [24] 2352 	sjmp	00101$
      001010                       2353 00135$:
      001010 74 02            [12] 2354 	mov	a,#0x02
      001012 B5 3D 06         [24] 2355 	cjne	a,_usbGetDescriptor_sloc0_1_0,00136$
      001015 E4               [12] 2356 	clr	a
      001016 B5 3E 02         [24] 2357 	cjne	a,(_usbGetDescriptor_sloc0_1_0 + 1),00136$
      001019 80 2C            [24] 2358 	sjmp	00102$
      00101B                       2359 00136$:
      00101B 74 03            [12] 2360 	mov	a,#0x03
      00101D B5 3D 07         [24] 2361 	cjne	a,_usbGetDescriptor_sloc0_1_0,00137$
      001020 E4               [12] 2362 	clr	a
      001021 B5 3E 03         [24] 2363 	cjne	a,(_usbGetDescriptor_sloc0_1_0 + 1),00137$
      001024 02 10 C5         [24] 2364 	ljmp	00108$
      001027                       2365 00137$:
      001027 02 10 E2         [24] 2366 	ljmp	00109$
                                   2367 ;	cc1111usb.c:516: case USB_DESC_DEVICE:
      00102A                       2368 00101$:
                                   2369 ;	cc1111usb.c:517: buffer = usbGetDescriptorPrimitive((pReq->wValue)>>8, 0);
      00102A 89 82            [24] 2370 	mov	dpl,r1
      00102C 75 0E 00         [24] 2371 	mov	_usbGetDescriptorPrimitive_PARM_2,#0x00
      00102F 12 0F 5B         [24] 2372 	lcall	_usbGetDescriptorPrimitive
                                   2373 ;	cc1111usb.c:518: length = (u8)*(buffer);
      001032 85 82 38         [24] 2374 	mov	_usbGetDescriptor_buffer_1_90,dpl
      001035 85 83 39         [24] 2375 	mov	(_usbGetDescriptor_buffer_1_90 + 1),dph
      001038 85 F0 3A         [24] 2376 	mov	(_usbGetDescriptor_buffer_1_90 + 2),b
      00103B 12 1A 67         [24] 2377 	lcall	__gptrget
      00103E FF               [12] 2378 	mov	r7,a
      00103F 8F 3B            [24] 2379 	mov	_usbGetDescriptor_length_1_90,r7
      001041 75 3C 00         [24] 2380 	mov	(_usbGetDescriptor_length_1_90 + 1),#0x00
                                   2381 ;	cc1111usb.c:519: break;
      001044 02 10 FB         [24] 2382 	ljmp	00110$
                                   2383 ;	cc1111usb.c:520: case USB_DESC_CONFIG:
      001047                       2384 00102$:
                                   2385 ;	cc1111usb.c:521: buffer = usbGetDescriptorPrimitive((pReq->wValue)>>8, (pReq->wValue)&0xff);
      001047 89 82            [24] 2386 	mov	dpl,r1
      001049 88 04            [24] 2387 	mov	ar4,r0
      00104B 8C 0E            [24] 2388 	mov	_usbGetDescriptorPrimitive_PARM_2,r4
      00104D 12 0F 5B         [24] 2389 	lcall	_usbGetDescriptorPrimitive
      001050 85 82 38         [24] 2390 	mov	_usbGetDescriptor_buffer_1_90,dpl
      001053 85 83 39         [24] 2391 	mov	(_usbGetDescriptor_buffer_1_90 + 1),dph
      001056 85 F0 3A         [24] 2392 	mov	(_usbGetDescriptor_buffer_1_90 + 2),b
                                   2393 ;	cc1111usb.c:522: length = (u16)*(buffer+2);
      001059 74 02            [12] 2394 	mov	a,#0x02
      00105B 25 38            [12] 2395 	add	a,_usbGetDescriptor_buffer_1_90
      00105D FB               [12] 2396 	mov	r3,a
      00105E E4               [12] 2397 	clr	a
      00105F 35 39            [12] 2398 	addc	a,(_usbGetDescriptor_buffer_1_90 + 1)
      001061 FC               [12] 2399 	mov	r4,a
      001062 AD 3A            [24] 2400 	mov	r5,(_usbGetDescriptor_buffer_1_90 + 2)
      001064 8B 82            [24] 2401 	mov	dpl,r3
      001066 8C 83            [24] 2402 	mov	dph,r4
      001068 8D F0            [24] 2403 	mov	b,r5
      00106A 12 1A 67         [24] 2404 	lcall	__gptrget
      00106D FB               [12] 2405 	mov	r3,a
      00106E 8B 3B            [24] 2406 	mov	_usbGetDescriptor_length_1_90,r3
      001070 75 3C 00         [24] 2407 	mov	(_usbGetDescriptor_length_1_90 + 1),#0x00
                                   2408 ;	cc1111usb.c:523: if ((pReq->wValue>>8) != *(buffer+1))
      001073 85 3F 82         [24] 2409 	mov	dpl,_usbGetDescriptor_sloc1_1_0
      001076 85 40 83         [24] 2410 	mov	dph,(_usbGetDescriptor_sloc1_1_0 + 1)
      001079 85 41 F0         [24] 2411 	mov	b,(_usbGetDescriptor_sloc1_1_0 + 2)
      00107C 12 1A 67         [24] 2412 	lcall	__gptrget
      00107F A3               [24] 2413 	inc	dptr
      001080 12 1A 67         [24] 2414 	lcall	__gptrget
      001083 FC               [12] 2415 	mov	r4,a
      001084 7D 00            [12] 2416 	mov	r5,#0x00
      001086 74 01            [12] 2417 	mov	a,#0x01
      001088 25 38            [12] 2418 	add	a,_usbGetDescriptor_buffer_1_90
      00108A FA               [12] 2419 	mov	r2,a
      00108B E4               [12] 2420 	clr	a
      00108C 35 39            [12] 2421 	addc	a,(_usbGetDescriptor_buffer_1_90 + 1)
      00108E FB               [12] 2422 	mov	r3,a
      00108F AF 3A            [24] 2423 	mov	r7,(_usbGetDescriptor_buffer_1_90 + 2)
      001091 8A 82            [24] 2424 	mov	dpl,r2
      001093 8B 83            [24] 2425 	mov	dph,r3
      001095 8F F0            [24] 2426 	mov	b,r7
      001097 12 1A 67         [24] 2427 	lcall	__gptrget
      00109A FA               [12] 2428 	mov	r2,a
      00109B 7F 00            [12] 2429 	mov	r7,#0x00
      00109D EC               [12] 2430 	mov	a,r4
      00109E B5 02 06         [24] 2431 	cjne	a,ar2,00138$
      0010A1 ED               [12] 2432 	mov	a,r5
      0010A2 B5 07 02         [24] 2433 	cjne	a,ar7,00138$
      0010A5 80 54            [24] 2434 	sjmp	00110$
      0010A7                       2435 00138$:
                                   2436 ;	cc1111usb.c:524: while (1)   //blink(100,100);                               ///////// DEBUGGING!  WILL STOP EXECUTION!
      0010A7                       2437 00104$:
                                   2438 ;	cc1111usb.c:525: blink_binary_baby_lsb((pReq->wValue), 16); 
      0010A7 85 3F 82         [24] 2439 	mov	dpl,_usbGetDescriptor_sloc1_1_0
      0010AA 85 40 83         [24] 2440 	mov	dph,(_usbGetDescriptor_sloc1_1_0 + 1)
      0010AD 85 41 F0         [24] 2441 	mov	b,(_usbGetDescriptor_sloc1_1_0 + 2)
      0010B0 12 1A 67         [24] 2442 	lcall	__gptrget
      0010B3 FE               [12] 2443 	mov	r6,a
      0010B4 A3               [24] 2444 	inc	dptr
      0010B5 12 1A 67         [24] 2445 	lcall	__gptrget
      0010B8 FF               [12] 2446 	mov	r7,a
      0010B9 75 0D 10         [24] 2447 	mov	_blink_binary_baby_lsb_PARM_2,#0x10
      0010BC 8E 82            [24] 2448 	mov	dpl,r6
      0010BE 8F 83            [24] 2449 	mov	dph,r7
      0010C0 12 09 A2         [24] 2450 	lcall	_blink_binary_baby_lsb
                                   2451 ;	cc1111usb.c:527: case USB_DESC_STRING:
      0010C3 80 E2            [24] 2452 	sjmp	00104$
      0010C5                       2453 00108$:
                                   2454 ;	cc1111usb.c:528: buffer = usbGetDescriptorPrimitive((pReq->wValue)>>8, (pReq->wValue)&0xff);
      0010C5 89 82            [24] 2455 	mov	dpl,r1
      0010C7 88 06            [24] 2456 	mov	ar6,r0
      0010C9 8E 0E            [24] 2457 	mov	_usbGetDescriptorPrimitive_PARM_2,r6
      0010CB 12 0F 5B         [24] 2458 	lcall	_usbGetDescriptorPrimitive
                                   2459 ;	cc1111usb.c:529: length = (u8)*(buffer);
      0010CE 85 82 38         [24] 2460 	mov	_usbGetDescriptor_buffer_1_90,dpl
      0010D1 85 83 39         [24] 2461 	mov	(_usbGetDescriptor_buffer_1_90 + 1),dph
      0010D4 85 F0 3A         [24] 2462 	mov	(_usbGetDescriptor_buffer_1_90 + 2),b
      0010D7 12 1A 67         [24] 2463 	lcall	__gptrget
      0010DA FF               [12] 2464 	mov	r7,a
      0010DB 8F 3B            [24] 2465 	mov	_usbGetDescriptor_length_1_90,r7
      0010DD 75 3C 00         [24] 2466 	mov	(_usbGetDescriptor_length_1_90 + 1),#0x00
                                   2467 ;	cc1111usb.c:530: break;
                                   2468 ;	cc1111usb.c:531: default:
      0010E0 80 19            [24] 2469 	sjmp	00110$
      0010E2                       2470 00109$:
                                   2471 ;	cc1111usb.c:532: buffer = usbGetDescriptorPrimitive((pReq->wValue)>>8, (pReq->wValue)&0xff);
      0010E2 89 82            [24] 2472 	mov	dpl,r1
      0010E4 88 0E            [24] 2473 	mov	_usbGetDescriptorPrimitive_PARM_2,r0
      0010E6 12 0F 5B         [24] 2474 	lcall	_usbGetDescriptorPrimitive
                                   2475 ;	cc1111usb.c:533: length = (u8)*(buffer);
      0010E9 85 82 38         [24] 2476 	mov	_usbGetDescriptor_buffer_1_90,dpl
      0010EC 85 83 39         [24] 2477 	mov	(_usbGetDescriptor_buffer_1_90 + 1),dph
      0010EF 85 F0 3A         [24] 2478 	mov	(_usbGetDescriptor_buffer_1_90 + 2),b
      0010F2 12 1A 67         [24] 2479 	lcall	__gptrget
      0010F5 FF               [12] 2480 	mov	r7,a
      0010F6 8F 3B            [24] 2481 	mov	_usbGetDescriptor_length_1_90,r7
      0010F8 75 3C 00         [24] 2482 	mov	(_usbGetDescriptor_length_1_90 + 1),#0x00
                                   2483 ;	cc1111usb.c:535: }
      0010FB                       2484 00110$:
                                   2485 ;	cc1111usb.c:536: if (length > pReq->wLength)
      0010FB 74 06            [12] 2486 	mov	a,#0x06
      0010FD 25 35            [12] 2487 	add	a,_usbGetDescriptor_pReq_1_89
      0010FF FD               [12] 2488 	mov	r5,a
      001100 E4               [12] 2489 	clr	a
      001101 35 36            [12] 2490 	addc	a,(_usbGetDescriptor_pReq_1_89 + 1)
      001103 FE               [12] 2491 	mov	r6,a
      001104 AF 37            [24] 2492 	mov	r7,(_usbGetDescriptor_pReq_1_89 + 2)
      001106 8D 82            [24] 2493 	mov	dpl,r5
      001108 8E 83            [24] 2494 	mov	dph,r6
      00110A 8F F0            [24] 2495 	mov	b,r7
      00110C 12 1A 67         [24] 2496 	lcall	__gptrget
      00110F FE               [12] 2497 	mov	r6,a
      001110 A3               [24] 2498 	inc	dptr
      001111 12 1A 67         [24] 2499 	lcall	__gptrget
      001114 FF               [12] 2500 	mov	r7,a
      001115 C3               [12] 2501 	clr	c
      001116 EE               [12] 2502 	mov	a,r6
      001117 95 3B            [12] 2503 	subb	a,_usbGetDescriptor_length_1_90
      001119 EF               [12] 2504 	mov	a,r7
      00111A 95 3C            [12] 2505 	subb	a,(_usbGetDescriptor_length_1_90 + 1)
      00111C 50 04            [24] 2506 	jnc	00112$
                                   2507 ;	cc1111usb.c:537: length = pReq->wLength;
      00111E 8E 3B            [24] 2508 	mov	_usbGetDescriptor_length_1_90,r6
      001120 8F 3C            [24] 2509 	mov	(_usbGetDescriptor_length_1_90 + 1),r7
      001122                       2510 00112$:
                                   2511 ;	cc1111usb.c:539: setup_send_ep0(buffer, length);
      001122 85 3B 31         [24] 2512 	mov	_setup_send_ep0_PARM_2,_usbGetDescriptor_length_1_90
      001125 85 3C 32         [24] 2513 	mov	(_setup_send_ep0_PARM_2 + 1),(_usbGetDescriptor_length_1_90 + 1)
      001128 85 38 82         [24] 2514 	mov	dpl,_usbGetDescriptor_buffer_1_90
      00112B 85 39 83         [24] 2515 	mov	dph,(_usbGetDescriptor_buffer_1_90 + 1)
      00112E 85 3A F0         [24] 2516 	mov	b,(_usbGetDescriptor_buffer_1_90 + 2)
      001131 12 0D 50         [24] 2517 	lcall	_setup_send_ep0
                                   2518 ;	cc1111usb.c:540: if ((pReq->wValue>>8) == USB_DESC_CONFIG){
      001134 85 3F 82         [24] 2519 	mov	dpl,_usbGetDescriptor_sloc1_1_0
      001137 85 40 83         [24] 2520 	mov	dph,(_usbGetDescriptor_sloc1_1_0 + 1)
      00113A 85 41 F0         [24] 2521 	mov	b,(_usbGetDescriptor_sloc1_1_0 + 2)
      00113D 12 1A 67         [24] 2522 	lcall	__gptrget
      001140 A3               [24] 2523 	inc	dptr
      001141 12 1A 67         [24] 2524 	lcall	__gptrget
      001144 FE               [12] 2525 	mov	r6,a
      001145 7F 00            [12] 2526 	mov	r7,#0x00
      001147 BE 02 1C         [24] 2527 	cjne	r6,#0x02,00115$
      00114A BF 00 19         [24] 2528 	cjne	r7,#0x00,00115$
                                   2529 ;	cc1111usb.c:541: REALLYFASTBLINK();
      00114D D2 90            [12] 2530 	setb	_P1_0
      00114F 90 00 02         [24] 2531 	mov	dptr,#0x0002
      001152 12 09 63         [24] 2532 	lcall	_sleepMillis
      001155 C2 90            [12] 2533 	clr	_P1_0
      001157 90 00 0A         [24] 2534 	mov	dptr,#0x000A
      00115A 12 09 63         [24] 2535 	lcall	_sleepMillis
                                   2536 ;	cc1111usb.c:542: appstatus |= 1;                                         //  hack to trigger "waitForUSBsetup()"
      00115D 90 F1 70         [24] 2537 	mov	dptr,#_appstatus
      001160 E0               [24] 2538 	movx	a,@dptr
      001161 FF               [12] 2539 	mov	r7,a
      001162 74 01            [12] 2540 	mov	a,#0x01
      001164 4F               [12] 2541 	orl	a,r7
      001165 F0               [24] 2542 	movx	@dptr,a
      001166                       2543 00115$:
      001166 22               [24] 2544 	ret
                                   2545 ;------------------------------------------------------------
                                   2546 ;Allocation info for local variables in function 'handleCS0'
                                   2547 ;------------------------------------------------------------
                                   2548 ;req                       Allocated with name '_handleCS0_req_1_95'
                                   2549 ;pReq                      Allocated to registers 
                                   2550 ;csReg                     Allocated to registers r7 
                                   2551 ;loop                      Allocated to registers r6 
                                   2552 ;val                       Allocated with name '_handleCS0_val_1_95'
                                   2553 ;------------------------------------------------------------
                                   2554 ;	cc1111usb.c:560: void handleCS0(void)
                                   2555 ;	-----------------------------------------
                                   2556 ;	 function handleCS0
                                   2557 ;	-----------------------------------------
      001167                       2558 _handleCS0:
                                   2559 ;	cc1111usb.c:563: u8* pReq = (u8*)(&req);
                                   2560 ;	cc1111usb.c:567: USBINDEX = 0;
      001167 90 DE 0E         [24] 2561 	mov	dptr,#_USBINDEX
      00116A E4               [12] 2562 	clr	a
      00116B F0               [24] 2563 	movx	@dptr,a
                                   2564 ;	cc1111usb.c:571: csReg = USBCS0;
      00116C 90 DE 11         [24] 2565 	mov	dptr,#_USBCS0
      00116F E0               [24] 2566 	movx	a,@dptr
                                   2567 ;	cc1111usb.c:574: if (csReg & USBCS0_SETUP_END) 
      001170 FF               [12] 2568 	mov	r7,a
      001171 30 E4 0E         [24] 2569 	jnb	acc.4,00102$
                                   2570 ;	cc1111usb.c:576: ep0iobuf.epstatus = EP_STATE_IDLE;
      001174 90 F1 61         [24] 2571 	mov	dptr,#(_ep0iobuf + 0x000d)
      001177 E4               [12] 2572 	clr	a
      001178 F0               [24] 2573 	movx	@dptr,a
                                   2574 ;	cc1111usb.c:577: USBCS0 |= USBCS0_CLR_SETUP_END;
      001179 90 DE 11         [24] 2575 	mov	dptr,#_USBCS0
      00117C E0               [24] 2576 	movx	a,@dptr
      00117D FE               [12] 2577 	mov	r6,a
      00117E 74 80            [12] 2578 	mov	a,#0x80
      001180 4E               [12] 2579 	orl	a,r6
      001181 F0               [24] 2580 	movx	@dptr,a
      001182                       2581 00102$:
                                   2582 ;	cc1111usb.c:581: if (csReg & USBCS0_SENT_STALL) 
      001182 EF               [12] 2583 	mov	a,r7
      001183 30 E2 24         [24] 2584 	jnb	acc.2,00104$
                                   2585 ;	cc1111usb.c:583: USBCS0 = 0x00;
      001186 90 DE 11         [24] 2586 	mov	dptr,#_USBCS0
      001189 E4               [12] 2587 	clr	a
      00118A F0               [24] 2588 	movx	@dptr,a
                                   2589 ;	cc1111usb.c:584: lastCode[1] = 4;
      00118B 90 F0 D3         [24] 2590 	mov	dptr,#(_lastCode + 0x0001)
      00118E 74 04            [12] 2591 	mov	a,#0x04
      001190 F0               [24] 2592 	movx	@dptr,a
                                   2593 ;	cc1111usb.c:585: ep0iobuf.epstatus = EP_STATE_IDLE;
      001191 90 F1 61         [24] 2594 	mov	dptr,#(_ep0iobuf + 0x000d)
      001194 E4               [12] 2595 	clr	a
      001195 F0               [24] 2596 	movx	@dptr,a
                                   2597 ;	cc1111usb.c:586: blink(200,200);
      001196 D2 90            [12] 2598 	setb	_P1_0
      001198 90 00 C8         [24] 2599 	mov	dptr,#0x00C8
      00119B C0 07            [24] 2600 	push	ar7
      00119D 12 09 63         [24] 2601 	lcall	_sleepMillis
      0011A0 C2 90            [12] 2602 	clr	_P1_0
      0011A2 90 00 C8         [24] 2603 	mov	dptr,#0x00C8
      0011A5 12 09 63         [24] 2604 	lcall	_sleepMillis
      0011A8 D0 07            [24] 2605 	pop	ar7
      0011AA                       2606 00104$:
                                   2607 ;	cc1111usb.c:589: if (ep0iobuf.epstatus == EP_STATE_STALL)
      0011AA 90 F1 61         [24] 2608 	mov	dptr,#(_ep0iobuf + 0x000d)
      0011AD E0               [24] 2609 	movx	a,@dptr
      0011AE FE               [12] 2610 	mov	r6,a
      0011AF BE 03 19         [24] 2611 	cjne	r6,#0x03,00106$
                                   2612 ;	cc1111usb.c:591: blink(500,500);
      0011B2 D2 90            [12] 2613 	setb	_P1_0
      0011B4 90 01 F4         [24] 2614 	mov	dptr,#0x01F4
      0011B7 C0 07            [24] 2615 	push	ar7
      0011B9 12 09 63         [24] 2616 	lcall	_sleepMillis
      0011BC C2 90            [12] 2617 	clr	_P1_0
      0011BE 90 01 F4         [24] 2618 	mov	dptr,#0x01F4
      0011C1 12 09 63         [24] 2619 	lcall	_sleepMillis
      0011C4 D0 07            [24] 2620 	pop	ar7
                                   2621 ;	cc1111usb.c:592: ep0iobuf.epstatus = EP_STATE_IDLE;
      0011C6 90 F1 61         [24] 2622 	mov	dptr,#(_ep0iobuf + 0x000d)
      0011C9 E4               [12] 2623 	clr	a
      0011CA F0               [24] 2624 	movx	@dptr,a
      0011CB                       2625 00106$:
                                   2626 ;	cc1111usb.c:598: if (ep0iobuf.epstatus == EP_STATE_IDLE)
      0011CB 90 F1 61         [24] 2627 	mov	dptr,#(_ep0iobuf + 0x000d)
      0011CE E0               [24] 2628 	movx	a,@dptr
      0011CF 60 03            [24] 2629 	jz	00313$
      0011D1 02 13 D3         [24] 2630 	ljmp	00173$
      0011D4                       2631 00313$:
                                   2632 ;	cc1111usb.c:601: if (csReg & USBCS0_OUTPKT_RDY)                          // do we have a SETUP packet ready for us to consume?
      0011D4 EF               [12] 2633 	mov	a,r7
      0011D5 20 E0 03         [24] 2634 	jb	acc.0,00314$
      0011D8 02 13 D3         [24] 2635 	ljmp	00173$
      0011DB                       2636 00314$:
                                   2637 ;	cc1111usb.c:604: USBINDEX = 0;
      0011DB 90 DE 0E         [24] 2638 	mov	dptr,#_USBINDEX
      0011DE E4               [12] 2639 	clr	a
      0011DF F0               [24] 2640 	movx	@dptr,a
                                   2641 ;	cc1111usb.c:605: for (loop=0; loop<8; loop++,pReq++) {               // FIXME: Use DMA
      0011E0 7F 00            [12] 2642 	mov	r7,#0x00
      0011E2 7C 42            [12] 2643 	mov	r4,#_handleCS0_req_1_95
      0011E4 7D 00            [12] 2644 	mov	r5,#(_handleCS0_req_1_95 >> 8)
      0011E6 7E 40            [12] 2645 	mov	r6,#0x40
      0011E8                       2646 00178$:
                                   2647 ;	cc1111usb.c:606: *pReq = USBF0;
      0011E8 90 DE 20         [24] 2648 	mov	dptr,#_USBF0
      0011EB E0               [24] 2649 	movx	a,@dptr
      0011EC FB               [12] 2650 	mov	r3,a
      0011ED 8C 82            [24] 2651 	mov	dpl,r4
      0011EF 8D 83            [24] 2652 	mov	dph,r5
      0011F1 8E F0            [24] 2653 	mov	b,r6
      0011F3 12 1A 4C         [24] 2654 	lcall	__gptrput
      0011F6 A3               [24] 2655 	inc	dptr
      0011F7 AC 82            [24] 2656 	mov	r4,dpl
      0011F9 AD 83            [24] 2657 	mov	r5,dph
                                   2658 ;	cc1111usb.c:605: for (loop=0; loop<8; loop++,pReq++) {               // FIXME: Use DMA
      0011FB 0F               [12] 2659 	inc	r7
      0011FC BF 08 00         [24] 2660 	cjne	r7,#0x08,00315$
      0011FF                       2661 00315$:
      0011FF 40 E7            [24] 2662 	jc	00178$
                                   2663 ;	cc1111usb.c:612: if (req.bmRequestType & USB_BM_REQTYPE_DIRMASK)                       // should be *sending* data, if any
      001201 E5 42            [12] 2664 	mov	a,_handleCS0_req_1_95
      001203 FF               [12] 2665 	mov	r7,a
      001204 20 E7 03         [24] 2666 	jb	acc.7,00317$
      001207 02 12 F3         [24] 2667 	ljmp	00166$
      00120A                       2668 00317$:
                                   2669 ;	cc1111usb.c:614: switch(req.bmRequestType & USB_BM_REQTYPE_TYPEMASK)
      00120A 74 60            [12] 2670 	mov	a,#0x60
      00120C 5F               [12] 2671 	anl	a,r7
      00120D FE               [12] 2672 	mov	r6,a
      00120E 60 15            [24] 2673 	jz	00108$
      001210 BE 20 03         [24] 2674 	cjne	r6,#0x20,00319$
      001213 02 13 BB         [24] 2675 	ljmp	00167$
      001216                       2676 00319$:
      001216 BE 40 03         [24] 2677 	cjne	r6,#0x40,00320$
      001219 02 12 D2         [24] 2678 	ljmp	00132$
      00121C                       2679 00320$:
      00121C BE 60 03         [24] 2680 	cjne	r6,#0x60,00321$
      00121F 02 12 DE         [24] 2681 	ljmp	00133$
      001222                       2682 00321$:
      001222 02 13 BB         [24] 2683 	ljmp	00167$
                                   2684 ;	cc1111usb.c:616: case USB_BM_REQTYPE_TYPE_STD:               //  STANDARD type
      001225                       2685 00108$:
                                   2686 ;	cc1111usb.c:618: loop = req.bmRequestType & USB_BM_REQTYPE_TGTMASK;
      001225 74 1F            [12] 2687 	mov	a,#0x1F
      001227 5F               [12] 2688 	anl	a,r7
                                   2689 ;	cc1111usb.c:619: if (loop == USB_BM_REQTYPE_TGT_DEV)
      001228 FE               [12] 2690 	mov	r6,a
      001229 70 45            [24] 2691 	jnz	00129$
                                   2692 ;	cc1111usb.c:621: switch (req.bRequest){
      00122B AD 43            [24] 2693 	mov	r5,(_handleCS0_req_1_95 + 0x0001)
      00122D BD 00 02         [24] 2694 	cjne	r5,#0x00,00323$
      001230 80 1C            [24] 2695 	sjmp	00111$
      001232                       2696 00323$:
      001232 BD 06 02         [24] 2697 	cjne	r5,#0x06,00324$
      001235 80 05            [24] 2698 	sjmp	00109$
      001237                       2699 00324$:
                                   2700 ;	cc1111usb.c:623: case USB_GET_DESCRIPTOR:
      001237 BD 08 2A         [24] 2701 	cjne	r5,#0x08,00112$
      00123A 80 0C            [24] 2702 	sjmp	00110$
      00123C                       2703 00109$:
                                   2704 ;	cc1111usb.c:624: usbGetDescriptor(&req);
      00123C 90 00 42         [24] 2705 	mov	dptr,#_handleCS0_req_1_95
      00123F 75 F0 40         [24] 2706 	mov	b,#0x40
      001242 12 0F D7         [24] 2707 	lcall	_usbGetDescriptor
                                   2708 ;	cc1111usb.c:625: break;
      001245 02 13 BB         [24] 2709 	ljmp	00167$
                                   2710 ;	cc1111usb.c:626: case USB_GET_CONFIGURATION: 
      001248                       2711 00110$:
                                   2712 ;	cc1111usb.c:627: usbGetConfiguration(); 
      001248 12 0F 2E         [24] 2713 	lcall	_usbGetConfiguration
                                   2714 ;	cc1111usb.c:628: break;
      00124B 02 13 BB         [24] 2715 	ljmp	00167$
                                   2716 ;	cc1111usb.c:630: case USB_GET_STATUS:
      00124E                       2717 00111$:
                                   2718 ;	cc1111usb.c:631: val = 0;
      00124E E4               [12] 2719 	clr	a
      00124F F5 4A            [12] 2720 	mov	_handleCS0_val_1_95,a
      001251 F5 4B            [12] 2721 	mov	(_handleCS0_val_1_95 + 1),a
                                   2722 ;	cc1111usb.c:632: setup_send_ep0((u8*)&val, 2);
      001253 75 31 02         [24] 2723 	mov	_setup_send_ep0_PARM_2,#0x02
                                   2724 ;	1-genFromRTrack replaced	mov	(_setup_send_ep0_PARM_2 + 1),#0x00
      001256 F5 32            [12] 2725 	mov	(_setup_send_ep0_PARM_2 + 1),a
      001258 90 00 4A         [24] 2726 	mov	dptr,#_handleCS0_val_1_95
      00125B 75 F0 40         [24] 2727 	mov	b,#0x40
      00125E 12 0D 50         [24] 2728 	lcall	_setup_send_ep0
                                   2729 ;	cc1111usb.c:633: break;
      001261 02 13 BB         [24] 2730 	ljmp	00167$
                                   2731 ;	cc1111usb.c:634: default:
      001264                       2732 00112$:
                                   2733 ;	cc1111usb.c:635: debugEP0Req((u8*)&req);
      001264 90 00 42         [24] 2734 	mov	dptr,#_handleCS0_req_1_95
      001267 75 F0 40         [24] 2735 	mov	b,#0x40
      00126A 12 19 B9         [24] 2736 	lcall	_debugEP0Req
                                   2737 ;	cc1111usb.c:636: }
      00126D 02 13 BB         [24] 2738 	ljmp	00167$
      001270                       2739 00129$:
                                   2740 ;	cc1111usb.c:639: else if (loop == USB_BM_REQTYPE_TGT_INTF)
      001270 BE 01 1A         [24] 2741 	cjne	r6,#0x01,00126$
                                   2742 ;	cc1111usb.c:641: switch (req.bRequest){
      001273 AD 43            [24] 2743 	mov	r5,(_handleCS0_req_1_95 + 0x0001)
      001275 BD 00 03         [24] 2744 	cjne	r5,#0x00,00328$
      001278 02 13 BB         [24] 2745 	ljmp	00167$
      00127B                       2746 00328$:
      00127B BD 0A 03         [24] 2747 	cjne	r5,#0x0A,00329$
      00127E 02 13 BB         [24] 2748 	ljmp	00167$
      001281                       2749 00329$:
                                   2750 ;	cc1111usb.c:645: debugEP0Req((u8*)&req);
      001281 90 00 42         [24] 2751 	mov	dptr,#_handleCS0_req_1_95
      001284 75 F0 40         [24] 2752 	mov	b,#0x40
      001287 12 19 B9         [24] 2753 	lcall	_debugEP0Req
                                   2754 ;	cc1111usb.c:646: }
      00128A 02 13 BB         [24] 2755 	ljmp	00167$
      00128D                       2756 00126$:
                                   2757 ;	cc1111usb.c:649: else if (loop == USB_BM_REQTYPE_TGT_EP)
      00128D BE 02 2D         [24] 2758 	cjne	r6,#0x02,00123$
                                   2759 ;	cc1111usb.c:651: switch (req.bRequest){
      001290 AD 43            [24] 2760 	mov	r5,(_handleCS0_req_1_95 + 0x0001)
      001292 BD 00 02         [24] 2761 	cjne	r5,#0x00,00332$
      001295 80 08            [24] 2762 	sjmp	00118$
      001297                       2763 00332$:
      001297 BD 12 03         [24] 2764 	cjne	r5,#0x12,00333$
      00129A 02 13 BB         [24] 2765 	ljmp	00167$
      00129D                       2766 00333$:
                                   2767 ;	cc1111usb.c:652: case USB_GET_STATUS:
      00129D 80 12            [24] 2768 	sjmp	00120$
      00129F                       2769 00118$:
                                   2770 ;	cc1111usb.c:653: setup_send_ep0("\x00\x00", 2);
      00129F 75 31 02         [24] 2771 	mov	_setup_send_ep0_PARM_2,#0x02
      0012A2 75 32 00         [24] 2772 	mov	(_setup_send_ep0_PARM_2 + 1),#0x00
      0012A5 90 1A 87         [24] 2773 	mov	dptr,#___str_0
      0012A8 75 F0 80         [24] 2774 	mov	b,#0x80
      0012AB 12 0D 50         [24] 2775 	lcall	_setup_send_ep0
                                   2776 ;	cc1111usb.c:654: break;
      0012AE 02 13 BB         [24] 2777 	ljmp	00167$
                                   2778 ;	cc1111usb.c:657: default:
      0012B1                       2779 00120$:
                                   2780 ;	cc1111usb.c:658: debugEP0Req((u8*)&req);
      0012B1 90 00 42         [24] 2781 	mov	dptr,#_handleCS0_req_1_95
      0012B4 75 F0 40         [24] 2782 	mov	b,#0x40
      0012B7 12 19 B9         [24] 2783 	lcall	_debugEP0Req
                                   2784 ;	cc1111usb.c:659: }
      0012BA 02 13 BB         [24] 2785 	ljmp	00167$
      0012BD                       2786 00123$:
                                   2787 ;	cc1111usb.c:661: debugEP0Req((u8*)&req);
      0012BD 90 00 42         [24] 2788 	mov	dptr,#_handleCS0_req_1_95
      0012C0 75 F0 40         [24] 2789 	mov	b,#0x40
      0012C3 12 19 B9         [24] 2790 	lcall	_debugEP0Req
                                   2791 ;	cc1111usb.c:662: USBCS0 |= USBCS0_SEND_STALL;
      0012C6 90 DE 11         [24] 2792 	mov	dptr,#_USBCS0
      0012C9 E0               [24] 2793 	movx	a,@dptr
      0012CA FD               [12] 2794 	mov	r5,a
      0012CB 74 20            [12] 2795 	mov	a,#0x20
      0012CD 4D               [12] 2796 	orl	a,r5
      0012CE F0               [24] 2797 	movx	@dptr,a
                                   2798 ;	cc1111usb.c:664: break;
      0012CF 02 13 BB         [24] 2799 	ljmp	00167$
                                   2800 ;	cc1111usb.c:667: case USB_BM_REQTYPE_TYPE_VENDOR:            // VENDOR type
      0012D2                       2801 00132$:
                                   2802 ;	cc1111usb.c:668: appHandleEP0(&req);
      0012D2 90 00 42         [24] 2803 	mov	dptr,#_handleCS0_req_1_95
      0012D5 75 F0 40         [24] 2804 	mov	b,#0x40
      0012D8 12 01 90         [24] 2805 	lcall	_appHandleEP0
                                   2806 ;	cc1111usb.c:669: break;
      0012DB 02 13 BB         [24] 2807 	ljmp	00167$
                                   2808 ;	cc1111usb.c:670: case USB_BM_REQTYPE_TYPE_RESERVED:          // RESERVED
      0012DE                       2809 00133$:
                                   2810 ;	cc1111usb.c:671: USBCS0 |= USBCS0_SEND_STALL;
      0012DE 90 DE 11         [24] 2811 	mov	dptr,#_USBCS0
      0012E1 E0               [24] 2812 	movx	a,@dptr
      0012E2 FD               [12] 2813 	mov	r5,a
      0012E3 74 20            [12] 2814 	mov	a,#0x20
      0012E5 4D               [12] 2815 	orl	a,r5
      0012E6 F0               [24] 2816 	movx	@dptr,a
                                   2817 ;	cc1111usb.c:672: debugEP0Req((u8*)&req);
      0012E7 90 00 42         [24] 2818 	mov	dptr,#_handleCS0_req_1_95
      0012EA 75 F0 40         [24] 2819 	mov	b,#0x40
      0012ED 12 19 B9         [24] 2820 	lcall	_debugEP0Req
                                   2821 ;	cc1111usb.c:673: }
      0012F0 02 13 BB         [24] 2822 	ljmp	00167$
      0012F3                       2823 00166$:
                                   2824 ;	cc1111usb.c:675: switch(req.bmRequestType & USB_BM_REQTYPE_TYPEMASK)
      0012F3 74 60            [12] 2825 	mov	a,#0x60
      0012F5 5F               [12] 2826 	anl	a,r7
      0012F6 FD               [12] 2827 	mov	r5,a
      0012F7 60 15            [24] 2828 	jz	00135$
      0012F9 BD 20 03         [24] 2829 	cjne	r5,#0x20,00335$
      0012FC 02 13 BB         [24] 2830 	ljmp	00167$
      0012FF                       2831 00335$:
      0012FF BD 40 03         [24] 2832 	cjne	r5,#0x40,00336$
      001302 02 13 9E         [24] 2833 	ljmp	00162$
      001305                       2834 00336$:
      001305 BD 60 03         [24] 2835 	cjne	r5,#0x60,00337$
      001308 02 13 A9         [24] 2836 	ljmp	00163$
      00130B                       2837 00337$:
      00130B 02 13 BB         [24] 2838 	ljmp	00167$
                                   2839 ;	cc1111usb.c:677: case USB_BM_REQTYPE_TYPE_STD:               // STANDARD type
      00130E                       2840 00135$:
                                   2841 ;	cc1111usb.c:678: loop = req.bmRequestType & USB_BM_REQTYPE_TGTMASK;
      00130E 74 1F            [12] 2842 	mov	a,#0x1F
      001310 5F               [12] 2843 	anl	a,r7
                                   2844 ;	cc1111usb.c:679: if (loop == USB_BM_REQTYPE_TGT_DEV)
      001311 FE               [12] 2845 	mov	r6,a
      001312 70 3D            [24] 2846 	jnz	00159$
                                   2847 ;	cc1111usb.c:681: switch (req.bRequest){
      001314 AF 43            [24] 2848 	mov	r7,(_handleCS0_req_1_95 + 0x0001)
      001316 BF 01 03         [24] 2849 	cjne	r7,#0x01,00339$
      001319 02 13 BB         [24] 2850 	ljmp	00167$
      00131C                       2851 00339$:
      00131C BF 03 03         [24] 2852 	cjne	r7,#0x03,00340$
      00131F 02 13 BB         [24] 2853 	ljmp	00167$
      001322                       2854 00340$:
      001322 BF 05 02         [24] 2855 	cjne	r7,#0x05,00341$
      001325 80 0B            [24] 2856 	sjmp	00136$
      001327                       2857 00341$:
      001327 BF 07 03         [24] 2858 	cjne	r7,#0x07,00342$
      00132A 02 13 BB         [24] 2859 	ljmp	00167$
      00132D                       2860 00342$:
                                   2861 ;	cc1111usb.c:682: case USB_SET_ADDRESS:
      00132D BF 09 16         [24] 2862 	cjne	r7,#0x09,00141$
      001330 80 09            [24] 2863 	sjmp	00137$
      001332                       2864 00136$:
                                   2865 ;	cc1111usb.c:683: USBADDR = req.wValue;
      001332 90 DE 00         [24] 2866 	mov	dptr,#_USBADDR
      001335 E5 44            [12] 2867 	mov	a,(_handleCS0_req_1_95 + 0x0002)
      001337 F0               [24] 2868 	movx	@dptr,a
                                   2869 ;	cc1111usb.c:684: break;
      001338 02 13 BB         [24] 2870 	ljmp	00167$
                                   2871 ;	cc1111usb.c:685: case USB_SET_CONFIGURATION:
      00133B                       2872 00137$:
                                   2873 ;	cc1111usb.c:686: usbSetConfiguration(&req);
      00133B 90 00 42         [24] 2874 	mov	dptr,#_handleCS0_req_1_95
      00133E 75 F0 40         [24] 2875 	mov	b,#0x40
      001341 12 0F 3D         [24] 2876 	lcall	_usbSetConfiguration
                                   2877 ;	cc1111usb.c:687: break;
                                   2878 ;	cc1111usb.c:695: default:
      001344 80 75            [24] 2879 	sjmp	00167$
      001346                       2880 00141$:
                                   2881 ;	cc1111usb.c:696: debugEP0Req((u8*)&req);
      001346 90 00 42         [24] 2882 	mov	dptr,#_handleCS0_req_1_95
      001349 75 F0 40         [24] 2883 	mov	b,#0x40
      00134C 12 19 B9         [24] 2884 	lcall	_debugEP0Req
                                   2885 ;	cc1111usb.c:697: }
      00134F 80 6A            [24] 2886 	sjmp	00167$
      001351                       2887 00159$:
                                   2888 ;	cc1111usb.c:700: else if (loop == USB_BM_REQTYPE_TGT_INTF)
      001351 BE 01 1C         [24] 2889 	cjne	r6,#0x01,00156$
                                   2890 ;	cc1111usb.c:702: switch (req.bRequest){
      001354 AF 43            [24] 2891 	mov	r7,(_handleCS0_req_1_95 + 0x0001)
      001356 BF 01 02         [24] 2892 	cjne	r7,#0x01,00346$
      001359 80 60            [24] 2893 	sjmp	00167$
      00135B                       2894 00346$:
      00135B BF 03 02         [24] 2895 	cjne	r7,#0x03,00347$
      00135E 80 5B            [24] 2896 	sjmp	00167$
      001360                       2897 00347$:
      001360 BF 11 02         [24] 2898 	cjne	r7,#0x11,00348$
      001363 80 56            [24] 2899 	sjmp	00167$
      001365                       2900 00348$:
                                   2901 ;	cc1111usb.c:707: debugEP0Req((u8*)&req);
      001365 90 00 42         [24] 2902 	mov	dptr,#_handleCS0_req_1_95
      001368 75 F0 40         [24] 2903 	mov	b,#0x40
      00136B 12 19 B9         [24] 2904 	lcall	_debugEP0Req
                                   2905 ;	cc1111usb.c:708: }
      00136E 80 4B            [24] 2906 	sjmp	00167$
      001370                       2907 00156$:
                                   2908 ;	cc1111usb.c:711: else if (loop == USB_BM_REQTYPE_TGT_EP)
      001370 BE 02 17         [24] 2909 	cjne	r6,#0x02,00153$
                                   2910 ;	cc1111usb.c:713: switch (req.bRequest){
      001373 AF 43            [24] 2911 	mov	r7,(_handleCS0_req_1_95 + 0x0001)
      001375 BF 01 02         [24] 2912 	cjne	r7,#0x01,00351$
      001378 80 41            [24] 2913 	sjmp	00167$
      00137A                       2914 00351$:
      00137A BF 03 02         [24] 2915 	cjne	r7,#0x03,00352$
      00137D 80 3C            [24] 2916 	sjmp	00167$
      00137F                       2917 00352$:
                                   2918 ;	cc1111usb.c:717: debugEP0Req((u8*)&req);
      00137F 90 00 42         [24] 2919 	mov	dptr,#_handleCS0_req_1_95
      001382 75 F0 40         [24] 2920 	mov	b,#0x40
      001385 12 19 B9         [24] 2921 	lcall	_debugEP0Req
                                   2922 ;	cc1111usb.c:718: }
      001388 80 31            [24] 2923 	sjmp	00167$
      00138A                       2924 00153$:
                                   2925 ;	cc1111usb.c:720: USBCS0 |= USBCS0_SEND_STALL;
      00138A 90 DE 11         [24] 2926 	mov	dptr,#_USBCS0
      00138D E0               [24] 2927 	movx	a,@dptr
      00138E FF               [12] 2928 	mov	r7,a
      00138F 74 20            [12] 2929 	mov	a,#0x20
      001391 4F               [12] 2930 	orl	a,r7
      001392 F0               [24] 2931 	movx	@dptr,a
                                   2932 ;	cc1111usb.c:721: debugEP0Req((u8*)&req);
      001393 90 00 42         [24] 2933 	mov	dptr,#_handleCS0_req_1_95
      001396 75 F0 40         [24] 2934 	mov	b,#0x40
      001399 12 19 B9         [24] 2935 	lcall	_debugEP0Req
                                   2936 ;	cc1111usb.c:723: break;
                                   2937 ;	cc1111usb.c:726: case USB_BM_REQTYPE_TYPE_VENDOR:            // VENDOR type
      00139C 80 1D            [24] 2938 	sjmp	00167$
      00139E                       2939 00162$:
                                   2940 ;	cc1111usb.c:727: appHandleEP0(&req);
      00139E 90 00 42         [24] 2941 	mov	dptr,#_handleCS0_req_1_95
      0013A1 75 F0 40         [24] 2942 	mov	b,#0x40
      0013A4 12 01 90         [24] 2943 	lcall	_appHandleEP0
                                   2944 ;	cc1111usb.c:728: break;
                                   2945 ;	cc1111usb.c:729: case USB_BM_REQTYPE_TYPE_RESERVED:          // RESERVED type
      0013A7 80 12            [24] 2946 	sjmp	00167$
      0013A9                       2947 00163$:
                                   2948 ;	cc1111usb.c:730: debugEP0Req((u8*)&req);
      0013A9 90 00 42         [24] 2949 	mov	dptr,#_handleCS0_req_1_95
      0013AC 75 F0 40         [24] 2950 	mov	b,#0x40
      0013AF 12 19 B9         [24] 2951 	lcall	_debugEP0Req
                                   2952 ;	cc1111usb.c:731: USBCS0 |= USBCS0_SEND_STALL;
      0013B2 90 DE 11         [24] 2953 	mov	dptr,#_USBCS0
      0013B5 E0               [24] 2954 	movx	a,@dptr
      0013B6 FF               [12] 2955 	mov	r7,a
      0013B7 74 20            [12] 2956 	mov	a,#0x20
      0013B9 4F               [12] 2957 	orl	a,r7
      0013BA F0               [24] 2958 	movx	@dptr,a
                                   2959 ;	cc1111usb.c:732: }
      0013BB                       2960 00167$:
                                   2961 ;	cc1111usb.c:735: USBCS0 |= USBCS0_CLR_OUTPKT_RDY;                    // clear the bit, we got it.
      0013BB 90 DE 11         [24] 2962 	mov	dptr,#_USBCS0
      0013BE E0               [24] 2963 	movx	a,@dptr
      0013BF FF               [12] 2964 	mov	r7,a
      0013C0 74 40            [12] 2965 	mov	a,#0x40
      0013C2 4F               [12] 2966 	orl	a,r7
      0013C3 F0               [24] 2967 	movx	@dptr,a
                                   2968 ;	cc1111usb.c:736: if (req.wLength == 0x0)
      0013C4 E5 48            [12] 2969 	mov	a,(_handleCS0_req_1_95 + 0x0006)
      0013C6 45 49            [12] 2970 	orl	a,((_handleCS0_req_1_95 + 0x0006) + 1)
      0013C8 70 09            [24] 2971 	jnz	00173$
                                   2972 ;	cc1111usb.c:737: USBCS0 |= USBCS0_DATA_END;                      // if the length is 0, signal that we got it and we're good.  (where did i come up with this?!?)
      0013CA 90 DE 11         [24] 2973 	mov	dptr,#_USBCS0
      0013CD E0               [24] 2974 	movx	a,@dptr
      0013CE FF               [12] 2975 	mov	r7,a
      0013CF 74 08            [12] 2976 	mov	a,#0x08
      0013D1 4F               [12] 2977 	orl	a,r7
      0013D2 F0               [24] 2978 	movx	@dptr,a
      0013D3                       2979 00173$:
                                   2980 ;	cc1111usb.c:743: if (ep0iobuf.epstatus == EP_STATE_TX)
      0013D3 90 F1 61         [24] 2981 	mov	dptr,#(_ep0iobuf + 0x000d)
      0013D6 E0               [24] 2982 	movx	a,@dptr
      0013D7 FF               [12] 2983 	mov	r7,a
      0013D8 BF 01 03         [24] 2984 	cjne	r7,#0x01,00175$
                                   2985 ;	cc1111usb.c:745: usb_arm_ep0IN(); 
      0013DB 12 0E 0E         [24] 2986 	lcall	_usb_arm_ep0IN
      0013DE                       2987 00175$:
                                   2988 ;	cc1111usb.c:747: if (ep0iobuf.epstatus == EP_STATE_RX)
      0013DE 90 F1 61         [24] 2989 	mov	dptr,#(_ep0iobuf + 0x000d)
      0013E1 E0               [24] 2990 	movx	a,@dptr
      0013E2 FF               [12] 2991 	mov	r7,a
      0013E3 BF 02 03         [24] 2992 	cjne	r7,#0x02,00180$
                                   2993 ;	cc1111usb.c:749: usb_recv_ep0OUT();
      0013E6 02 0E 9C         [24] 2994 	ljmp	_usb_recv_ep0OUT
      0013E9                       2995 00180$:
      0013E9 22               [24] 2996 	ret
                                   2997 ;------------------------------------------------------------
                                   2998 ;Allocation info for local variables in function 'handleOUTEP5'
                                   2999 ;------------------------------------------------------------
                                   3000 ;loop                      Allocated with name '_handleOUTEP5_loop_1_125'
                                   3001 ;len                       Allocated with name '_handleOUTEP5_len_1_125'
                                   3002 ;cmd                       Allocated with name '_handleOUTEP5_cmd_1_125'
                                   3003 ;app                       Allocated with name '_handleOUTEP5_app_1_125'
                                   3004 ;ptr                       Allocated to registers r6 r7 
                                   3005 ;dptr                      Allocated with name '_handleOUTEP5_dptr_1_125'
                                   3006 ;sloc0                     Allocated with name '_handleOUTEP5_sloc0_1_0'
                                   3007 ;------------------------------------------------------------
                                   3008 ;	cc1111usb.c:754: void handleOUTEP5(void)
                                   3009 ;	-----------------------------------------
                                   3010 ;	 function handleOUTEP5
                                   3011 ;	-----------------------------------------
      0013EA                       3012 _handleOUTEP5:
                                   3013 ;	cc1111usb.c:761: USBINDEX = 5;
      0013EA 90 DE 0E         [24] 3014 	mov	dptr,#_USBINDEX
      0013ED 74 05            [12] 3015 	mov	a,#0x05
      0013EF F0               [24] 3016 	movx	@dptr,a
                                   3017 ;	cc1111usb.c:762: if (ep5iobuf.flags & EP_OUTBUF_WRITTEN)                     // have we processed the last OUTbuf?  don't want to clobber it.
      0013F0 90 F1 6E         [24] 3018 	mov	dptr,#(_ep5iobuf + 0x000c)
      0013F3 E0               [24] 3019 	movx	a,@dptr
      0013F4 FF               [12] 3020 	mov	r7,a
      0013F5 30 E1 16         [24] 3021 	jnb	acc.1,00102$
                                   3022 ;	cc1111usb.c:764: ep5iobuf.epstatus = EP_STATE_STALL;
      0013F8 90 F1 6F         [24] 3023 	mov	dptr,#(_ep5iobuf + 0x000d)
      0013FB 74 03            [12] 3024 	mov	a,#0x03
      0013FD F0               [24] 3025 	movx	@dptr,a
                                   3026 ;	cc1111usb.c:765: USBCSOL |= USBCSOL_SEND_STALL;
      0013FE 90 DE 14         [24] 3027 	mov	dptr,#_USBCSOL
      001401 E0               [24] 3028 	movx	a,@dptr
      001402 FF               [12] 3029 	mov	r7,a
      001403 74 20            [12] 3030 	mov	a,#0x20
      001405 4F               [12] 3031 	orl	a,r7
      001406 F0               [24] 3032 	movx	@dptr,a
                                   3033 ;	cc1111usb.c:767: lastCode[1] = 5;
      001407 90 F0 D3         [24] 3034 	mov	dptr,#(_lastCode + 0x0001)
      00140A 74 05            [12] 3035 	mov	a,#0x05
      00140C F0               [24] 3036 	movx	@dptr,a
                                   3037 ;	cc1111usb.c:768: return;
      00140D 22               [24] 3038 	ret
      00140E                       3039 00102$:
                                   3040 ;	cc1111usb.c:770: ep5iobuf.flags |= EP_OUTBUF_WRITTEN;                        // track that we've read into the OUTbuf
      00140E 90 F1 6E         [24] 3041 	mov	dptr,#(_ep5iobuf + 0x000c)
      001411 E0               [24] 3042 	movx	a,@dptr
      001412 44 02            [12] 3043 	orl	a,#0x02
      001414 F0               [24] 3044 	movx	@dptr,a
                                   3045 ;	cc1111usb.c:773: ptr = &ep5iobuf.OUTbuf[0];
      001415 90 F1 67         [24] 3046 	mov	dptr,#(_ep5iobuf + 0x0005)
      001418 E0               [24] 3047 	movx	a,@dptr
      001419 FE               [12] 3048 	mov	r6,a
      00141A A3               [24] 3049 	inc	dptr
      00141B E0               [24] 3050 	movx	a,@dptr
      00141C FF               [12] 3051 	mov	r7,a
                                   3052 ;	cc1111usb.c:774: while ((DMAIRQ & DMAARM1))
      00141D                       3053 00103$:
      00141D E5 D1            [12] 3054 	mov	a,_DMAIRQ
      00141F 30 E1 1A         [24] 3055 	jnb	acc.1,00105$
                                   3056 ;	cc1111usb.c:775: blink(20,20);
      001422 D2 90            [12] 3057 	setb	_P1_0
      001424 90 00 14         [24] 3058 	mov	dptr,#0x0014
      001427 C0 07            [24] 3059 	push	ar7
      001429 C0 06            [24] 3060 	push	ar6
      00142B 12 09 63         [24] 3061 	lcall	_sleepMillis
      00142E C2 90            [12] 3062 	clr	_P1_0
      001430 90 00 14         [24] 3063 	mov	dptr,#0x0014
      001433 12 09 63         [24] 3064 	lcall	_sleepMillis
      001436 D0 06            [24] 3065 	pop	ar6
      001438 D0 07            [24] 3066 	pop	ar7
      00143A 80 E1            [24] 3067 	sjmp	00103$
      00143C                       3068 00105$:
                                   3069 ;	cc1111usb.c:776: DMAARM |= 0x80 + DMAARM1;
      00143C 43 D6 82         [24] 3070 	orl	_DMAARM,#0x82
                                   3071 ;	cc1111usb.c:777: usbdma.srcAddrH = 0xde;     //USBF5 == 0xde2a
      00143F 90 F1 71         [24] 3072 	mov	dptr,#_usbdma
      001442 74 DE            [12] 3073 	mov	a,#0xDE
      001444 F0               [24] 3074 	movx	@dptr,a
                                   3075 ;	cc1111usb.c:778: usbdma.srcAddrL = 0x2a;
      001445 90 F1 72         [24] 3076 	mov	dptr,#(_usbdma + 0x0001)
      001448 74 2A            [12] 3077 	mov	a,#0x2A
      00144A F0               [24] 3078 	movx	@dptr,a
                                   3079 ;	cc1111usb.c:779: usbdma.destAddrH = ((u16)ptr)>>8;
      00144B 8E 04            [24] 3080 	mov	ar4,r6
      00144D 8F 05            [24] 3081 	mov	ar5,r7
      00144F 8D 03            [24] 3082 	mov	ar3,r5
      001451 90 F1 73         [24] 3083 	mov	dptr,#(_usbdma + 0x0002)
      001454 EB               [12] 3084 	mov	a,r3
      001455 F0               [24] 3085 	movx	@dptr,a
                                   3086 ;	cc1111usb.c:780: usbdma.destAddrL = ((u16)ptr)&0xff;
      001456 90 F1 74         [24] 3087 	mov	dptr,#(_usbdma + 0x0003)
      001459 EC               [12] 3088 	mov	a,r4
      00145A F0               [24] 3089 	movx	@dptr,a
                                   3090 ;	cc1111usb.c:781: usbdma.srcInc = 0;
      00145B 90 F1 78         [24] 3091 	mov	dptr,#(_usbdma + 0x0007)
      00145E E0               [24] 3092 	movx	a,@dptr
      00145F 54 3F            [12] 3093 	anl	a,#0x3F
      001461 F0               [24] 3094 	movx	@dptr,a
                                   3095 ;	cc1111usb.c:782: usbdma.destInc = 1;
      001462 90 F1 78         [24] 3096 	mov	dptr,#(_usbdma + 0x0007)
      001465 E0               [24] 3097 	movx	a,@dptr
      001466 54 CF            [12] 3098 	anl	a,#0xCF
      001468 44 10            [12] 3099 	orl	a,#0x10
      00146A F0               [24] 3100 	movx	@dptr,a
                                   3101 ;	cc1111usb.c:783: usbdma.lenL = USBCNTL;
      00146B 90 DE 16         [24] 3102 	mov	dptr,#_USBCNTL
      00146E E0               [24] 3103 	movx	a,@dptr
      00146F 90 F1 76         [24] 3104 	mov	dptr,#(_usbdma + 0x0005)
      001472 F0               [24] 3105 	movx	@dptr,a
                                   3106 ;	cc1111usb.c:784: usbdma.lenH = USBCNTH;
      001473 90 DE 17         [24] 3107 	mov	dptr,#_USBCNTH
      001476 E0               [24] 3108 	movx	a,@dptr
      001477 90 F1 75         [24] 3109 	mov	dptr,#(_usbdma + 0x0004)
      00147A 54 1F            [12] 3110 	anl	a,#0x1F
      00147C F5 F0            [12] 3111 	mov	b,a
      00147E E0               [24] 3112 	movx	a,@dptr
      00147F 54 E0            [12] 3113 	anl	a,#0xE0
      001481 45 F0            [12] 3114 	orl	a,b
      001483 F0               [24] 3115 	movx	@dptr,a
                                   3116 ;	cc1111usb.c:786: len = (usbdma.lenH<<8)+usbdma.lenL;
      001484 90 F1 75         [24] 3117 	mov	dptr,#(_usbdma + 0x0004)
      001487 E0               [24] 3118 	movx	a,@dptr
      001488 54 1F            [12] 3119 	anl	a,#0x1F
      00148A FC               [12] 3120 	mov	r4,a
      00148B 7D 00            [12] 3121 	mov	r5,#0x00
      00148D 90 F1 76         [24] 3122 	mov	dptr,#(_usbdma + 0x0005)
      001490 E0               [24] 3123 	movx	a,@dptr
      001491 FB               [12] 3124 	mov	r3,a
      001492 7A 00            [12] 3125 	mov	r2,#0x00
      001494 2D               [12] 3126 	add	a,r5
      001495 F5 4E            [12] 3127 	mov	_handleOUTEP5_len_1_125,a
      001497 EA               [12] 3128 	mov	a,r2
      001498 3C               [12] 3129 	addc	a,r4
      001499 F5 4F            [12] 3130 	mov	(_handleOUTEP5_len_1_125 + 1),a
                                   3131 ;	cc1111usb.c:787: if (len > EP5OUT_MAX_PACKET_SIZE)                           // FIXME: if they wanna send too much data, do we accept what we can?  or bomb?
      00149B C3               [12] 3132 	clr	c
      00149C 74 40            [12] 3133 	mov	a,#0x40
      00149E 95 4E            [12] 3134 	subb	a,_handleOUTEP5_len_1_125
      0014A0 E4               [12] 3135 	clr	a
      0014A1 95 4F            [12] 3136 	subb	a,(_handleOUTEP5_len_1_125 + 1)
      0014A3 50 25            [24] 3137 	jnc	00107$
                                   3138 ;	cc1111usb.c:789: ep5iobuf.epstatus = EP_STATE_STALL;
      0014A5 90 F1 6F         [24] 3139 	mov	dptr,#(_ep5iobuf + 0x000d)
      0014A8 74 03            [12] 3140 	mov	a,#0x03
      0014AA F0               [24] 3141 	movx	@dptr,a
                                   3142 ;	cc1111usb.c:790: USBCSOL |= USBCSOL_SEND_STALL;
      0014AB 90 DE 14         [24] 3143 	mov	dptr,#_USBCSOL
      0014AE E0               [24] 3144 	movx	a,@dptr
      0014AF FB               [12] 3145 	mov	r3,a
      0014B0 74 20            [12] 3146 	mov	a,#0x20
      0014B2 4B               [12] 3147 	orl	a,r3
      0014B3 F0               [24] 3148 	movx	@dptr,a
                                   3149 ;	cc1111usb.c:791: USBCSOL &= ~USBCSOL_OUTPKT_RDY;
      0014B4 E0               [24] 3150 	movx	a,@dptr
      0014B5 FB               [12] 3151 	mov	r3,a
      0014B6 74 FE            [12] 3152 	mov	a,#0xFE
      0014B8 5B               [12] 3153 	anl	a,r3
      0014B9 F0               [24] 3154 	movx	@dptr,a
                                   3155 ;	cc1111usb.c:792: blink(300,200);
      0014BA D2 90            [12] 3156 	setb	_P1_0
      0014BC 90 01 2C         [24] 3157 	mov	dptr,#0x012C
      0014BF 12 09 63         [24] 3158 	lcall	_sleepMillis
      0014C2 C2 90            [12] 3159 	clr	_P1_0
      0014C4 90 00 C8         [24] 3160 	mov	dptr,#0x00C8
                                   3161 ;	cc1111usb.c:793: return;
      0014C7 02 09 63         [24] 3162 	ljmp	_sleepMillis
      0014CA                       3163 00107$:
                                   3164 ;	cc1111usb.c:804: DMAARM |= DMAARM1;
      0014CA 43 D6 02         [24] 3165 	orl	_DMAARM,#0x02
                                   3166 ;	cc1111usb.c:805: DMAREQ |= DMAARM1;
      0014CD 43 D7 02         [24] 3167 	orl	_DMAREQ,#0x02
                                   3168 ;	cc1111usb.c:807: while (!(DMAIRQ & DMAARM1));
      0014D0                       3169 00108$:
      0014D0 E5 D1            [12] 3170 	mov	a,_DMAIRQ
      0014D2 30 E1 FB         [24] 3171 	jnb	acc.1,00108$
                                   3172 ;	cc1111usb.c:808: DMAIRQ &= ~DMAARM1;             // FIXME: superfuous?
      0014D5 AB D1            [24] 3173 	mov	r3,_DMAIRQ
      0014D7 74 FD            [12] 3174 	mov	a,#0xFD
      0014D9 5B               [12] 3175 	anl	a,r3
      0014DA F5 D1            [12] 3176 	mov	_DMAIRQ,a
                                   3177 ;	cc1111usb.c:810: ep5iobuf.OUTlen = len;
      0014DC 90 F1 6A         [24] 3178 	mov	dptr,#(_ep5iobuf + 0x0008)
      0014DF E5 4E            [12] 3179 	mov	a,_handleOUTEP5_len_1_125
      0014E1 F0               [24] 3180 	movx	@dptr,a
      0014E2 E5 4F            [12] 3181 	mov	a,(_handleOUTEP5_len_1_125 + 1)
      0014E4 A3               [24] 3182 	inc	dptr
      0014E5 F0               [24] 3183 	movx	@dptr,a
                                   3184 ;	cc1111usb.c:812: if (ep5iobuf.OUTlen >= 8)
      0014E6 C3               [12] 3185 	clr	c
      0014E7 E5 4E            [12] 3186 	mov	a,_handleOUTEP5_len_1_125
      0014E9 94 08            [12] 3187 	subb	a,#0x08
      0014EB E5 4F            [12] 3188 	mov	a,(_handleOUTEP5_len_1_125 + 1)
      0014ED 94 00            [12] 3189 	subb	a,#0x00
      0014EF 50 03            [24] 3190 	jnc	00208$
      0014F1 02 17 6B         [24] 3191 	ljmp	00129$
      0014F4                       3192 00208$:
                                   3193 ;	cc1111usb.c:814: app = ep5iobuf.OUTbuf[4];
      0014F4 90 F1 67         [24] 3194 	mov	dptr,#(_ep5iobuf + 0x0005)
      0014F7 E0               [24] 3195 	movx	a,@dptr
      0014F8 F5 54            [12] 3196 	mov	_handleOUTEP5_sloc0_1_0,a
      0014FA A3               [24] 3197 	inc	dptr
      0014FB E0               [24] 3198 	movx	a,@dptr
      0014FC F5 55            [12] 3199 	mov	(_handleOUTEP5_sloc0_1_0 + 1),a
      0014FE A3               [24] 3200 	inc	dptr
      0014FF E0               [24] 3201 	movx	a,@dptr
      001500 F5 56            [12] 3202 	mov	(_handleOUTEP5_sloc0_1_0 + 2),a
      001502 74 04            [12] 3203 	mov	a,#0x04
      001504 25 54            [12] 3204 	add	a,_handleOUTEP5_sloc0_1_0
      001506 F8               [12] 3205 	mov	r0,a
      001507 E4               [12] 3206 	clr	a
      001508 35 55            [12] 3207 	addc	a,(_handleOUTEP5_sloc0_1_0 + 1)
      00150A FA               [12] 3208 	mov	r2,a
      00150B AB 56            [24] 3209 	mov	r3,(_handleOUTEP5_sloc0_1_0 + 2)
      00150D 88 82            [24] 3210 	mov	dpl,r0
      00150F 8A 83            [24] 3211 	mov	dph,r2
      001511 8B F0            [24] 3212 	mov	b,r3
      001513 12 1A 67         [24] 3213 	lcall	__gptrget
      001516 F5 51            [12] 3214 	mov	_handleOUTEP5_app_1_125,a
                                   3215 ;	cc1111usb.c:815: cmd = ep5iobuf.OUTbuf[5];
      001518 74 05            [12] 3216 	mov	a,#0x05
      00151A 25 54            [12] 3217 	add	a,_handleOUTEP5_sloc0_1_0
      00151C F8               [12] 3218 	mov	r0,a
      00151D E4               [12] 3219 	clr	a
      00151E 35 55            [12] 3220 	addc	a,(_handleOUTEP5_sloc0_1_0 + 1)
      001520 F9               [12] 3221 	mov	r1,a
      001521 AA 56            [24] 3222 	mov	r2,(_handleOUTEP5_sloc0_1_0 + 2)
      001523 88 82            [24] 3223 	mov	dpl,r0
      001525 89 83            [24] 3224 	mov	dph,r1
      001527 8A F0            [24] 3225 	mov	b,r2
      001529 12 1A 67         [24] 3226 	lcall	__gptrget
      00152C F5 50            [12] 3227 	mov	_handleOUTEP5_cmd_1_125,a
                                   3228 ;	cc1111usb.c:816: ptr = &ep5iobuf.OUTbuf[6];
      00152E 74 06            [12] 3229 	mov	a,#0x06
      001530 25 54            [12] 3230 	add	a,_handleOUTEP5_sloc0_1_0
      001532 FE               [12] 3231 	mov	r6,a
      001533 E4               [12] 3232 	clr	a
      001534 35 55            [12] 3233 	addc	a,(_handleOUTEP5_sloc0_1_0 + 1)
      001536 FF               [12] 3234 	mov	r7,a
                                   3235 ;	cc1111usb.c:817: len =  (u16)*ptr++;
      001537 8E 82            [24] 3236 	mov	dpl,r6
      001539 8F 83            [24] 3237 	mov	dph,r7
      00153B E0               [24] 3238 	movx	a,@dptr
      00153C F9               [12] 3239 	mov	r1,a
      00153D A3               [24] 3240 	inc	dptr
                                   3241 ;	cc1111usb.c:818: len += (u16)*ptr++ << 8;
      00153E 89 4E            [24] 3242 	mov	_handleOUTEP5_len_1_125,r1
      001540 75 4F 00         [24] 3243 	mov	(_handleOUTEP5_len_1_125 + 1),#0x00
      001543 E0               [24] 3244 	movx	a,@dptr
      001544 F9               [12] 3245 	mov	r1,a
      001545 A3               [24] 3246 	inc	dptr
      001546 AE 82            [24] 3247 	mov	r6,dpl
      001548 AF 83            [24] 3248 	mov	r7,dph
      00154A 89 00            [24] 3249 	mov	ar0,r1
      00154C 88 01            [24] 3250 	mov	ar1,r0
      00154E E4               [12] 3251 	clr	a
      00154F F8               [12] 3252 	mov	r0,a
      001550 25 4E            [12] 3253 	add	a,_handleOUTEP5_len_1_125
      001552 F5 4E            [12] 3254 	mov	_handleOUTEP5_len_1_125,a
      001554 E9               [12] 3255 	mov	a,r1
      001555 35 4F            [12] 3256 	addc	a,(_handleOUTEP5_len_1_125 + 1)
      001557 F5 4F            [12] 3257 	mov	(_handleOUTEP5_len_1_125 + 1),a
                                   3258 ;	cc1111usb.c:821: if (app == 0xff)                                        // system application
      001559 74 FF            [12] 3259 	mov	a,#0xFF
      00155B B5 51 02         [24] 3260 	cjne	a,_handleOUTEP5_app_1_125,00209$
      00155E 80 03            [24] 3261 	sjmp	00210$
      001560                       3262 00209$:
      001560 02 17 66         [24] 3263 	ljmp	00126$
      001563                       3264 00210$:
                                   3265 ;	cc1111usb.c:824: switch (cmd)
      001563 74 80            [12] 3266 	mov	a,#0x80
      001565 B5 50 02         [24] 3267 	cjne	a,_handleOUTEP5_cmd_1_125,00211$
      001568 80 2A            [24] 3268 	sjmp	00111$
      00156A                       3269 00211$:
      00156A 74 81            [12] 3270 	mov	a,#0x81
      00156C B5 50 02         [24] 3271 	cjne	a,_handleOUTEP5_cmd_1_125,00212$
      00156F 80 7A            [24] 3272 	sjmp	00112$
      001571                       3273 00212$:
      001571 74 82            [12] 3274 	mov	a,#0x82
      001573 B5 50 03         [24] 3275 	cjne	a,_handleOUTEP5_cmd_1_125,00213$
      001576 02 16 D1         [24] 3276 	ljmp	00116$
      001579                       3277 00213$:
      001579 74 83            [12] 3278 	mov	a,#0x83
      00157B B5 50 03         [24] 3279 	cjne	a,_handleOUTEP5_cmd_1_125,00214$
      00157E 02 16 E6         [24] 3280 	ljmp	00117$
      001581                       3281 00214$:
      001581 74 84            [12] 3282 	mov	a,#0x84
      001583 B5 50 03         [24] 3283 	cjne	a,_handleOUTEP5_cmd_1_125,00215$
      001586 02 16 69         [24] 3284 	ljmp	00114$
      001589                       3285 00215$:
      001589 74 85            [12] 3286 	mov	a,#0x85
      00158B B5 50 03         [24] 3287 	cjne	a,_handleOUTEP5_cmd_1_125,00216$
      00158E 02 16 FD         [24] 3288 	ljmp	00118$
      001591                       3289 00216$:
      001591 02 17 49         [24] 3290 	ljmp	00123$
                                   3291 ;	cc1111usb.c:826: case CMD_PEEK:
      001594                       3292 00111$:
                                   3293 ;	cc1111usb.c:827: len =  *ptr++;
      001594 8E 82            [24] 3294 	mov	dpl,r6
      001596 8F 83            [24] 3295 	mov	dph,r7
      001598 E0               [24] 3296 	movx	a,@dptr
      001599 F9               [12] 3297 	mov	r1,a
      00159A A3               [24] 3298 	inc	dptr
                                   3299 ;	cc1111usb.c:828: len += *ptr++ << 8;
      00159B 89 4E            [24] 3300 	mov	_handleOUTEP5_len_1_125,r1
      00159D 75 4F 00         [24] 3301 	mov	(_handleOUTEP5_len_1_125 + 1),#0x00
      0015A0 E0               [24] 3302 	movx	a,@dptr
      0015A1 F9               [12] 3303 	mov	r1,a
      0015A2 A3               [24] 3304 	inc	dptr
      0015A3 AE 82            [24] 3305 	mov	r6,dpl
      0015A5 AF 83            [24] 3306 	mov	r7,dph
      0015A7 89 00            [24] 3307 	mov	ar0,r1
      0015A9 88 01            [24] 3308 	mov	ar1,r0
      0015AB E4               [12] 3309 	clr	a
      0015AC F8               [12] 3310 	mov	r0,a
      0015AD 25 4E            [12] 3311 	add	a,_handleOUTEP5_len_1_125
      0015AF F5 4E            [12] 3312 	mov	_handleOUTEP5_len_1_125,a
      0015B1 E9               [12] 3313 	mov	a,r1
      0015B2 35 4F            [12] 3314 	addc	a,(_handleOUTEP5_len_1_125 + 1)
      0015B4 F5 4F            [12] 3315 	mov	(_handleOUTEP5_len_1_125 + 1),a
                                   3316 ;	cc1111usb.c:829: loop =  (u16)*ptr++;                                    // just using loop for our immediate purpose.  sorry.
      0015B6 8E 82            [24] 3317 	mov	dpl,r6
      0015B8 8F 83            [24] 3318 	mov	dph,r7
      0015BA E0               [24] 3319 	movx	a,@dptr
      0015BB F9               [12] 3320 	mov	r1,a
      0015BC A3               [24] 3321 	inc	dptr
                                   3322 ;	1-genFromRTrack replaced	mov	(_handleOUTEP5_loop_1_125 + 1),#0x00
                                   3323 ;	cc1111usb.c:830: loop += (u16)*ptr++ << 8;                               // hack, but it works
      0015BD 89 4C            [24] 3324 	mov	_handleOUTEP5_loop_1_125,r1
      0015BF 88 4D            [24] 3325 	mov	(_handleOUTEP5_loop_1_125 + 1),r0
      0015C1 E0               [24] 3326 	movx	a,@dptr
      0015C2 F9               [12] 3327 	mov	r1,a
      0015C3 E4               [12] 3328 	clr	a
      0015C4 25 4C            [12] 3329 	add	a,_handleOUTEP5_loop_1_125
      0015C6 F5 4C            [12] 3330 	mov	_handleOUTEP5_loop_1_125,a
      0015C8 E9               [12] 3331 	mov	a,r1
      0015C9 35 4D            [12] 3332 	addc	a,(_handleOUTEP5_loop_1_125 + 1)
      0015CB F5 4D            [12] 3333 	mov	(_handleOUTEP5_loop_1_125 + 1),a
                                   3334 ;	cc1111usb.c:831: dptr = (__xdata u8*) loop;
      0015CD 85 4C 52         [24] 3335 	mov	_handleOUTEP5_dptr_1_125,_handleOUTEP5_loop_1_125
      0015D0 85 4D 53         [24] 3336 	mov	(_handleOUTEP5_dptr_1_125 + 1),(_handleOUTEP5_loop_1_125 + 1)
                                   3337 ;	cc1111usb.c:832: txdata(app, cmd, len, dptr);
      0015D3 85 50 2C         [24] 3338 	mov	_txdata_PARM_2,_handleOUTEP5_cmd_1_125
      0015D6 85 4E 2D         [24] 3339 	mov	_txdata_PARM_3,_handleOUTEP5_len_1_125
      0015D9 85 4F 2E         [24] 3340 	mov	(_txdata_PARM_3 + 1),(_handleOUTEP5_len_1_125 + 1)
      0015DC 85 52 2F         [24] 3341 	mov	_txdata_PARM_4,_handleOUTEP5_dptr_1_125
      0015DF 85 53 30         [24] 3342 	mov	(_txdata_PARM_4 + 1),(_handleOUTEP5_dptr_1_125 + 1)
      0015E2 85 51 82         [24] 3343 	mov	dpl,_handleOUTEP5_app_1_125
      0015E5 12 0B 01         [24] 3344 	lcall	_txdata
                                   3345 ;	cc1111usb.c:835: break;
      0015E8 02 17 5C         [24] 3346 	ljmp	00124$
                                   3347 ;	cc1111usb.c:836: case CMD_POKE:
      0015EB                       3348 00112$:
                                   3349 ;	cc1111usb.c:837: loop =  *ptr++;
      0015EB 8E 82            [24] 3350 	mov	dpl,r6
      0015ED 8F 83            [24] 3351 	mov	dph,r7
      0015EF E0               [24] 3352 	movx	a,@dptr
      0015F0 FB               [12] 3353 	mov	r3,a
      0015F1 A3               [24] 3354 	inc	dptr
                                   3355 ;	cc1111usb.c:838: loop += *ptr++ << 8;                                    // just using loop for our immediate purpose.  sorry.
      0015F2 8B 4C            [24] 3356 	mov	_handleOUTEP5_loop_1_125,r3
      0015F4 75 4D 00         [24] 3357 	mov	(_handleOUTEP5_loop_1_125 + 1),#0x00
      0015F7 E0               [24] 3358 	movx	a,@dptr
      0015F8 FB               [12] 3359 	mov	r3,a
      0015F9 A3               [24] 3360 	inc	dptr
      0015FA AE 82            [24] 3361 	mov	r6,dpl
      0015FC AF 83            [24] 3362 	mov	r7,dph
      0015FE 8B 02            [24] 3363 	mov	ar2,r3
      001600 8A 03            [24] 3364 	mov	ar3,r2
      001602 E4               [12] 3365 	clr	a
      001603 25 4C            [12] 3366 	add	a,_handleOUTEP5_loop_1_125
      001605 F5 4C            [12] 3367 	mov	_handleOUTEP5_loop_1_125,a
      001607 EB               [12] 3368 	mov	a,r3
      001608 35 4D            [12] 3369 	addc	a,(_handleOUTEP5_loop_1_125 + 1)
      00160A F5 4D            [12] 3370 	mov	(_handleOUTEP5_loop_1_125 + 1),a
                                   3371 ;	cc1111usb.c:839: dptr = (__xdata u8*) loop;                                // hack, but it works
      00160C 85 4C 52         [24] 3372 	mov	_handleOUTEP5_dptr_1_125,_handleOUTEP5_loop_1_125
      00160F 85 4D 53         [24] 3373 	mov	(_handleOUTEP5_dptr_1_125 + 1),(_handleOUTEP5_loop_1_125 + 1)
                                   3374 ;	cc1111usb.c:841: for (loop=2;loop<len;loop++)
      001612 8E 02            [24] 3375 	mov	ar2,r6
      001614 8F 03            [24] 3376 	mov	ar3,r7
      001616 85 52 54         [24] 3377 	mov	_handleOUTEP5_sloc0_1_0,_handleOUTEP5_dptr_1_125
      001619 85 53 55         [24] 3378 	mov	(_handleOUTEP5_sloc0_1_0 + 1),(_handleOUTEP5_dptr_1_125 + 1)
      00161C 75 4C 02         [24] 3379 	mov	_handleOUTEP5_loop_1_125,#0x02
      00161F 75 4D 00         [24] 3380 	mov	(_handleOUTEP5_loop_1_125 + 1),#0x00
      001622                       3381 00132$:
      001622 C3               [12] 3382 	clr	c
      001623 E5 4C            [12] 3383 	mov	a,_handleOUTEP5_loop_1_125
      001625 95 4E            [12] 3384 	subb	a,_handleOUTEP5_len_1_125
      001627 E5 4D            [12] 3385 	mov	a,(_handleOUTEP5_loop_1_125 + 1)
      001629 95 4F            [12] 3386 	subb	a,(_handleOUTEP5_len_1_125 + 1)
      00162B 50 24            [24] 3387 	jnc	00113$
                                   3388 ;	cc1111usb.c:843: *dptr++ = *ptr++;
      00162D 8A 82            [24] 3389 	mov	dpl,r2
      00162F 8B 83            [24] 3390 	mov	dph,r3
      001631 E0               [24] 3391 	movx	a,@dptr
      001632 FD               [12] 3392 	mov	r5,a
      001633 A3               [24] 3393 	inc	dptr
      001634 AA 82            [24] 3394 	mov	r2,dpl
      001636 AB 83            [24] 3395 	mov	r3,dph
      001638 85 54 82         [24] 3396 	mov	dpl,_handleOUTEP5_sloc0_1_0
      00163B 85 55 83         [24] 3397 	mov	dph,(_handleOUTEP5_sloc0_1_0 + 1)
      00163E ED               [12] 3398 	mov	a,r5
      00163F F0               [24] 3399 	movx	@dptr,a
      001640 A3               [24] 3400 	inc	dptr
      001641 85 82 54         [24] 3401 	mov	_handleOUTEP5_sloc0_1_0,dpl
      001644 85 83 55         [24] 3402 	mov	(_handleOUTEP5_sloc0_1_0 + 1),dph
                                   3403 ;	cc1111usb.c:841: for (loop=2;loop<len;loop++)
      001647 05 4C            [12] 3404 	inc	_handleOUTEP5_loop_1_125
      001649 E4               [12] 3405 	clr	a
      00164A B5 4C D5         [24] 3406 	cjne	a,_handleOUTEP5_loop_1_125,00132$
      00164D 05 4D            [12] 3407 	inc	(_handleOUTEP5_loop_1_125 + 1)
      00164F 80 D1            [24] 3408 	sjmp	00132$
      001651                       3409 00113$:
                                   3410 ;	cc1111usb.c:845: txdata(app, cmd, 1, (__xdata u8*)"0");
      001651 75 2F 8A         [24] 3411 	mov	_txdata_PARM_4,#___str_1
      001654 75 30 1A         [24] 3412 	mov	(_txdata_PARM_4 + 1),#(___str_1 >> 8)
      001657 85 50 2C         [24] 3413 	mov	_txdata_PARM_2,_handleOUTEP5_cmd_1_125
      00165A 75 2D 01         [24] 3414 	mov	_txdata_PARM_3,#0x01
      00165D 75 2E 00         [24] 3415 	mov	(_txdata_PARM_3 + 1),#0x00
      001660 85 51 82         [24] 3416 	mov	dpl,_handleOUTEP5_app_1_125
      001663 12 0B 01         [24] 3417 	lcall	_txdata
                                   3418 ;	cc1111usb.c:847: break;
      001666 02 17 5C         [24] 3419 	ljmp	00124$
                                   3420 ;	cc1111usb.c:848: case CMD_POKE_REG:
      001669                       3421 00114$:
                                   3422 ;	cc1111usb.c:849: loop =  *ptr++;
      001669 8E 82            [24] 3423 	mov	dpl,r6
      00166B 8F 83            [24] 3424 	mov	dph,r7
      00166D E0               [24] 3425 	movx	a,@dptr
      00166E FD               [12] 3426 	mov	r5,a
      00166F A3               [24] 3427 	inc	dptr
                                   3428 ;	cc1111usb.c:850: loop += *ptr++ << 8;                                    // just using loop for our immediate purpose.  sorry.
      001670 8D 4C            [24] 3429 	mov	_handleOUTEP5_loop_1_125,r5
      001672 75 4D 00         [24] 3430 	mov	(_handleOUTEP5_loop_1_125 + 1),#0x00
      001675 E0               [24] 3431 	movx	a,@dptr
      001676 FD               [12] 3432 	mov	r5,a
      001677 A3               [24] 3433 	inc	dptr
      001678 AE 82            [24] 3434 	mov	r6,dpl
      00167A AF 83            [24] 3435 	mov	r7,dph
      00167C 8D 04            [24] 3436 	mov	ar4,r5
      00167E E4               [12] 3437 	clr	a
      00167F 25 4C            [12] 3438 	add	a,_handleOUTEP5_loop_1_125
      001681 F5 4C            [12] 3439 	mov	_handleOUTEP5_loop_1_125,a
      001683 EC               [12] 3440 	mov	a,r4
      001684 35 4D            [12] 3441 	addc	a,(_handleOUTEP5_loop_1_125 + 1)
      001686 F5 4D            [12] 3442 	mov	(_handleOUTEP5_loop_1_125 + 1),a
                                   3443 ;	cc1111usb.c:851: dptr = (__xdata u8*) loop;                                // hack, but it works
      001688 85 4C 52         [24] 3444 	mov	_handleOUTEP5_dptr_1_125,_handleOUTEP5_loop_1_125
      00168B 85 4D 53         [24] 3445 	mov	(_handleOUTEP5_dptr_1_125 + 1),(_handleOUTEP5_loop_1_125 + 1)
                                   3446 ;	cc1111usb.c:852: for (loop=2;loop<len;loop++)
      00168E 8E 04            [24] 3447 	mov	ar4,r6
      001690 8F 05            [24] 3448 	mov	ar5,r7
      001692 7A 02            [12] 3449 	mov	r2,#0x02
      001694 7B 00            [12] 3450 	mov	r3,#0x00
      001696                       3451 00135$:
      001696 C3               [12] 3452 	clr	c
      001697 EA               [12] 3453 	mov	a,r2
      001698 95 4E            [12] 3454 	subb	a,_handleOUTEP5_len_1_125
      00169A EB               [12] 3455 	mov	a,r3
      00169B 95 4F            [12] 3456 	subb	a,(_handleOUTEP5_len_1_125 + 1)
      00169D 50 1A            [24] 3457 	jnc	00115$
                                   3458 ;	cc1111usb.c:854: *dptr = *ptr++;
      00169F 8C 82            [24] 3459 	mov	dpl,r4
      0016A1 8D 83            [24] 3460 	mov	dph,r5
      0016A3 E0               [24] 3461 	movx	a,@dptr
      0016A4 F9               [12] 3462 	mov	r1,a
      0016A5 A3               [24] 3463 	inc	dptr
      0016A6 AC 82            [24] 3464 	mov	r4,dpl
      0016A8 AD 83            [24] 3465 	mov	r5,dph
      0016AA 85 52 82         [24] 3466 	mov	dpl,_handleOUTEP5_dptr_1_125
      0016AD 85 53 83         [24] 3467 	mov	dph,(_handleOUTEP5_dptr_1_125 + 1)
      0016B0 E9               [12] 3468 	mov	a,r1
      0016B1 F0               [24] 3469 	movx	@dptr,a
                                   3470 ;	cc1111usb.c:852: for (loop=2;loop<len;loop++)
      0016B2 0A               [12] 3471 	inc	r2
      0016B3 BA 00 E0         [24] 3472 	cjne	r2,#0x00,00135$
      0016B6 0B               [12] 3473 	inc	r3
      0016B7 80 DD            [24] 3474 	sjmp	00135$
      0016B9                       3475 00115$:
                                   3476 ;	cc1111usb.c:856: txdata(app, cmd, 1, (__xdata u8*)"");
      0016B9 75 2F 8C         [24] 3477 	mov	_txdata_PARM_4,#___str_2
      0016BC 75 30 1A         [24] 3478 	mov	(_txdata_PARM_4 + 1),#(___str_2 >> 8)
      0016BF 85 50 2C         [24] 3479 	mov	_txdata_PARM_2,_handleOUTEP5_cmd_1_125
      0016C2 75 2D 01         [24] 3480 	mov	_txdata_PARM_3,#0x01
      0016C5 75 2E 00         [24] 3481 	mov	(_txdata_PARM_3 + 1),#0x00
      0016C8 85 51 82         [24] 3482 	mov	dpl,_handleOUTEP5_app_1_125
      0016CB 12 0B 01         [24] 3483 	lcall	_txdata
                                   3484 ;	cc1111usb.c:858: break;
      0016CE 02 17 5C         [24] 3485 	ljmp	00124$
                                   3486 ;	cc1111usb.c:859: case CMD_PING:
      0016D1                       3487 00116$:
                                   3488 ;	cc1111usb.c:860: txdata(app,cmd,len,ptr);
      0016D1 85 50 2C         [24] 3489 	mov	_txdata_PARM_2,_handleOUTEP5_cmd_1_125
      0016D4 85 4E 2D         [24] 3490 	mov	_txdata_PARM_3,_handleOUTEP5_len_1_125
      0016D7 85 4F 2E         [24] 3491 	mov	(_txdata_PARM_3 + 1),(_handleOUTEP5_len_1_125 + 1)
      0016DA 8E 2F            [24] 3492 	mov	_txdata_PARM_4,r6
      0016DC 8F 30            [24] 3493 	mov	(_txdata_PARM_4 + 1),r7
      0016DE 85 51 82         [24] 3494 	mov	dpl,_handleOUTEP5_app_1_125
      0016E1 12 0B 01         [24] 3495 	lcall	_txdata
                                   3496 ;	cc1111usb.c:862: break;
                                   3497 ;	cc1111usb.c:863: case CMD_STATUS:
      0016E4 80 76            [24] 3498 	sjmp	00124$
      0016E6                       3499 00117$:
                                   3500 ;	cc1111usb.c:864: txdata(app, cmd, 13, (__xdata u8*)"UNIMPLEMENTED");
      0016E6 75 2F 8D         [24] 3501 	mov	_txdata_PARM_4,#___str_3
      0016E9 75 30 1A         [24] 3502 	mov	(_txdata_PARM_4 + 1),#(___str_3 >> 8)
      0016EC 85 50 2C         [24] 3503 	mov	_txdata_PARM_2,_handleOUTEP5_cmd_1_125
      0016EF 75 2D 0D         [24] 3504 	mov	_txdata_PARM_3,#0x0D
      0016F2 75 2E 00         [24] 3505 	mov	(_txdata_PARM_3 + 1),#0x00
      0016F5 85 51 82         [24] 3506 	mov	dpl,_handleOUTEP5_app_1_125
      0016F8 12 0B 01         [24] 3507 	lcall	_txdata
                                   3508 ;	cc1111usb.c:866: break;
                                   3509 ;	cc1111usb.c:867: case CMD_RFMODE:
      0016FB 80 5F            [24] 3510 	sjmp	00124$
      0016FD                       3511 00118$:
                                   3512 ;	cc1111usb.c:869: switch (*ptr++)
      0016FD 8E 82            [24] 3513 	mov	dpl,r6
      0016FF 8F 83            [24] 3514 	mov	dph,r7
      001701 E0               [24] 3515 	movx	a,@dptr
      001702 FD               [12] 3516 	mov	r5,a
      001703 A3               [24] 3517 	inc	dptr
      001704 AE 82            [24] 3518 	mov	r6,dpl
      001706 AF 83            [24] 3519 	mov	r7,dph
      001708 BD 01 02         [24] 3520 	cjne	r5,#0x01,00221$
      00170B 80 0A            [24] 3521 	sjmp	00119$
      00170D                       3522 00221$:
      00170D BD 02 02         [24] 3523 	cjne	r5,#0x02,00222$
      001710 80 1F            [24] 3524 	sjmp	00121$
      001712                       3525 00222$:
                                   3526 ;	cc1111usb.c:871: case RF_STATE_RX:
      001712 BD 03 34         [24] 3527 	cjne	r5,#0x03,00123$
      001715 80 0D            [24] 3528 	sjmp	00120$
      001717                       3529 00119$:
                                   3530 ;	cc1111usb.c:872: RxOn(); 
      001717 C0 07            [24] 3531 	push	ar7
      001719 C0 06            [24] 3532 	push	ar6
      00171B 12 07 1B         [24] 3533 	lcall	_RxOn
      00171E D0 06            [24] 3534 	pop	ar6
      001720 D0 07            [24] 3535 	pop	ar7
                                   3536 ;	cc1111usb.c:873: break;
                                   3537 ;	cc1111usb.c:874: case RF_STATE_IDLE:
      001722 80 25            [24] 3538 	sjmp	00123$
      001724                       3539 00120$:
                                   3540 ;	cc1111usb.c:875: setRFIdle();  
      001724 C0 07            [24] 3541 	push	ar7
      001726 C0 06            [24] 3542 	push	ar6
      001728 12 04 52         [24] 3543 	lcall	_setRFIdle
      00172B D0 06            [24] 3544 	pop	ar6
      00172D D0 07            [24] 3545 	pop	ar7
                                   3546 ;	cc1111usb.c:876: break;
                                   3547 ;	cc1111usb.c:877: case RF_STATE_TX:
      00172F 80 18            [24] 3548 	sjmp	00123$
      001731                       3549 00121$:
                                   3550 ;	cc1111usb.c:878: transmit(ptr, len, 0);  
      001731 85 4E 0A         [24] 3551 	mov	_transmit_PARM_2,_handleOUTEP5_len_1_125
      001734 85 4F 0B         [24] 3552 	mov	(_transmit_PARM_2 + 1),(_handleOUTEP5_len_1_125 + 1)
      001737 75 0C 00         [24] 3553 	mov	_transmit_PARM_3,#0x00
      00173A 8E 82            [24] 3554 	mov	dpl,r6
      00173C 8F 83            [24] 3555 	mov	dph,r7
      00173E C0 07            [24] 3556 	push	ar7
      001740 C0 06            [24] 3557 	push	ar6
      001742 12 04 99         [24] 3558 	lcall	_transmit
      001745 D0 06            [24] 3559 	pop	ar6
      001747 D0 07            [24] 3560 	pop	ar7
                                   3561 ;	cc1111usb.c:881: default:
      001749                       3562 00123$:
                                   3563 ;	cc1111usb.c:882: txdata(app,cmd,len,ptr);
      001749 85 50 2C         [24] 3564 	mov	_txdata_PARM_2,_handleOUTEP5_cmd_1_125
      00174C 85 4E 2D         [24] 3565 	mov	_txdata_PARM_3,_handleOUTEP5_len_1_125
      00174F 85 4F 2E         [24] 3566 	mov	(_txdata_PARM_3 + 1),(_handleOUTEP5_len_1_125 + 1)
      001752 8E 2F            [24] 3567 	mov	_txdata_PARM_4,r6
      001754 8F 30            [24] 3568 	mov	(_txdata_PARM_4 + 1),r7
      001756 85 51 82         [24] 3569 	mov	dpl,_handleOUTEP5_app_1_125
      001759 12 0B 01         [24] 3570 	lcall	_txdata
                                   3571 ;	cc1111usb.c:883: }
      00175C                       3572 00124$:
                                   3573 ;	cc1111usb.c:884: ep5iobuf.flags &= ~EP_OUTBUF_WRITTEN; 
      00175C 90 F1 6E         [24] 3574 	mov	dptr,#(_ep5iobuf + 0x000c)
      00175F E0               [24] 3575 	movx	a,@dptr
      001760 54 FD            [12] 3576 	anl	a,#0xFD
      001762 FF               [12] 3577 	mov	r7,a
      001763 F0               [24] 3578 	movx	@dptr,a
      001764 80 0B            [24] 3579 	sjmp	00130$
      001766                       3580 00126$:
                                   3581 ;	cc1111usb.c:887: appHandleEP5();                                         // must clear this flag:   ep5iobuf.flags &= ~EP_OUTBUF_WRITTEN; 
      001766 12 01 84         [24] 3582 	lcall	_appHandleEP5
      001769 80 06            [24] 3583 	sjmp	00130$
      00176B                       3584 00129$:
                                   3585 ;	cc1111usb.c:889: lastCode[1] = 7;                                            // got crap...
      00176B 90 F0 D3         [24] 3586 	mov	dptr,#(_lastCode + 0x0001)
      00176E 74 07            [12] 3587 	mov	a,#0x07
      001770 F0               [24] 3588 	movx	@dptr,a
      001771                       3589 00130$:
                                   3590 ;	cc1111usb.c:891: USBCSOL &= ~USBCSOL_OUTPKT_RDY;
      001771 90 DE 14         [24] 3591 	mov	dptr,#_USBCSOL
      001774 E0               [24] 3592 	movx	a,@dptr
      001775 FF               [12] 3593 	mov	r7,a
      001776 74 FE            [12] 3594 	mov	a,#0xFE
      001778 5F               [12] 3595 	anl	a,r7
      001779 F0               [24] 3596 	movx	@dptr,a
      00177A 22               [24] 3597 	ret
                                   3598 ;------------------------------------------------------------
                                   3599 ;Allocation info for local variables in function 'usbProcessEvents'
                                   3600 ;------------------------------------------------------------
                                   3601 ;	cc1111usb.c:902: void usbProcessEvents(void)
                                   3602 ;	-----------------------------------------
                                   3603 ;	 function usbProcessEvents
                                   3604 ;	-----------------------------------------
      00177B                       3605 _usbProcessEvents:
                                   3606 ;	cc1111usb.c:905: if (usb_data.event & (USBD_IIF_EP0IF))
      00177B E5 23            [12] 3607 	mov	a,(_usb_data + 0x0001)
      00177D 30 E4 11         [24] 3608 	jnb	acc.4,00102$
                                   3609 ;	cc1111usb.c:908: handleCS0();
      001780 12 11 67         [24] 3610 	lcall	_handleCS0
                                   3611 ;	cc1111usb.c:909: usb_data.event &= 0xfe7;
      001783 74 E7            [12] 3612 	mov	a,#0xE7
      001785 55 23            [12] 3613 	anl	a,(_usb_data + 0x0001)
      001787 FE               [12] 3614 	mov	r6,a
      001788 74 0F            [12] 3615 	mov	a,#0x0F
      00178A 55 24            [12] 3616 	anl	a,((_usb_data + 0x0001) + 1)
      00178C FF               [12] 3617 	mov	r7,a
      00178D 8E 23            [24] 3618 	mov	((_usb_data + 0x0001) + 0),r6
      00178F 8F 24            [24] 3619 	mov	((_usb_data + 0x0001) + 1),r7
      001791                       3620 00102$:
                                   3621 ;	cc1111usb.c:914: if (usb_data.event & USBD_CIF_SUSPEND) {
      001791 E5 23            [12] 3622 	mov	a,(_usb_data + 0x0001)
      001793 30 E0 11         [24] 3623 	jnb	acc.0,00104$
                                   3624 ;	cc1111usb.c:915: usb_data.usbstatus = USB_STATE_SUSPEND;
      001796 75 22 01         [24] 3625 	mov	_usb_data,#0x01
                                   3626 ;	cc1111usb.c:916: usb_data.event    &= ~USBD_CIF_SUSPEND;
      001799 74 FE            [12] 3627 	mov	a,#0xFE
      00179B 55 23            [12] 3628 	anl	a,(_usb_data + 0x0001)
      00179D FE               [12] 3629 	mov	r6,a
      00179E AF 24            [24] 3630 	mov	r7,((_usb_data + 0x0001) + 1)
      0017A0 8E 23            [24] 3631 	mov	((_usb_data + 0x0001) + 0),r6
      0017A2 8F 24            [24] 3632 	mov	((_usb_data + 0x0001) + 1),r7
                                   3633 ;	cc1111usb.c:917: PM1();                                               // sir, if you'll not be needing me i'll close down for a while.  sure go ahead.
      0017A4 43 BE 01         [24] 3634 	orl	_SLEEP,#0x01
      0017A7                       3635 00104$:
                                   3636 ;	cc1111usb.c:920: if (usb_data.event & (USBD_CIF_RESET | USBD_CIF_RESUME)) {
      0017A7 E5 23            [12] 3637 	mov	a,(_usb_data + 0x0001)
      0017A9 54 06            [12] 3638 	anl	a,#0x06
      0017AB 60 2F            [24] 3639 	jz	00106$
                                   3640 ;	cc1111usb.c:921: lastCode[0] = 10;
      0017AD 90 F0 D2         [24] 3641 	mov	dptr,#_lastCode
      0017B0 74 0A            [12] 3642 	mov	a,#0x0A
      0017B2 F0               [24] 3643 	movx	@dptr,a
                                   3644 ;	cc1111usb.c:922: usb_data.usbstatus = USB_STATE_RESUME;
      0017B3 75 22 02         [24] 3645 	mov	_usb_data,#0x02
                                   3646 ;	cc1111usb.c:923: usb_data.event    &= ~(USBD_CIF_RESUME);
      0017B6 74 FD            [12] 3647 	mov	a,#0xFD
      0017B8 55 23            [12] 3648 	anl	a,(_usb_data + 0x0001)
      0017BA FE               [12] 3649 	mov	r6,a
      0017BB AF 24            [24] 3650 	mov	r7,((_usb_data + 0x0001) + 1)
      0017BD 8E 23            [24] 3651 	mov	((_usb_data + 0x0001) + 0),r6
      0017BF 8F 24            [24] 3652 	mov	((_usb_data + 0x0001) + 1),r7
                                   3653 ;	cc1111usb.c:928: USBPOW |= USBPOW_RESUME;
      0017C1 90 DE 01         [24] 3654 	mov	dptr,#_USBPOW
      0017C4 E0               [24] 3655 	movx	a,@dptr
      0017C5 FF               [12] 3656 	mov	r7,a
      0017C6 74 04            [12] 3657 	mov	a,#0x04
      0017C8 4F               [12] 3658 	orl	a,r7
      0017C9 F0               [24] 3659 	movx	@dptr,a
                                   3660 ;	cc1111usb.c:929: sleepMillis(8);
      0017CA 90 00 08         [24] 3661 	mov	dptr,#0x0008
      0017CD 12 09 63         [24] 3662 	lcall	_sleepMillis
                                   3663 ;	cc1111usb.c:930: USBPOW &= ~USBPOW_RESUME;
      0017D0 90 DE 01         [24] 3664 	mov	dptr,#_USBPOW
      0017D3 E0               [24] 3665 	movx	a,@dptr
      0017D4 FF               [12] 3666 	mov	r7,a
      0017D5 74 FB            [12] 3667 	mov	a,#0xFB
      0017D7 5F               [12] 3668 	anl	a,r7
      0017D8 F0               [24] 3669 	movx	@dptr,a
                                   3670 ;	cc1111usb.c:932: usb_data.usbstatus = USB_STATE_IDLE;
      0017D9 75 22 00         [24] 3671 	mov	_usb_data,#0x00
      0017DC                       3672 00106$:
                                   3673 ;	cc1111usb.c:938: if (usb_data.event & USBD_CIF_RESET || usb_data.usbstatus == USB_STATE_RESET)                // handle RESET
      0017DC E5 23            [12] 3674 	mov	a,(_usb_data + 0x0001)
      0017DE 20 E2 05         [24] 3675 	jb	acc.2,00107$
      0017E1 74 03            [12] 3676 	mov	a,#0x03
      0017E3 B5 22 14         [24] 3677 	cjne	a,_usb_data,00108$
      0017E6                       3678 00107$:
                                   3679 ;	cc1111usb.c:940: usb_init();
      0017E6 12 0C 28         [24] 3680 	lcall	_usb_init
                                   3681 ;	cc1111usb.c:941: lastCode[0] = 11;
      0017E9 90 F0 D2         [24] 3682 	mov	dptr,#_lastCode
      0017EC 74 0B            [12] 3683 	mov	a,#0x0B
      0017EE F0               [24] 3684 	movx	@dptr,a
                                   3685 ;	cc1111usb.c:942: usb_data.event &= ~USBD_CIF_RESET;
      0017EF 74 FB            [12] 3686 	mov	a,#0xFB
      0017F1 55 23            [12] 3687 	anl	a,(_usb_data + 0x0001)
      0017F3 FE               [12] 3688 	mov	r6,a
      0017F4 AF 24            [24] 3689 	mov	r7,((_usb_data + 0x0001) + 1)
      0017F6 8E 23            [24] 3690 	mov	((_usb_data + 0x0001) + 0),r6
      0017F8 8F 24            [24] 3691 	mov	((_usb_data + 0x0001) + 1),r7
      0017FA                       3692 00108$:
                                   3693 ;	cc1111usb.c:945: if (usb_data.event & (USBD_OIF_OUTEP5IF))
      0017FA E5 24            [12] 3694 	mov	a,((_usb_data + 0x0001) + 1)
      0017FC 30 E6 36         [24] 3695 	jnb	acc.6,00113$
                                   3696 ;	cc1111usb.c:947: lastCode[0] = 12;
      0017FF 90 F0 D2         [24] 3697 	mov	dptr,#_lastCode
      001802 74 0C            [12] 3698 	mov	a,#0x0C
      001804 F0               [24] 3699 	movx	@dptr,a
                                   3700 ;	cc1111usb.c:948: if (ep5iobuf.epstatus == EP_STATE_STALL)                        // gotta clear this somewhere...
      001805 90 F1 6F         [24] 3701 	mov	dptr,#(_ep5iobuf + 0x000d)
      001808 E0               [24] 3702 	movx	a,@dptr
      001809 FF               [12] 3703 	mov	r7,a
      00180A BF 03 1A         [24] 3704 	cjne	r7,#0x03,00111$
                                   3705 ;	cc1111usb.c:951: lastCode[1] = 8;
      00180D 90 F0 D3         [24] 3706 	mov	dptr,#(_lastCode + 0x0001)
      001810 74 08            [12] 3707 	mov	a,#0x08
      001812 F0               [24] 3708 	movx	@dptr,a
                                   3709 ;	cc1111usb.c:952: ep5iobuf.epstatus = EP_STATE_IDLE;
      001813 90 F1 6F         [24] 3710 	mov	dptr,#(_ep5iobuf + 0x000d)
      001816 E4               [12] 3711 	clr	a
      001817 F0               [24] 3712 	movx	@dptr,a
                                   3713 ;	cc1111usb.c:953: USBINDEX=5;
      001818 90 DE 0E         [24] 3714 	mov	dptr,#_USBINDEX
      00181B 74 05            [12] 3715 	mov	a,#0x05
      00181D F0               [24] 3716 	movx	@dptr,a
                                   3717 ;	cc1111usb.c:954: USBCSOL &= 0x9f;                                            // clear both command (SEND_STALL) and status (SENT_STALL)
      00181E 90 DE 14         [24] 3718 	mov	dptr,#_USBCSOL
      001821 E0               [24] 3719 	movx	a,@dptr
      001822 FF               [12] 3720 	mov	r7,a
      001823 74 9F            [12] 3721 	mov	a,#0x9F
      001825 5F               [12] 3722 	anl	a,r7
      001826 F0               [24] 3723 	movx	@dptr,a
      001827                       3724 00111$:
                                   3725 ;	cc1111usb.c:956: handleOUTEP5();
      001827 12 13 EA         [24] 3726 	lcall	_handleOUTEP5
                                   3727 ;	cc1111usb.c:957: usb_data.event &= ~USBD_OIF_OUTEP5IF;
      00182A AE 23            [24] 3728 	mov	r6,(_usb_data + 0x0001)
      00182C 74 BF            [12] 3729 	mov	a,#0xBF
      00182E 55 24            [12] 3730 	anl	a,((_usb_data + 0x0001) + 1)
      001830 FF               [12] 3731 	mov	r7,a
      001831 8E 23            [24] 3732 	mov	((_usb_data + 0x0001) + 0),r6
      001833 8F 24            [24] 3733 	mov	((_usb_data + 0x0001) + 1),r7
      001835                       3734 00113$:
                                   3735 ;	cc1111usb.c:967: if (usb_data.event & ~(USBD_IIF_INEP5IF|USBD_OIF_OUTEP5IF|USBD_IIF_EP0IF|USBD_CIF_RESET|
      001835 E5 23            [12] 3736 	mov	a,(_usb_data + 0x0001)
      001837 54 E0            [12] 3737 	anl	a,#0xE0
      001839 70 06            [24] 3738 	jnz	00153$
      00183B E5 24            [12] 3739 	mov	a,((_usb_data + 0x0001) + 1)
      00183D 54 BD            [12] 3740 	anl	a,#0xBD
      00183F 60 20            [24] 3741 	jz	00115$
      001841                       3742 00153$:
                                   3743 ;	cc1111usb.c:970: lastCode[1] = 9;
      001841 90 F0 D3         [24] 3744 	mov	dptr,#(_lastCode + 0x0001)
      001844 74 09            [12] 3745 	mov	a,#0x09
      001846 F0               [24] 3746 	movx	@dptr,a
                                   3747 ;	cc1111usb.c:971: blink_binary_baby_lsb(usb_data.event, 16);
      001847 85 23 82         [24] 3748 	mov	dpl,((_usb_data + 0x0001) + 0)
      00184A 85 24 83         [24] 3749 	mov	dph,((_usb_data + 0x0001) + 1)
      00184D 75 0D 10         [24] 3750 	mov	_blink_binary_baby_lsb_PARM_2,#0x10
      001850 12 09 A2         [24] 3751 	lcall	_blink_binary_baby_lsb
                                   3752 ;	cc1111usb.c:972: usb_data.event &= ~(USBD_IIF_INEP5IF|USBD_OIF_OUTEP5IF|USBD_IIF_EP0IF|USBD_CIF_RESET|
      001853 74 E0            [12] 3753 	mov	a,#0xE0
      001855 55 23            [12] 3754 	anl	a,(_usb_data + 0x0001)
      001857 FE               [12] 3755 	mov	r6,a
      001858 74 BD            [12] 3756 	mov	a,#0xBD
      00185A 55 24            [12] 3757 	anl	a,((_usb_data + 0x0001) + 1)
      00185C FF               [12] 3758 	mov	r7,a
      00185D 8E 23            [24] 3759 	mov	((_usb_data + 0x0001) + 0),r6
      00185F 8F 24            [24] 3760 	mov	((_usb_data + 0x0001) + 1),r7
      001861                       3761 00115$:
                                   3762 ;	cc1111usb.c:976: if (usb_data.usbstatus == USB_STATE_BLINK)
      001861 74 FF            [12] 3763 	mov	a,#0xFF
      001863 B5 22 13         [24] 3764 	cjne	a,_usb_data,00118$
                                   3765 ;	cc1111usb.c:978: REALLYFASTBLINK();
      001866 D2 90            [12] 3766 	setb	_P1_0
      001868 90 00 02         [24] 3767 	mov	dptr,#0x0002
      00186B 12 09 63         [24] 3768 	lcall	_sleepMillis
      00186E C2 90            [12] 3769 	clr	_P1_0
      001870 90 00 0A         [24] 3770 	mov	dptr,#0x000A
      001873 12 09 63         [24] 3771 	lcall	_sleepMillis
                                   3772 ;	cc1111usb.c:979: usb_data.usbstatus = USB_STATE_IDLE;
      001876 75 22 00         [24] 3773 	mov	_usb_data,#0x00
      001879                       3774 00118$:
      001879 22               [24] 3775 	ret
                                   3776 ;------------------------------------------------------------
                                   3777 ;Allocation info for local variables in function 'usbIntHandler'
                                   3778 ;------------------------------------------------------------
                                   3779 ;	cc1111usb.c:989: void usbIntHandler(void) __interrupt P2INT_VECTOR
                                   3780 ;	-----------------------------------------
                                   3781 ;	 function usbIntHandler
                                   3782 ;	-----------------------------------------
      00187A                       3783 _usbIntHandler:
      00187A C0 E0            [24] 3784 	push	acc
      00187C C0 82            [24] 3785 	push	dpl
      00187E C0 83            [24] 3786 	push	dph
      001880 C0 07            [24] 3787 	push	ar7
      001882 C0 06            [24] 3788 	push	ar6
      001884 C0 05            [24] 3789 	push	ar5
      001886 C0 04            [24] 3790 	push	ar4
      001888 C0 D0            [24] 3791 	push	psw
      00188A 75 D0 00         [24] 3792 	mov	psw,#0x00
                                   3793 ;	cc1111usb.c:992: while (!IS_XOSC_STABLE());
      00188D                       3794 00101$:
      00188D E5 BE            [12] 3795 	mov	a,_SLEEP
      00188F 30 E6 FB         [24] 3796 	jnb	acc.6,00101$
                                   3797 ;	cc1111usb.c:993: EA=0;
      001892 C2 AF            [12] 3798 	clr	_EA
                                   3799 ;	cc1111usb.c:998: usb_data.event |= USBCIF;
      001894 90 DE 06         [24] 3800 	mov	dptr,#_USBCIF
      001897 E0               [24] 3801 	movx	a,@dptr
      001898 FF               [12] 3802 	mov	r7,a
      001899 7E 00            [12] 3803 	mov	r6,#0x00
      00189B E5 23            [12] 3804 	mov	a,(_usb_data + 0x0001)
      00189D 42 07            [12] 3805 	orl	ar7,a
      00189F E5 24            [12] 3806 	mov	a,((_usb_data + 0x0001) + 1)
      0018A1 42 06            [12] 3807 	orl	ar6,a
      0018A3 8F 23            [24] 3808 	mov	((_usb_data + 0x0001) + 0),r7
      0018A5 8E 24            [24] 3809 	mov	((_usb_data + 0x0001) + 1),r6
                                   3810 ;	cc1111usb.c:999: usb_data.event |= (USBIIF << 4);
      0018A7 90 DE 02         [24] 3811 	mov	dptr,#_USBIIF
      0018AA E0               [24] 3812 	movx	a,@dptr
      0018AB FD               [12] 3813 	mov	r5,a
      0018AC E4               [12] 3814 	clr	a
      0018AD CD               [12] 3815 	xch	a,r5
      0018AE C4               [12] 3816 	swap	a
      0018AF CD               [12] 3817 	xch	a,r5
      0018B0 6D               [12] 3818 	xrl	a,r5
      0018B1 CD               [12] 3819 	xch	a,r5
      0018B2 54 F0            [12] 3820 	anl	a,#0xF0
      0018B4 CD               [12] 3821 	xch	a,r5
      0018B5 6D               [12] 3822 	xrl	a,r5
      0018B6 FC               [12] 3823 	mov	r4,a
      0018B7 ED               [12] 3824 	mov	a,r5
      0018B8 42 07            [12] 3825 	orl	ar7,a
      0018BA EC               [12] 3826 	mov	a,r4
      0018BB 42 06            [12] 3827 	orl	ar6,a
      0018BD 8F 23            [24] 3828 	mov	((_usb_data + 0x0001) + 0),r7
      0018BF 8E 24            [24] 3829 	mov	((_usb_data + 0x0001) + 1),r6
                                   3830 ;	cc1111usb.c:1000: usb_data.event |= (USBOIF << 9);
      0018C1 90 DE 04         [24] 3831 	mov	dptr,#_USBOIF
      0018C4 E0               [24] 3832 	movx	a,@dptr
      0018C5 25 E0            [12] 3833 	add	a,acc
      0018C7 FC               [12] 3834 	mov	r4,a
      0018C8 E4               [12] 3835 	clr	a
      0018C9 FD               [12] 3836 	mov	r5,a
      0018CA 42 07            [12] 3837 	orl	ar7,a
      0018CC EC               [12] 3838 	mov	a,r4
      0018CD 42 06            [12] 3839 	orl	ar6,a
      0018CF 8F 23            [24] 3840 	mov	((_usb_data + 0x0001) + 0),r7
                                   3841 ;	cc1111usb.c:1004: if (usb_data.event & (USBD_IIF_INEP5IF))
      0018D1 EE               [12] 3842 	mov	a,r6
      0018D2 F5 24            [12] 3843 	mov	((_usb_data + 0x0001) + 1),a
      0018D4 30 E1 12         [24] 3844 	jnb	acc.1,00105$
                                   3845 ;	cc1111usb.c:1006: ep5iobuf.flags &= ~EP_INBUF_WRITTEN;
      0018D7 90 F1 6E         [24] 3846 	mov	dptr,#(_ep5iobuf + 0x000c)
      0018DA E0               [24] 3847 	movx	a,@dptr
      0018DB 54 FE            [12] 3848 	anl	a,#0xFE
      0018DD F0               [24] 3849 	movx	@dptr,a
                                   3850 ;	cc1111usb.c:1007: usb_data.event &= ~USBD_IIF_INEP5IF;
      0018DE AE 23            [24] 3851 	mov	r6,(_usb_data + 0x0001)
      0018E0 74 FD            [12] 3852 	mov	a,#0xFD
      0018E2 55 24            [12] 3853 	anl	a,((_usb_data + 0x0001) + 1)
      0018E4 FF               [12] 3854 	mov	r7,a
      0018E5 8E 23            [24] 3855 	mov	((_usb_data + 0x0001) + 0),r6
      0018E7 8F 24            [24] 3856 	mov	((_usb_data + 0x0001) + 1),r7
      0018E9                       3857 00105$:
                                   3858 ;	cc1111usb.c:1011: USB_INT_CLEAR();                                // P2IFG= 0; P2IF= 0;
      0018E9 75 8B 00         [24] 3859 	mov	_P2IFG,#0x00
      0018EC C2 E8            [12] 3860 	clr	_P2IF
                                   3861 ;	cc1111usb.c:1012: EA=1;
      0018EE D2 AF            [12] 3862 	setb	_EA
      0018F0 D0 D0            [24] 3863 	pop	psw
      0018F2 D0 04            [24] 3864 	pop	ar4
      0018F4 D0 05            [24] 3865 	pop	ar5
      0018F6 D0 06            [24] 3866 	pop	ar6
      0018F8 D0 07            [24] 3867 	pop	ar7
      0018FA D0 83            [24] 3868 	pop	dph
      0018FC D0 82            [24] 3869 	pop	dpl
      0018FE D0 E0            [24] 3870 	pop	acc
      001900 32               [24] 3871 	reti
                                   3872 ;	eliminated unneeded push/pop ar1
                                   3873 ;	eliminated unneeded push/pop ar0
                                   3874 ;	eliminated unneeded push/pop b
                                   3875 ;------------------------------------------------------------
                                   3876 ;Allocation info for local variables in function 'p0IntHandler'
                                   3877 ;------------------------------------------------------------
                                   3878 ;	cc1111usb.c:1016: void p0IntHandler(void) __interrupt P0INT_VECTOR  // P0_7's interrupt is used as the USB RESUME interrupt
                                   3879 ;	-----------------------------------------
                                   3880 ;	 function p0IntHandler
                                   3881 ;	-----------------------------------------
      001901                       3882 _p0IntHandler:
      001901 C0 E0            [24] 3883 	push	acc
      001903 C0 07            [24] 3884 	push	ar7
      001905 C0 D0            [24] 3885 	push	psw
      001907 75 D0 00         [24] 3886 	mov	psw,#0x00
                                   3887 ;	cc1111usb.c:1018: while (!IS_XOSC_STABLE());
      00190A                       3888 00101$:
      00190A E5 BE            [12] 3889 	mov	a,_SLEEP
      00190C 30 E6 FB         [24] 3890 	jnb	acc.6,00101$
                                   3891 ;	cc1111usb.c:1019: EA=0;
      00190F C2 AF            [12] 3892 	clr	_EA
                                   3893 ;	cc1111usb.c:1021: if (P0IFG & P0IFG_USB_RESUME)
      001911 E5 89            [12] 3894 	mov	a,_P0IFG
      001913 30 E7 03         [24] 3895 	jnb	acc.7,00105$
                                   3896 ;	cc1111usb.c:1022: usb_data.usbstatus = USB_STATE_RESUME;
      001916 75 22 02         [24] 3897 	mov	_usb_data,#0x02
      001919                       3898 00105$:
                                   3899 ;	cc1111usb.c:1024: SLEEP &= ~0x3;                                  // clear the PM mode bits
      001919 AF BE            [24] 3900 	mov	r7,_SLEEP
      00191B 74 FC            [12] 3901 	mov	a,#0xFC
      00191D 5F               [12] 3902 	anl	a,r7
      00191E F5 BE            [12] 3903 	mov	_SLEEP,a
                                   3904 ;	cc1111usb.c:1025: USB_RESUME_INT_CLEAR();
      001920 75 89 00         [24] 3905 	mov	_P0IFG,#0x00
      001923 C2 C5            [12] 3906 	clr	_P0IF
                                   3907 ;	cc1111usb.c:1027: EA=1;
      001925 D2 AF            [12] 3908 	setb	_EA
      001927 D0 D0            [24] 3909 	pop	psw
      001929 D0 07            [24] 3910 	pop	ar7
      00192B D0 E0            [24] 3911 	pop	acc
      00192D 32               [24] 3912 	reti
                                   3913 ;	eliminated unneeded push/pop ar1
                                   3914 ;	eliminated unneeded push/pop ar0
                                   3915 ;	eliminated unneeded push/pop dpl
                                   3916 ;	eliminated unneeded push/pop dph
                                   3917 ;	eliminated unneeded push/pop b
                                   3918 ;------------------------------------------------------------
                                   3919 ;Allocation info for local variables in function 'USBDESCBEGIN'
                                   3920 ;------------------------------------------------------------
                                   3921 ;	cc1111usb.c:1032: void USBDESCBEGIN(void){
                                   3922 ;	-----------------------------------------
                                   3923 ;	 function USBDESCBEGIN
                                   3924 ;	-----------------------------------------
      00192E                       3925 _USBDESCBEGIN:
                                   3926 ;	cc1111usb.c:1138: __endasm;
      00192E                       3927 	0001$:
                                   3928 ; Device descriptor
      00192E 12                    3929 	.DB 0002$ - 0001$ ; bLength
      00192F 01                    3930 	.DB 0x01 ; bDescriptorType
      001930 00 02                 3931 	.DB 0x00, 0x02 ; bcdUSB
      001932 02                    3932 	.DB 0x02 ; bDeviceClass i
      001933 00                    3933 	.DB 0x00 ; bDeviceSubClass
      001934 00                    3934 	.DB 0x00 ; bDeviceProtocol
      001935 40                    3935 	.DB 64 ; EP0_PACKET_SIZE
      001936 51 04                 3936 	.DB 0x51, 0x04 ; idVendor Texas Instruments
      001938 15 47                 3937 	.DB 0x15, 0x47 ; idProduct CC1111
      00193A 01 00                 3938 	.DB 0x01, 0x00 ; bcdDevice (change to hardware version)
      00193C 01                    3939 	.DB 0x01 ; iManufacturer
      00193D 02                    3940 	.DB 0x02 ; iProduct
      00193E 03                    3941 	.DB 0x03 ; iSerialNumber
      00193F 01                    3942 	.DB 0x01 ; bNumConfigurations
      001940                       3943 	0002$:
                                   3944 ; Configuration descriptor
      001940 09                    3945 	.DB 0003$ - 0002$ ; bLength
      001941 02                    3946 	.DB 0x02 ; bDescriptorType
      001942 20                    3947 	.DB 0006$ - 0002$ ;
      001943 00                    3948 	.DB 00
      001944 01                    3949 	.DB 0x01 ; NumInterfaces
      001945 01                    3950 	.DB 0x01 ; bConfigurationValue - should be nonzero
      001946 00                    3951 	.DB 0x00 ; iConfiguration
      001947 80                    3952 	.DB 0x80 ; bmAttributes
      001948 FA                    3953 	.DB 0xfa ; MaxPower
      001949                       3954 	0003$:
                                   3955 ; Interface descriptor
      001949 09                    3956 	.DB 0004$ - 0003$ ; bLength
      00194A 04                    3957 	.DB 0x04 ; bDescriptorType
      00194B 00                    3958 	.DB 0x00 ; bInterfaceNumber
      00194C 00                    3959 	.DB 0x00 ; bAlternateSetting
      00194D 02                    3960 	.DB 0x02 ; bNumEndpoints
      00194E FF                    3961 	.DB 0xff ; bInterfaceClass
      00194F FF                    3962 	.DB 0xff ; bInterfaceSubClass
      001950 01                    3963 	.DB 0x01 ; bInterfaceProcotol
      001951 00                    3964 	.DB 0x00 ; iInterface
      001952                       3965 	0004$:
                                   3966 ; Endpoint descriptor (EP5 IN)
      001952 07                    3967 	.DB 0005$ - 0004$ ; bLength
      001953 05                    3968 	.DB 0x05 ; bDescriptorType
      001954 85                    3969 	.DB 0x85 ; bEndpointAddress
      001955 02                    3970 	.DB 0x02 ; bmAttributes - bits 0-1 Xfer Type (0=Ctrl, 1=Isoc, 2=Bulk, 3=Intrpt); 2-3 Isoc-SyncType (0=None, 1=FeedbackEndpoint, 2=Adaptive, 3=Synchronous); 4-5 Isoc-UsageType (0=Data, 1=Feedback, 2=Explicit)
      001956 F4 01                 3971 	.DB 0xf4, 0x01 ; wMaxPacketSize
      001958 01                    3972 	.DB 0x01 ; bInterval
      001959                       3973 	0005$:
                                   3974 ; Endpoint descriptor (EP5 OUT)
      001959 07                    3975 	.DB 0006$ - 0005$ ; bLength
      00195A 05                    3976 	.DB 0x05 ; bDescriptorType
      00195B 05                    3977 	.DB 0x05 ; bEndpointAddress
      00195C 02                    3978 	.DB 0x02 ; bmAttributes
      00195D 40 00                 3979 	.DB 0x40, 0x00 ; wMaxPacketSize
      00195F 01                    3980 	.DB 0x01 ; bInterval
      001960                       3981 	0006$:
                                   3982 ; Language ID
      001960 04                    3983 	.DB 0007$ - 0006$ ; bLength
      001961 03                    3984 	.DB 0x03 ; bDescriptorType
      001962 09                    3985 	.DB 0x09 ; US-EN
      001963 04                    3986 	.DB 0x04
      001964                       3987 	0007$:
                                   3988 ; Manufacturer
      001964 24                    3989 	.DB 0008$ - 0007$ ; bLength
      001965 03                    3990 	.DB 0x03 ; bDescriptorType
      001966 22 00                 3991 	.DB "a", 0
      001968 22 00                 3992 	.DB "t", 0
      00196A 22 00                 3993 	.DB "l", 0
      00196C 22 00                 3994 	.DB "a", 0
      00196E 22 00                 3995 	.DB "s", 0
      001970 22 00                 3996 	.DB " ", 0
      001972 22 00                 3997 	.DB "i", 0
      001974 22 00                 3998 	.DB "n", 0
      001976 22 00                 3999 	.DB "s", 0
      001978 22 00                 4000 	.DB "t", 0
      00197A 22 00                 4001 	.DB "r", 0
      00197C 22 00                 4002 	.DB "u", 0
      00197E 22 00                 4003 	.DB "m", 0
      001980 22 00                 4004 	.DB "e", 0
      001982 22 00                 4005 	.DB "n", 0
      001984 22 00                 4006 	.DB "t", 0
      001986 22 00                 4007 	.DB "s", 0
      001988                       4008 	0008$:
                                   4009 ; Product
      001988 26                    4010 	.DB 0009$ - 0008$ ; bLength
      001989 03                    4011 	.DB 0x03 ; bDescriptorType
      00198A 22 00                 4012 	.DB "C", 0
      00198C 22 00                 4013 	.DB "C", 0
      00198E 22 00                 4014 	.DB "1", 0
      001990 22 00                 4015 	.DB "1", 0
      001992 22 00                 4016 	.DB "1", 0
      001994 22 00                 4017 	.DB "1", 0
      001996 22 00                 4018 	.DB " ", 0
      001998 22 00                 4019 	.DB "U", 0
      00199A 22 00                 4020 	.DB "S", 0
      00199C 22 00                 4021 	.DB "B", 0
      00199E 22 00                 4022 	.DB " ", 0
      0019A0 22 00                 4023 	.DB "K", 0
      0019A2 22 00                 4024 	.DB "i", 0
      0019A4 22 00                 4025 	.DB "c", 0
      0019A6 22 00                 4026 	.DB "k", 0
      0019A8 22 00                 4027 	.DB "a", 0
      0019AA 22 00                 4028 	.DB "s", 0
      0019AC 22 00                 4029 	.DB "s", 0
      0019AE                       4030 	0009$:
                                   4031 ;; Serial number
      0019AE 08                    4032 	.DB 0010$ - 0009$ ;; bLength
      0019AF 03                    4033 	.DB 0x03 ;; bDescriptorType
      0019B0 22 00                 4034 	.DB "0", 0
      0019B2 22 00                 4035 	.DB "0", 0
      0019B4 22 00                 4036 	.DB "1", 0
      0019B6                       4037 	0010$:
      0019B6 00                    4038 	.DB 0
      0019B7 FF                    4039 	.DB 0xff
      0019B8 22               [24] 4040 	ret
                                   4041 	.area CSEG    (CODE)
                                   4042 	.area CONST   (CODE)
      001A87                       4043 ___str_0:
      001A87 00                    4044 	.db 0x00
      001A88 00                    4045 	.db 0x00
      001A89 00                    4046 	.db 0x00
      001A8A                       4047 ___str_1:
      001A8A 30                    4048 	.ascii "0"
      001A8B 00                    4049 	.db 0x00
      001A8C                       4050 ___str_2:
      001A8C 00                    4051 	.db 0x00
      001A8D                       4052 ___str_3:
      001A8D 55 4E 49 4D 50 4C 45  4053 	.ascii "UNIMPLEMENTED"
             4D 45 4E 54 45 44
      001A9A 00                    4054 	.db 0x00
                                   4055 	.area XINIT   (CODE)
                                   4056 	.area CABS    (ABS,CODE)
