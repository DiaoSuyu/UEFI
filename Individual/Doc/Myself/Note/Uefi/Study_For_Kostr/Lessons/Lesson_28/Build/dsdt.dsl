/*
 * Intel ACPI Component Architecture
 * AML/ASL+ Disassembler version 20200925 (64-bit version)
 * Copyright (c) 2000 - 2020 Intel Corporation
 * 
 * Disassembling to symbolic ASL+ operators
 *
 * Disassembly of dsdt.aml, Wed Feb 26 17:18:09 2025
 *
 * Original Table Header:
 *     Signature        "DSDT"
 *     Length           0x00002154 (8532)
 *     Revision         0x01 **** 32-bit table (V1), no 64-bit math support
 *     Checksum         0x27
 *     OEM ID           "BOCHS "
 *     OEM Table ID     "BXPC    "
 *     OEM Revision     0x00000001 (1)
 *     Compiler ID      "BXPC"
 *     Compiler Version 0x00000001 (1)
 */
DefinitionBlock ("", "DSDT", 1, "BOCHS ", "BXPC    ", 0x00000001)
{
    Scope (\)
    {
        OperationRegion (DBG, SystemIO, 0x0402, One)
        Field (DBG, ByteAcc, NoLock, Preserve)
        {
            DBGB,   8
        }

        Method (DBUG, 1, NotSerialized)
        {
            ToHexString (Arg0, Local0)
            ToBuffer (Local0, Local0)
            Local1 = (SizeOf (Local0) - One)
            Local2 = Zero
            While ((Local2 < Local1))
            {
                DBGB = DerefOf (Local0 [Local2])
                Local2++
            }

            DBGB = 0x0A
        }
    }

    Scope (_SB)
    {
        Device (PCI0)
        {
            Name (_HID, EisaId ("PNP0A03") /* PCI Bus */)  // _HID: Hardware ID
            Name (_UID, Zero)  // _UID: Unique ID
            Method (EDSM, 5, Serialized)
            {
                If ((Arg2 == Zero))
                {
                    Local0 = Buffer (One)
                        {
                             0x00                                             // .
                        }
                    If ((Arg0 != ToUUID ("e5c937d0-3553-4d7a-9117-ea4d19c3434d") /* Device Labeling Interface */))
                    {
                        Return (Local0)
                    }

                    If ((Arg1 < 0x02))
                    {
                        Return (Local0)
                    }

                    Local0 [Zero] = 0x81
                    Return (Local0)
                }

                If ((Arg2 == 0x07))
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            ""
                        }
                    Local1 = DerefOf (Arg4 [Zero])
                    Local0 [Zero] = Local1
                    Return (Local0)
                }
            }
        }
    }

    Scope (_SB.PCI0)
    {
        OperationRegion (PCST, SystemIO, 0xAE00, 0x08)
        Field (PCST, DWordAcc, NoLock, WriteAsZeros)
        {
            PCIU,   32, 
            PCID,   32
        }

        OperationRegion (SEJ, SystemIO, 0xAE08, 0x04)
        Field (SEJ, DWordAcc, NoLock, WriteAsZeros)
        {
            B0EJ,   32
        }

        OperationRegion (BNMR, SystemIO, 0xAE10, 0x08)
        Field (BNMR, DWordAcc, NoLock, WriteAsZeros)
        {
            BNUM,   32, 
            PIDX,   32
        }

        Mutex (BLCK, 0x00)
        Method (PCEJ, 2, NotSerialized)
        {
            Acquire (BLCK, 0xFFFF)
            BNUM = Arg0
            B0EJ = (One << Arg1)
            Release (BLCK)
            Return (Zero)
        }

        Method (AIDX, 2, NotSerialized)
        {
            Acquire (BLCK, 0xFFFF)
            BNUM = Arg0
            PIDX = (One << Arg1)
            Local0 = PIDX /* \_SB_.PCI0.PIDX */
            Release (BLCK)
            Return (Local0)
        }

        Method (PDSM, 5, Serialized)
        {
            If ((Arg2 == Zero))
            {
                Local0 = Buffer (One)
                    {
                         0x00                                             // .
                    }
                If ((Arg0 != ToUUID ("e5c937d0-3553-4d7a-9117-ea4d19c3434d") /* Device Labeling Interface */))
                {
                    Return (Local0)
                }

                If ((Arg1 < 0x02))
                {
                    Return (Local0)
                }

                Local1 = Zero
                Local2 = AIDX (DerefOf (Arg4 [Zero]), DerefOf (Arg4 [One]
                    ))
                If (!((Local2 == Zero) | (Local2 == 0xFFFFFFFF)))
                {
                    Local1 |= One
                    Local1 |= (One << 0x07)
                }

                Local0 [Zero] = Local1
                Return (Local0)
            }

            If ((Arg2 == 0x07))
            {
                Local0 = Package (0x02)
                    {
                        Zero, 
                        ""
                    }
                Local2 = AIDX (DerefOf (Arg4 [Zero]), DerefOf (Arg4 [One]
                    ))
                Local0 [Zero] = Local2
                Return (Local0)
            }
        }
    }

    Scope (_SB)
    {
        Scope (PCI0)
        {
            Method (_PRT, 0, NotSerialized)  // _PRT: PCI Routing Table
            {
                Return (Package (0x80)
                {
                    Package (0x04)
                    {
                        0xFFFF, 
                        Zero, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0xFFFF, 
                        One, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0xFFFF, 
                        0x02, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0xFFFF, 
                        0x03, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0001FFFF, 
                        Zero, 
                        LNKS, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0001FFFF, 
                        One, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0001FFFF, 
                        0x02, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0001FFFF, 
                        0x03, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0002FFFF, 
                        Zero, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0002FFFF, 
                        One, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0002FFFF, 
                        0x02, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0002FFFF, 
                        0x03, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0003FFFF, 
                        Zero, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0003FFFF, 
                        One, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0003FFFF, 
                        0x02, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0003FFFF, 
                        0x03, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0004FFFF, 
                        Zero, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0004FFFF, 
                        One, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0004FFFF, 
                        0x02, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0004FFFF, 
                        0x03, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0005FFFF, 
                        Zero, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0005FFFF, 
                        One, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0005FFFF, 
                        0x02, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0005FFFF, 
                        0x03, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0006FFFF, 
                        Zero, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0006FFFF, 
                        One, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0006FFFF, 
                        0x02, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0006FFFF, 
                        0x03, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0007FFFF, 
                        Zero, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0007FFFF, 
                        One, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0007FFFF, 
                        0x02, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0007FFFF, 
                        0x03, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0008FFFF, 
                        Zero, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0008FFFF, 
                        One, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0008FFFF, 
                        0x02, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0008FFFF, 
                        0x03, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0009FFFF, 
                        Zero, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0009FFFF, 
                        One, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0009FFFF, 
                        0x02, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0009FFFF, 
                        0x03, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000AFFFF, 
                        Zero, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000AFFFF, 
                        One, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000AFFFF, 
                        0x02, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000AFFFF, 
                        0x03, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000BFFFF, 
                        Zero, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000BFFFF, 
                        One, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000BFFFF, 
                        0x02, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000BFFFF, 
                        0x03, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000CFFFF, 
                        Zero, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000CFFFF, 
                        One, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000CFFFF, 
                        0x02, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000CFFFF, 
                        0x03, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000DFFFF, 
                        Zero, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000DFFFF, 
                        One, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000DFFFF, 
                        0x02, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000DFFFF, 
                        0x03, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000EFFFF, 
                        Zero, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000EFFFF, 
                        One, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000EFFFF, 
                        0x02, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000EFFFF, 
                        0x03, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000FFFFF, 
                        Zero, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000FFFFF, 
                        One, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000FFFFF, 
                        0x02, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x000FFFFF, 
                        0x03, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0010FFFF, 
                        Zero, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0010FFFF, 
                        One, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0010FFFF, 
                        0x02, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0010FFFF, 
                        0x03, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0011FFFF, 
                        Zero, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0011FFFF, 
                        One, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0011FFFF, 
                        0x02, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0011FFFF, 
                        0x03, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0012FFFF, 
                        Zero, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0012FFFF, 
                        One, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0012FFFF, 
                        0x02, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0012FFFF, 
                        0x03, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0013FFFF, 
                        Zero, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0013FFFF, 
                        One, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0013FFFF, 
                        0x02, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0013FFFF, 
                        0x03, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0014FFFF, 
                        Zero, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0014FFFF, 
                        One, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0014FFFF, 
                        0x02, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0014FFFF, 
                        0x03, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0015FFFF, 
                        Zero, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0015FFFF, 
                        One, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0015FFFF, 
                        0x02, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0015FFFF, 
                        0x03, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0016FFFF, 
                        Zero, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0016FFFF, 
                        One, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0016FFFF, 
                        0x02, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0016FFFF, 
                        0x03, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0017FFFF, 
                        Zero, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0017FFFF, 
                        One, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0017FFFF, 
                        0x02, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0017FFFF, 
                        0x03, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0018FFFF, 
                        Zero, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0018FFFF, 
                        One, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0018FFFF, 
                        0x02, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0018FFFF, 
                        0x03, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0019FFFF, 
                        Zero, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0019FFFF, 
                        One, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0019FFFF, 
                        0x02, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x0019FFFF, 
                        0x03, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001AFFFF, 
                        Zero, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001AFFFF, 
                        One, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001AFFFF, 
                        0x02, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001AFFFF, 
                        0x03, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001BFFFF, 
                        Zero, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001BFFFF, 
                        One, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001BFFFF, 
                        0x02, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001BFFFF, 
                        0x03, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001CFFFF, 
                        Zero, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001CFFFF, 
                        One, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001CFFFF, 
                        0x02, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001CFFFF, 
                        0x03, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001DFFFF, 
                        Zero, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001DFFFF, 
                        One, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001DFFFF, 
                        0x02, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001DFFFF, 
                        0x03, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001EFFFF, 
                        Zero, 
                        LNKB, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001EFFFF, 
                        One, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001EFFFF, 
                        0x02, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001EFFFF, 
                        0x03, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001FFFFF, 
                        Zero, 
                        LNKC, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001FFFFF, 
                        One, 
                        LNKD, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001FFFFF, 
                        0x02, 
                        LNKA, 
                        Zero
                    }, 

                    Package (0x04)
                    {
                        0x001FFFFF, 
                        0x03, 
                        LNKB, 
                        Zero
                    }
                })
            }
        }

        Method (IQST, 1, NotSerialized)
        {
            If ((0x80 & Arg0))
            {
                Return (0x09)
            }

            Return (0x0B)
        }

        Method (IQCR, 1, Serialized)
        {
            Name (PRR0, ResourceTemplate ()
            {
                Interrupt (ResourceConsumer, Level, ActiveHigh, Shared, ,, _Y00)
                {
                    0x00000000,
                }
            })
            CreateDWordField (PRR0, \_SB.IQCR._Y00._INT, PRRI)  // _INT: Interrupts
            If ((Arg0 < 0x80))
            {
                PRRI = Arg0
            }

            Return (PRR0) /* \_SB_.IQCR.PRR0 */
        }

        Device (LNKA)
        {
            Name (_HID, EisaId ("PNP0C0F") /* PCI Interrupt Link Device */)  // _HID: Hardware ID
            Name (_UID, Zero)  // _UID: Unique ID
            Name (_PRS, ResourceTemplate ()  // _PRS: Possible Resource Settings
            {
                Interrupt (ResourceConsumer, Level, ActiveHigh, Shared, ,, )
                {
                    0x00000005,
                    0x0000000A,
                    0x0000000B,
                }
            })
            Method (_STA, 0, NotSerialized)  // _STA: Status
            {
                Return (IQST (PRQ0))
            }

            Method (_DIS, 0, NotSerialized)  // _DIS: Disable Device
            {
                PRQ0 |= 0x80
            }

            Method (_CRS, 0, NotSerialized)  // _CRS: Current Resource Settings
            {
                Return (IQCR (PRQ0))
            }

            Method (_SRS, 1, NotSerialized)  // _SRS: Set Resource Settings
            {
                CreateDWordField (Arg0, 0x05, PRRI)
                PRQ0 = PRRI /* \_SB_.LNKA._SRS.PRRI */
            }
        }

        Device (LNKB)
        {
            Name (_HID, EisaId ("PNP0C0F") /* PCI Interrupt Link Device */)  // _HID: Hardware ID
            Name (_UID, One)  // _UID: Unique ID
            Name (_PRS, ResourceTemplate ()  // _PRS: Possible Resource Settings
            {
                Interrupt (ResourceConsumer, Level, ActiveHigh, Shared, ,, )
                {
                    0x00000005,
                    0x0000000A,
                    0x0000000B,
                }
            })
            Method (_STA, 0, NotSerialized)  // _STA: Status
            {
                Return (IQST (PRQ1))
            }

            Method (_DIS, 0, NotSerialized)  // _DIS: Disable Device
            {
                PRQ1 |= 0x80
            }

            Method (_CRS, 0, NotSerialized)  // _CRS: Current Resource Settings
            {
                Return (IQCR (PRQ1))
            }

            Method (_SRS, 1, NotSerialized)  // _SRS: Set Resource Settings
            {
                CreateDWordField (Arg0, 0x05, PRRI)
                PRQ1 = PRRI /* \_SB_.LNKB._SRS.PRRI */
            }
        }

        Device (LNKC)
        {
            Name (_HID, EisaId ("PNP0C0F") /* PCI Interrupt Link Device */)  // _HID: Hardware ID
            Name (_UID, 0x02)  // _UID: Unique ID
            Name (_PRS, ResourceTemplate ()  // _PRS: Possible Resource Settings
            {
                Interrupt (ResourceConsumer, Level, ActiveHigh, Shared, ,, )
                {
                    0x00000005,
                    0x0000000A,
                    0x0000000B,
                }
            })
            Method (_STA, 0, NotSerialized)  // _STA: Status
            {
                Return (IQST (PRQ2))
            }

            Method (_DIS, 0, NotSerialized)  // _DIS: Disable Device
            {
                PRQ2 |= 0x80
            }

            Method (_CRS, 0, NotSerialized)  // _CRS: Current Resource Settings
            {
                Return (IQCR (PRQ2))
            }

            Method (_SRS, 1, NotSerialized)  // _SRS: Set Resource Settings
            {
                CreateDWordField (Arg0, 0x05, PRRI)
                PRQ2 = PRRI /* \_SB_.LNKC._SRS.PRRI */
            }
        }

        Device (LNKD)
        {
            Name (_HID, EisaId ("PNP0C0F") /* PCI Interrupt Link Device */)  // _HID: Hardware ID
            Name (_UID, 0x03)  // _UID: Unique ID
            Name (_PRS, ResourceTemplate ()  // _PRS: Possible Resource Settings
            {
                Interrupt (ResourceConsumer, Level, ActiveHigh, Shared, ,, )
                {
                    0x00000005,
                    0x0000000A,
                    0x0000000B,
                }
            })
            Method (_STA, 0, NotSerialized)  // _STA: Status
            {
                Return (IQST (PRQ3))
            }

            Method (_DIS, 0, NotSerialized)  // _DIS: Disable Device
            {
                PRQ3 |= 0x80
            }

            Method (_CRS, 0, NotSerialized)  // _CRS: Current Resource Settings
            {
                Return (IQCR (PRQ3))
            }

            Method (_SRS, 1, NotSerialized)  // _SRS: Set Resource Settings
            {
                CreateDWordField (Arg0, 0x05, PRRI)
                PRQ3 = PRRI /* \_SB_.LNKD._SRS.PRRI */
            }
        }

        Device (LNKS)
        {
            Name (_HID, EisaId ("PNP0C0F") /* PCI Interrupt Link Device */)  // _HID: Hardware ID
            Name (_UID, 0x04)  // _UID: Unique ID
            Name (_PRS, ResourceTemplate ()  // _PRS: Possible Resource Settings
            {
                Interrupt (ResourceConsumer, Level, ActiveHigh, Shared, ,, )
                {
                    0x00000009,
                }
            })
            Method (_STA, 0, NotSerialized)  // _STA: Status
            {
                Return (0x0B)
            }

            Method (_DIS, 0, NotSerialized)  // _DIS: Disable Device
            {
            }

            Method (_CRS, 0, NotSerialized)  // _CRS: Current Resource Settings
            {
                Return (_PRS) /* \_SB_.LNKS._PRS */
            }

            Method (_SRS, 1, NotSerialized)  // _SRS: Set Resource Settings
            {
            }
        }
    }

    Scope (_SB)
    {
        Device (HPET)
        {
            Name (_HID, EisaId ("PNP0103") /* HPET System Timer */)  // _HID: Hardware ID
            Name (_UID, Zero)  // _UID: Unique ID
            OperationRegion (HPTM, SystemMemory, 0xFED00000, 0x0400)
            Field (HPTM, DWordAcc, Lock, Preserve)
            {
                VEND,   32, 
                PRD,    32
            }

            Method (_STA, 0, NotSerialized)  // _STA: Status
            {
                Local0 = VEND /* \_SB_.HPET.VEND */
                Local1 = PRD /* \_SB_.HPET.PRD_ */
                Local0 >>= 0x10
                If (((Local0 == Zero) || (Local0 == 0xFFFF)))
                {
                    Return (Zero)
                }

                If (((Local1 == Zero) || (Local1 > 0x05F5E100)))
                {
                    Return (Zero)
                }

                Return (0x0F)
            }

            Name (_CRS, ResourceTemplate ()  // _CRS: Current Resource Settings
            {
                Memory32Fixed (ReadOnly,
                    0xFED00000,         // Address Base
                    0x00000400,         // Address Length
                    )
            })
        }
    }

    Scope (_GPE)
    {
        Name (_HID, "ACPI0006" /* GPE Block Device */)  // _HID: Hardware ID
    }

    Scope (_SB)
    {
        Device (\_SB.PCI0.PRES)
        {
            Name (_HID, EisaId ("PNP0A06") /* Generic Container Device */)  // _HID: Hardware ID
            Name (_UID, "CPU Hotplug resources")  // _UID: Unique ID
            Mutex (CPLK, 0x00)
            Name (_CRS, ResourceTemplate ()  // _CRS: Current Resource Settings
            {
                IO (Decode16,
                    0xAF00,             // Range Minimum
                    0xAF00,             // Range Maximum
                    0x01,               // Alignment
                    0x0C,               // Length
                    )
            })
            OperationRegion (PRST, SystemIO, 0xAF00, 0x0C)
            Field (PRST, ByteAcc, NoLock, WriteAsZeros)
            {
                Offset (0x04), 
                CPEN,   1, 
                CINS,   1, 
                CRMV,   1, 
                CEJ0,   1, 
                CEJF,   1, 
                Offset (0x05), 
                CCMD,   8
            }

            Field (PRST, DWordAcc, NoLock, Preserve)
            {
                CSEL,   32, 
                Offset (0x08), 
                CDAT,   32
            }

            Method (_INI, 0, Serialized)  // _INI: Initialize
            {
                CSEL = Zero
            }
        }

        Device (\_SB.CPUS)
        {
            Name (_HID, "ACPI0010" /* Processor Container Device */)  // _HID: Hardware ID
            Name (_CID, EisaId ("PNP0A05") /* Generic Container Device */)  // _CID: Compatible ID
            Method (CTFY, 2, NotSerialized)
            {
                If ((Arg0 == Zero))
                {
                    Notify (C000, Arg1)
                }
            }

            Method (CSTA, 1, Serialized)
            {
                Acquire (\_SB.PCI0.PRES.CPLK, 0xFFFF)
                \_SB.PCI0.PRES.CSEL = Arg0
                Local0 = Zero
                If ((\_SB.PCI0.PRES.CPEN == One))
                {
                    Local0 = 0x0F
                }

                Release (\_SB.PCI0.PRES.CPLK)
                Return (Local0)
            }

            Method (CEJ0, 1, Serialized)
            {
                Acquire (\_SB.PCI0.PRES.CPLK, 0xFFFF)
                \_SB.PCI0.PRES.CSEL = Arg0
                \_SB.PCI0.PRES.CEJ0 = One
                Release (\_SB.PCI0.PRES.CPLK)
            }

            Method (CSCN, 0, Serialized)
            {
                Acquire (\_SB.PCI0.PRES.CPLK, 0xFFFF)
                Name (CNEW, Package (0xFF) {})
                Local3 = Zero
                Local4 = One
                While ((Local4 == One))
                {
                    Local4 = Zero
                    Local0 = One
                    Local1 = Zero
                    While (((Local0 == One) && (Local3 < One)))
                    {
                        Local0 = Zero
                        \_SB.PCI0.PRES.CSEL = Local3
                        \_SB.PCI0.PRES.CCMD = Zero
                        If ((\_SB.PCI0.PRES.CDAT < Local3))
                        {
                            Break
                        }

                        If ((Local1 == 0xFF))
                        {
                            Local4 = One
                            Break
                        }

                        Local3 = \_SB.PCI0.PRES.CDAT
                        If ((\_SB.PCI0.PRES.CINS == One))
                        {
                            CNEW [Local1] = Local3
                            Local1++
                            Local0 = One
                        }
                        ElseIf ((\_SB.PCI0.PRES.CRMV == One))
                        {
                            CTFY (Local3, 0x03)
                            \_SB.PCI0.PRES.CRMV = One
                            Local0 = One
                        }

                        Local3++
                    }

                    Local2 = Zero
                    While ((Local2 < Local1))
                    {
                        Local3 = DerefOf (CNEW [Local2])
                        CTFY (Local3, One)
                        Debug = Local3
                        \_SB.PCI0.PRES.CSEL = Local3
                        \_SB.PCI0.PRES.CINS = One
                        Local2++
                    }
                }

                Release (\_SB.PCI0.PRES.CPLK)
            }

            Method (COST, 4, Serialized)
            {
                Acquire (\_SB.PCI0.PRES.CPLK, 0xFFFF)
                \_SB.PCI0.PRES.CSEL = Arg0
                \_SB.PCI0.PRES.CCMD = One
                \_SB.PCI0.PRES.CDAT = Arg1
                \_SB.PCI0.PRES.CCMD = 0x02
                \_SB.PCI0.PRES.CDAT = Arg2
                Release (\_SB.PCI0.PRES.CPLK)
            }

            Processor (C000, 0x00, 0x00000000, 0x00)
            {
                Method (_STA, 0, Serialized)  // _STA: Status
                {
                    Return (CSTA (Zero))
                }

                Name (_MAT, Buffer (0x08)  // _MAT: Multiple APIC Table Entry
                {
                     0x00, 0x08, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00   // ........
                })
                Method (_OST, 3, Serialized)  // _OST: OSPM Status Indication
                {
                    COST (Zero, Arg0, Arg1, Arg2)
                }
            }
        }
    }

    Method (\_GPE._E02, 0, NotSerialized)  // _Exx: Edge-Triggered GPE, xx=0x00-0xFF
    {
        \_SB.CPUS.CSCN ()
    }

    Scope (\_SB.PCI0)
    {
        Name (_CRS, ResourceTemplate ()  // _CRS: Current Resource Settings
        {
            WordBusNumber (ResourceProducer, MinFixed, MaxFixed, PosDecode,
                0x0000,             // Granularity
                0x0000,             // Range Minimum
                0x00FF,             // Range Maximum
                0x0000,             // Translation Offset
                0x0100,             // Length
                ,, )
            IO (Decode16,
                0x0CF8,             // Range Minimum
                0x0CF8,             // Range Maximum
                0x01,               // Alignment
                0x08,               // Length
                )
            WordIO (ResourceProducer, MinFixed, MaxFixed, PosDecode, EntireRange,
                0x0000,             // Granularity
                0x0000,             // Range Minimum
                0x0CF7,             // Range Maximum
                0x0000,             // Translation Offset
                0x0CF8,             // Length
                ,, , TypeStatic, DenseTranslation)
            WordIO (ResourceProducer, MinFixed, MaxFixed, PosDecode, EntireRange,
                0x0000,             // Granularity
                0x0D00,             // Range Minimum
                0xFFFF,             // Range Maximum
                0x0000,             // Translation Offset
                0xF300,             // Length
                ,, , TypeStatic, DenseTranslation)
            DWordMemory (ResourceProducer, PosDecode, MinFixed, MaxFixed, Cacheable, ReadWrite,
                0x00000000,         // Granularity
                0x000A0000,         // Range Minimum
                0x000BFFFF,         // Range Maximum
                0x00000000,         // Translation Offset
                0x00020000,         // Length
                ,, , AddressRangeMemory, TypeStatic)
            DWordMemory (ResourceProducer, PosDecode, MinFixed, MaxFixed, NonCacheable, ReadWrite,
                0x00000000,         // Granularity
                0x08000000,         // Range Minimum
                0xFEBFFFFF,         // Range Maximum
                0x00000000,         // Translation Offset
                0xF6C00000,         // Length
                ,, , AddressRangeMemory, TypeStatic)
            QWordMemory (ResourceProducer, PosDecode, MinFixed, MaxFixed, Cacheable, ReadWrite,
                0x0000000000000000, // Granularity
                0x0000000100000000, // Range Minimum
                0x000000017FFFFFFF, // Range Maximum
                0x0000000000000000, // Translation Offset
                0x0000000080000000, // Length
                ,, , AddressRangeMemory, TypeStatic)
        })
        Device (GPE0)
        {
            Name (_HID, "PNP0A06" /* Generic Container Device */)  // _HID: Hardware ID
            Name (_UID, "GPE0 resources")  // _UID: Unique ID
            Name (_STA, 0x0B)  // _STA: Status
            Name (_CRS, ResourceTemplate ()  // _CRS: Current Resource Settings
            {
                IO (Decode16,
                    0xAFE0,             // Range Minimum
                    0xAFE0,             // Range Maximum
                    0x01,               // Alignment
                    0x04,               // Length
                    )
            })
        }

        Device (PHPR)
        {
            Name (_HID, "PNP0A06" /* Generic Container Device */)  // _HID: Hardware ID
            Name (_UID, "PCI Hotplug resources")  // _UID: Unique ID
            Name (_STA, 0x0B)  // _STA: Status
            Name (_CRS, ResourceTemplate ()  // _CRS: Current Resource Settings
            {
                IO (Decode16,
                    0xAE00,             // Range Minimum
                    0xAE00,             // Range Maximum
                    0x01,               // Alignment
                    0x18,               // Length
                    )
            })
        }
    }

    Scope (\)
    {
        Name (_S3, Package (0x04)  // _S3_: S3 System State
        {
            One, 
            One, 
            Zero, 
            Zero
        })
        Name (_S4, Package (0x04)  // _S4_: S4 System State
        {
            0x02, 
            0x02, 
            Zero, 
            Zero
        })
        Name (_S5, Package (0x04)  // _S5_: S5 System State
        {
            Zero, 
            Zero, 
            Zero, 
            Zero
        })
    }

    Scope (\_SB.PCI0)
    {
        Device (FWCF)
        {
            Name (_HID, "QEMU0002")  // _HID: Hardware ID
            Name (_STA, 0x0B)  // _STA: Status
            Name (_CRS, ResourceTemplate ()  // _CRS: Current Resource Settings
            {
                IO (Decode16,
                    0x0510,             // Range Minimum
                    0x0510,             // Range Maximum
                    0x01,               // Alignment
                    0x0C,               // Length
                    )
            })
        }
    }

    Scope (\_SB)
    {
        Scope (PCI0)
        {
            Device (S00)
            {
                Name (_ADR, Zero)  // _ADR: Address
            }

            Device (S08)
            {
                Name (_ADR, 0x00010000)  // _ADR: Address
                OperationRegion (P40C, PCI_Config, 0x60, 0x04)
                Scope (\_SB)
                {
                    Field (PCI0.S08.P40C, ByteAcc, NoLock, Preserve)
                    {
                        PRQ0,   8, 
                        PRQ1,   8, 
                        PRQ2,   8, 
                        PRQ3,   8
                    }
                }

                Device (KBD)
                {
                    Name (_HID, EisaId ("PNP0303") /* IBM Enhanced Keyboard (101/102-key, PS/2 Mouse) */)  // _HID: Hardware ID
                    Name (_STA, 0x0F)  // _STA: Status
                    Name (_CRS, ResourceTemplate ()  // _CRS: Current Resource Settings
                    {
                        IO (Decode16,
                            0x0060,             // Range Minimum
                            0x0060,             // Range Maximum
                            0x01,               // Alignment
                            0x01,               // Length
                            )
                        IO (Decode16,
                            0x0064,             // Range Minimum
                            0x0064,             // Range Maximum
                            0x01,               // Alignment
                            0x01,               // Length
                            )
                        IRQNoFlags ()
                            {1}
                    })
                }

                Device (MOU)
                {
                    Name (_HID, EisaId ("PNP0F13") /* PS/2 Mouse */)  // _HID: Hardware ID
                    Name (_STA, 0x0F)  // _STA: Status
                    Name (_CRS, ResourceTemplate ()  // _CRS: Current Resource Settings
                    {
                        IRQNoFlags ()
                            {12}
                    })
                }

                Device (FDC0)
                {
                    Name (_HID, EisaId ("PNP0700"))  // _HID: Hardware ID
                    Name (_CRS, ResourceTemplate ()  // _CRS: Current Resource Settings
                    {
                        IO (Decode16,
                            0x03F2,             // Range Minimum
                            0x03F2,             // Range Maximum
                            0x00,               // Alignment
                            0x04,               // Length
                            )
                        IO (Decode16,
                            0x03F7,             // Range Minimum
                            0x03F7,             // Range Maximum
                            0x00,               // Alignment
                            0x01,               // Length
                            )
                        IRQNoFlags ()
                            {6}
                        DMA (Compatibility, NotBusMaster, Transfer8, )
                            {2}
                    })
                    Device (FLPA)
                    {
                        Name (_ADR, Zero)  // _ADR: Address
                        Name (_FDI, Package (0x10)  // _FDI: Floppy Drive Information
                        {
                            Zero, 
                            0x05, 
                            0x4F, 
                            0x30, 
                            One, 
                            0xAF, 
                            0x02, 
                            0x25, 
                            0x02, 
                            0x12, 
                            0x1B, 
                            0xFF, 
                            0x6C, 
                            0xF6, 
                            0x0F, 
                            0x08
                        })
                    }

                    Name (_FDE, Buffer (0x14)  // _FDE: Floppy Disk Enumerate
                    {
                        /* 0000 */  0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // ........
                        /* 0008 */  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // ........
                        /* 0010 */  0x02, 0x00, 0x00, 0x00                           // ....
                    })
                }

                Device (LPT1)
                {
                    Name (_HID, EisaId ("PNP0400") /* Standard LPT Parallel Port */)  // _HID: Hardware ID
                    Name (_UID, One)  // _UID: Unique ID
                    Name (_STA, 0x0F)  // _STA: Status
                    Name (_CRS, ResourceTemplate ()  // _CRS: Current Resource Settings
                    {
                        IO (Decode16,
                            0x0378,             // Range Minimum
                            0x0378,             // Range Maximum
                            0x08,               // Alignment
                            0x08,               // Length
                            )
                        IRQNoFlags ()
                            {7}
                    })
                }

                Device (COM1)
                {
                    Name (_HID, EisaId ("PNP0501") /* 16550A-compatible COM Serial Port */)  // _HID: Hardware ID
                    Name (_UID, One)  // _UID: Unique ID
                    Name (_STA, 0x0F)  // _STA: Status
                    Name (_CRS, ResourceTemplate ()  // _CRS: Current Resource Settings
                    {
                        IO (Decode16,
                            0x03F8,             // Range Minimum
                            0x03F8,             // Range Maximum
                            0x00,               // Alignment
                            0x08,               // Length
                            )
                        IRQNoFlags ()
                            {4}
                    })
                }

                Device (RTC)
                {
                    Name (_HID, EisaId ("PNP0B00") /* AT Real-Time Clock */)  // _HID: Hardware ID
                    Name (_CRS, ResourceTemplate ()  // _CRS: Current Resource Settings
                    {
                        IO (Decode16,
                            0x0070,             // Range Minimum
                            0x0070,             // Range Maximum
                            0x01,               // Alignment
                            0x08,               // Length
                            )
                        IRQNoFlags ()
                            {8}
                    })
                }
            }

            Device (S09)
            {
                Name (_ADR, 0x00010001)  // _ADR: Address
            }

            Device (S0B)
            {
                Name (_ADR, 0x00010003)  // _ADR: Address
            }

            Device (S10)
            {
                Name (_ADR, 0x00020000)  // _ADR: Address
                Method (_S1D, 0, NotSerialized)  // _S1D: S1 Device State
                {
                    Return (Zero)
                }

                Method (_S2D, 0, NotSerialized)  // _S2D: S2 Device State
                {
                    Return (Zero)
                }

                Method (_S3D, 0, NotSerialized)  // _S3D: S3 Device State
                {
                    Return (Zero)
                }
            }

            Device (S18)
            {
                Name (_ADR, 0x00030000)  // _ADR: Address
            }

            Name (BSEL, Zero)
            Scope (S18)
            {
                Name (ASUN, 0x03)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S18_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x03)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (S20)
            {
                Name (_ADR, 0x00040000)  // _ADR: Address
                Name (ASUN, 0x04)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S20_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x04)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (S28)
            {
                Name (_ADR, 0x00050000)  // _ADR: Address
                Name (ASUN, 0x05)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S28_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x05)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (S30)
            {
                Name (_ADR, 0x00060000)  // _ADR: Address
                Name (ASUN, 0x06)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S30_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x06)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (S38)
            {
                Name (_ADR, 0x00070000)  // _ADR: Address
                Name (ASUN, 0x07)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S38_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x07)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (S40)
            {
                Name (_ADR, 0x00080000)  // _ADR: Address
                Name (ASUN, 0x08)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S40_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x08)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (S48)
            {
                Name (_ADR, 0x00090000)  // _ADR: Address
                Name (ASUN, 0x09)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S48_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x09)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (S50)
            {
                Name (_ADR, 0x000A0000)  // _ADR: Address
                Name (ASUN, 0x0A)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S50_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x0A)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (S58)
            {
                Name (_ADR, 0x000B0000)  // _ADR: Address
                Name (ASUN, 0x0B)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S58_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x0B)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (S60)
            {
                Name (_ADR, 0x000C0000)  // _ADR: Address
                Name (ASUN, 0x0C)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S60_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x0C)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (S68)
            {
                Name (_ADR, 0x000D0000)  // _ADR: Address
                Name (ASUN, 0x0D)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S68_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x0D)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (S70)
            {
                Name (_ADR, 0x000E0000)  // _ADR: Address
                Name (ASUN, 0x0E)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S70_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x0E)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (S78)
            {
                Name (_ADR, 0x000F0000)  // _ADR: Address
                Name (ASUN, 0x0F)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S78_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x0F)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (S80)
            {
                Name (_ADR, 0x00100000)  // _ADR: Address
                Name (ASUN, 0x10)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S80_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x10)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (S88)
            {
                Name (_ADR, 0x00110000)  // _ADR: Address
                Name (ASUN, 0x11)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S88_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x11)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (S90)
            {
                Name (_ADR, 0x00120000)  // _ADR: Address
                Name (ASUN, 0x12)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S90_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x12)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (S98)
            {
                Name (_ADR, 0x00130000)  // _ADR: Address
                Name (ASUN, 0x13)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.S98_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x13)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (SA0)
            {
                Name (_ADR, 0x00140000)  // _ADR: Address
                Name (ASUN, 0x14)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.SA0_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x14)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (SA8)
            {
                Name (_ADR, 0x00150000)  // _ADR: Address
                Name (ASUN, 0x15)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.SA8_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x15)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (SB0)
            {
                Name (_ADR, 0x00160000)  // _ADR: Address
                Name (ASUN, 0x16)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.SB0_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x16)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (SB8)
            {
                Name (_ADR, 0x00170000)  // _ADR: Address
                Name (ASUN, 0x17)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.SB8_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x17)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (SC0)
            {
                Name (_ADR, 0x00180000)  // _ADR: Address
                Name (ASUN, 0x18)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.SC0_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x18)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (SC8)
            {
                Name (_ADR, 0x00190000)  // _ADR: Address
                Name (ASUN, 0x19)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.SC8_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x19)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (SD0)
            {
                Name (_ADR, 0x001A0000)  // _ADR: Address
                Name (ASUN, 0x1A)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.SD0_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x1A)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (SD8)
            {
                Name (_ADR, 0x001B0000)  // _ADR: Address
                Name (ASUN, 0x1B)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.SD8_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x1B)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (SE0)
            {
                Name (_ADR, 0x001C0000)  // _ADR: Address
                Name (ASUN, 0x1C)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.SE0_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x1C)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (SE8)
            {
                Name (_ADR, 0x001D0000)  // _ADR: Address
                Name (ASUN, 0x1D)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.SE8_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x1D)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (SF0)
            {
                Name (_ADR, 0x001E0000)  // _ADR: Address
                Name (ASUN, 0x1E)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.SF0_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x1E)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Device (SF8)
            {
                Name (_ADR, 0x001F0000)  // _ADR: Address
                Name (ASUN, 0x1F)
                Method (_DSM, 4, Serialized)  // _DSM: Device-Specific Method
                {
                    Local0 = Package (0x02)
                        {
                            Zero, 
                            Zero
                        }
                    Local0 [Zero] = BSEL /* \_SB_.PCI0.BSEL */
                    Local0 [One] = ASUN /* \_SB_.PCI0.SF8_.ASUN */
                    Return (PDSM (Arg0, Arg1, Arg2, Arg3, Local0))
                }

                Name (_SUN, 0x1F)  // _SUN: Slot User Number
                Method (_EJ0, 1, NotSerialized)  // _EJx: Eject Device, x=0-9
                {
                    PCEJ (BSEL, _SUN)
                }
            }

            Method (DVNT, 2, NotSerialized)
            {
                If ((Arg0 & 0x08))
                {
                    Notify (S18, Arg1)
                }

                If ((Arg0 & 0x10))
                {
                    Notify (S20, Arg1)
                }

                If ((Arg0 & 0x20))
                {
                    Notify (S28, Arg1)
                }

                If ((Arg0 & 0x40))
                {
                    Notify (S30, Arg1)
                }

                If ((Arg0 & 0x80))
                {
                    Notify (S38, Arg1)
                }

                If ((Arg0 & 0x0100))
                {
                    Notify (S40, Arg1)
                }

                If ((Arg0 & 0x0200))
                {
                    Notify (S48, Arg1)
                }

                If ((Arg0 & 0x0400))
                {
                    Notify (S50, Arg1)
                }

                If ((Arg0 & 0x0800))
                {
                    Notify (S58, Arg1)
                }

                If ((Arg0 & 0x1000))
                {
                    Notify (S60, Arg1)
                }

                If ((Arg0 & 0x2000))
                {
                    Notify (S68, Arg1)
                }

                If ((Arg0 & 0x4000))
                {
                    Notify (S70, Arg1)
                }

                If ((Arg0 & 0x8000))
                {
                    Notify (S78, Arg1)
                }

                If ((Arg0 & 0x00010000))
                {
                    Notify (S80, Arg1)
                }

                If ((Arg0 & 0x00020000))
                {
                    Notify (S88, Arg1)
                }

                If ((Arg0 & 0x00040000))
                {
                    Notify (S90, Arg1)
                }

                If ((Arg0 & 0x00080000))
                {
                    Notify (S98, Arg1)
                }

                If ((Arg0 & 0x00100000))
                {
                    Notify (SA0, Arg1)
                }

                If ((Arg0 & 0x00200000))
                {
                    Notify (SA8, Arg1)
                }

                If ((Arg0 & 0x00400000))
                {
                    Notify (SB0, Arg1)
                }

                If ((Arg0 & 0x00800000))
                {
                    Notify (SB8, Arg1)
                }

                If ((Arg0 & 0x01000000))
                {
                    Notify (SC0, Arg1)
                }

                If ((Arg0 & 0x02000000))
                {
                    Notify (SC8, Arg1)
                }

                If ((Arg0 & 0x04000000))
                {
                    Notify (SD0, Arg1)
                }

                If ((Arg0 & 0x08000000))
                {
                    Notify (SD8, Arg1)
                }

                If ((Arg0 & 0x10000000))
                {
                    Notify (SE0, Arg1)
                }

                If ((Arg0 & 0x20000000))
                {
                    Notify (SE8, Arg1)
                }

                If ((Arg0 & 0x40000000))
                {
                    Notify (SF0, Arg1)
                }

                If ((Arg0 & 0x80000000))
                {
                    Notify (SF8, Arg1)
                }
            }
        }
    }

    Scope (\_SB.PCI0)
    {
        Method (PCNT, 0, NotSerialized)
        {
            BNUM = Zero
            DVNT (PCIU, One)
            DVNT (PCID, 0x03)
        }
    }

    Scope (_GPE)
    {
        Method (_E01, 0, NotSerialized)  // _Exx: Edge-Triggered GPE, xx=0x00-0xFF
        {
            Acquire (\_SB.PCI0.BLCK, 0xFFFF)
            \_SB.PCI0.PCNT ()
            Release (\_SB.PCI0.BLCK)
        }
    }
}

