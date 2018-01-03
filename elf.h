// Based on:
// https://en.wikipedia.org/wiki/Executable_and_Linkable_Format
// http://www.skyfree.org/linux/references/ELF_Format.pdf
// http://www.sco.com/developers/gabi/2000-07-17/ch4.eheader.html

#ifndef _ELF_H_
#define _ELF_H_

#include "types.h"

enum eclass : u8 {
    arch_32_bit = 1,
    arch_64_bit = 2
};

enum eosabi : u8 {
    SystemV         = 0x00,
    HP_UX           = 0x01,
    NetBSD          = 0x02,
    Linux           = 0x03,
    GNU_Hurd        = 0x04,
    Solaris         = 0x06,
    AIX             = 0x07,
    IRIX            = 0x08,
    FreeBSD         = 0x09,
    Tru64           = 0x0A,
    Novell_Modesto  = 0x0B,
    OpenBSD         = 0x0C,
    OpenVMS         = 0x0D,
    NonStop_Kernel  = 0x0E,
    AROS            = 0x0F,
    Fenix_OS        = 0x10,
    CloudABI        = 0x11,
    Sortix          = 0x53
};

enum emachine : u16 {
    None	    = 0x00, // No machine
    M32	        = 0x01, // AT&T WE 32100
    SPARC	    = 0x02, // SPARC
    i386	    = 0x03, // Intel 80386
    Moto68K	    = 0x04, // Motorola 68000
    Moto88K	    = 0x05, // Motorola 88000
    i860	    = 0x07, // Intel 80860
    MIPS	    = 0x08, // MIPS I Architecture
    S370	    = 0x09, // IBM System/370 Processor
    MIPS_RS3_LE	= 0x0A, // MIPS RS3000 Little-endian
    PARISC	    = 0x0F, // Hewlett-Packard PA-RISC
    VPP500	    = 0x11, // Fujitsu VPP500
    SPARC32PLUS	= 0x12, // Enhanced instruction set SPARC
    i960	    = 0x13, // Intel 80960
    PPC	        = 0x14, // PowerPC
    PPC64	    = 0x15, // 64-bit PowerPC
    V800	    = 0x24, // NEC V800
    FR20	    = 0x25, // Fujitsu FR20
    RH32	    = 0x26, // TRW RH-32
    RCE	        = 0x27, // Motorola RCE
    ARM         = 0x28, // Advanced RISC Machines ARM
    ALPHA	    = 0x29, // Digital Alpha
    SuperH	    = 0x2A, // Hitachi SH
    SPARCV9	    = 0x2B, // SPARC Version 9
    TRICORE	    = 0x2C, // Siemens Tricore embedded processor
    ARC	        = 0x2D, // Argonaut RISC Core, Argonaut Technologies Inc.
    H8_300	    = 0x2E, // Hitachi H8/300
    H8_300H	    = 0x2F, // Hitachi H8/300H
    H8S	        = 0x30, // Hitachi H8S
    H8_500	    = 0x31, // Hitachi H8/500
    IA_64	    = 0x32, // Intel IA-64 processor architecture
    MIPS_X	    = 0x33, // Stanford MIPS-X
    COLDFIRE    = 0x34, // Motorola ColdFire
    Moto68HC12	= 0x35, // Motorola M68HC12
    MMA	        = 0x36, // Fujitsu MMA Multimedia Accelerator
    PCP	        = 0x37, // Siemens PCP
    NCPU	    = 0x38, // Sony nCPU embedded RISC processor
    NDR1	    = 0x39, // Denso NDR1 microprocessor
    STARCORE	= 0x3A, // Motorola Star*Core processor
    ME16	    = 0x3B, // Toyota ME16 processor
    ST100	    = 0x3C, // STMicroelectronics ST100 processor
    TINYJ	    = 0x3D, // Advanced Logic Corp. TinyJ embedded processor family
    x86_64      = 0x3E, // x86-64
    FX66	    = 0x42, // Siemens FX66 microcontroller
    ST9PLUS	    = 0x43, // STMicroelectronics ST9+ 8/16 bit microcontroller
    ST7         = 0x44, // STMicroelectronics ST7 8-bit microcontroller
    Moto68HC16	= 0x45, // Motorola MC68HC16 Microcontroller
    Moto68HC11	= 0x46, // Motorola MC68HC11 Microcontroller
    Moto68HC08	= 0x47, // Motorola MC68HC08 Microcontroller
    Moto68HC05	= 0x48, // Motorola MC68HC05 Microcontroller
    SVX	        = 0x49, // Silicon Graphics SVx
    ST19	    = 0x4A, // STMicroelectronics ST19 8-bit microcontroller
    VAX	        = 0x4B, // Digital VAX
    CRIS	    = 0x4C, // Axis Communications 32-bit embedded processor
    JAVELIN	    = 0x4D, // Infineon Technologies 32-bit embedded processor
    FIREPATH	= 0x4E, // Element 14 64-bit DSP Processor
    ZSP	        = 0x4F, // LSI Logic 16-bit DSP Processor
    MMIX	    = 0x50, // Donald Knuth's educational 64-bit processor
    HUANY	    = 0x51, // Harvard University machine-independent object files
    PRISM	    = 0x52, // SiTera Prism
    AArch64     = 0xB7, // AArch64
 	RISC_V      = 0xF3  // RISC-V
};

enum etype : u16 {
    none    = 0,        // No file type
    rel     = 1,        // Relocatable file
    exec    = 2,        // Executable file
    dyn     = 3,        // Shared object file
    core    = 4,        // Core file
    loproc  = 0xFF00,   // Processor-specific
    hiproc  = 0xFFFF    // Processor-specific
};

enum eendianness : u8 {
    little_endian = 1,
    big_endian    = 2
};

struct elf_header_32 {
    u8          e_magic[4];         // Offset: 0x00, size 4
    eclass      e_class;            // Offset: 0x04, size 1
    eendianness e_endianness;       // Offset: 0x05, size 1
    u8          e_ident_version;    // Offset: 0x06, size 1
    eosabi      e_os_abi;           // Offset: 0x07, size 1
    u8          e_abi_version;      // Offset: 0x08, size 1
    u8          e_unused[7];        // Offset: 0x09, size 7
    etype       e_type;             // Offset: 0x10, size 2
    emachine    e_machine;          // Offset: 0x12, size 2
    u32         e_version;          // Offset: 0x14, size 4
    u32         e_entry;            // Offset: 0x18, size 4
    u32         e_phoff;            // Offset: 0x1C, size 4
    u32         e_shoff;            // Offset: 0x20, size 4
    u32         e_flags;            // Offset: 0x24, size 4
    u16         e_ehsize;           // Offset: 0x28, size 2
    u16         e_phentsize;        // Offset: 0x2A, size 2
    u16         e_phnum;            // Offset: 0x2C, size 2
    u16         e_shentsize;        // Offset: 0x2E, size 2
    u16         e_shnum;            // Offset: 0x30, size 2
    u16         e_shstrndx;         // Offset: 0x32, size 2
};

#endif // _ELF_H_