// Based on:
// https://en.wikipedia.org/wiki/Executable_and_Linkable_Format
// http://www.skyfree.org/linux/references/ELF_Format.pdf
// http://www.sco.com/developers/gabi/2000-07-17/ch4.eheader.html

#ifndef _ELF_H_
#define _ELF_H_

#include "types.h"

// e_ident_version/e_ident[EI_VERSION]
#define EI_MAG0    0x00 // File identification
#define EI_MAG1    0x01 // File identification
#define EI_MAG2    0x02 // File identification
#define EI_MAG3    0x03 // File identification
#define EI_CLASS   0x04 // File class
#define EI_DATA    0x05 // Data encoding
#define EI_VERSION 0x06 // File version
#define EI_PAD     0x07 // Start of padding bytes
#define EI_NIDENT  0x10 // Size of e_ident[]

// e_class/e_ident[EI_CLASS]
#define CLASS_32_BIT 1
#define CLASS_64_BIT 2

// e_endianness/e_ident[EI_DATA]
#define LITTLE_ENDIAN 1
#define BIG_ENDIAN    2

// e_os_abi/e_ident[EI_OSABI]
#define SYSTEM_V        0x00 // SystemV
#define HP_UX           0x01 // HP-UX
#define NET_BSD         0x02 // NetBSD
#define LINUX           0x03 // Linux
#define GNU_HURD        0x04 // GNU Hurd
#define SOLARIS         0x06 // Solaris
#define AIX             0x07 // AIX
#define IRIX            0x08 // IRIX
#define FREE_BSD        0x09 // FreeBSD
#define TRU_64          0x0A // Tru64
#define NOVEL_MODESTO   0x0B // Novell Modesto
#define OPEN_BSD        0x0C // OpenBSD
#define OPEN_VMS        0x0D // OpenVMS
#define NON_STOP_KERNEL 0x0E // NonStop_Kernel
#define AROS            0x0F // AROS
#define Fenix_OS        0x10 // Fenix OS
#define CLOUD_ABI       0x11 // CloudABI
#define Sortix          0x53 // Sortix

// e_machine
#define EM_NONE 	    0x00    // No machine
#define EM_M32 	        0x01    // AT&T WE 32100
#define EM_SPARC 	    0x02    // SPARC
#define EM_386          0x03    // Intel 80386
#define EM_68K          0x04    // Motorola 68000
#define EM_88K 	        0x05    // Motorola 88000
#define EM_860 	        0x07    // Intel 80860
#define EM_MIPS 	    0x08    // MIPS I Architecture
#define EM_S370 	    0x09    // IBM System/370 Processor
#define EM_MIPS_RS3_LE  0x0A    // MIPS RS3000 Little-endian
#define EM_PARISC 	    0x0F    // Hewlett-Packard PA-RISC
#define EM_VPP500 	    0x11    // Fujitsu VPP500
#define EM_SPARC32PLUS 	0x12    // Enhanced instruction set SPARC
#define EM_960          0x13    // Intel 80960
#define EM_PPC          0x14    // PowerPC
#define EM_PPC64        0x15    // 64-bit PowerPC
#define EM_V800 	    0x24    // NEC V800
#define EM_FR20         0x25    // Fujitsu FR20
#define EM_RH32 	    0x26    // TRW RH-32
#define EM_RCE          0x27    // Motorola RCE
#define EM_ARM          0x28    // Advanced RISC Machines ARM
#define EM_ALPHA 	    0x29    // Digital Alpha
#define EM_SH           0x2A    // Hitachi SH
#define EM_SPARCV9      0x2B    // SPARC Version 9
#define EM_TRICORE 	    0x2C    // Siemens Tricore embedded processor
#define EM_ARC 	        0x2D    // Argonaut RISC Core, Argonaut Technologies Inc.
#define EM_H8_300 	    0x2E    // Hitachi H8/300
#define EM_H8_300H 	    0x2F    // Hitachi H8/300H
#define EM_H8S 	        0x30    // Hitachi H8S
#define EM_H8_500 	    0x31    // Hitachi H8/500
#define EM_IA_64 	    0x32    // Intel IA-64 processor architecture
#define EM_MIPS_X 	    0x33    // Stanford MIPS-X
#define EM_COLDFIRE 	0x34    // Motorola ColdFire
#define EM_68HC12 	    0x35    // Motorola M68HC12
#define EM_MMA 	        0x36    // Fujitsu MMA Multimedia Accelerator
#define EM_PCP 	        0x37    // Siemens PCP
#define EM_NCPU 	    0x38    // Sony nCPU embedded RISC processor
#define EM_NDR1 	    0x39    // Denso NDR1 microprocessor
#define EM_STARCORE 	0x3A    // Motorola Star*Core processor
#define EM_ME16 	    0x3B    // Toyota ME16 processor
#define EM_ST100 	    0x3C    // STMicroelectronics ST100 processor
#define EM_TINYJ 	    0x3D    // Advanced Logic Corp. TinyJ embedded processor family
#define EM_X86_64       0x3E    // x86-64
#define EM_FX66 	    0x42    // Siemens FX66 microcontroller
#define EM_ST9PLUS 	    0x43    // STMicroelectronics ST9+ 8/16 bit microcontroller
#define EM_ST7 	        0x44    // STMicroelectronics ST7 8-bit microcontroller
#define EM_68HC16 	    0x45    // Motorola MC68HC16 Microcontroller
#define EM_68HC11 	    0x46    // Motorola MC68HC11 Microcontroller
#define EM_68HC08 	    0x47    // Motorola MC68HC08 Microcontroller
#define EM_68HC05 	    0x48    // Motorola MC68HC05 Microcontroller
#define EM_SVX 	        0x49    // Silicon Graphics SVx
#define EM_ST19 	    0x4A    // STMicroelectronics ST19 8-bit microcontroller
#define EM_VAX 	        0x4B    // Digital VAX
#define EM_CRIS 	    0x4C    // Axis Communications 32-bit embedded processor
#define EM_JAVELIN 	    0x4D    // Infineon Technologies 32-bit embedded processor
#define EM_FIREPATH 	0x4E    // Element 14 64-bit DSP Processor
#define EM_ZSP 	        0x4F    // LSI Logic 16-bit DSP Processor
#define EM_MMIX 	    0x50    // Donald Knuth's educational 64-bit processor
#define EM_HUANY 	    0x51    // Harvard University machine-independent object files
#define EM_PRISM 	    0x52    // SiTera Prism
#define EM_AARCH64      0xB7    // AArch64
#define EM_RISC_V       0xF3    // RISC-V

// e_type
#define ET_NONE   0x0000 // No file type
#define ET_REL    0x0001 // Relocatable file
#define ET_EXEC   0x0002 // Executable file
#define ET_DYN    0x0003 // Shared object file
#define ET_CORE   0x0004 // Core file
#define ET_LOPROC 0xFF00 // Processor-specific
#define ET_HIPROC 0xFFFF // Processor-specific

// e_version
#define EV_NONE    0x00 // Invalid version
#define EV_CURRENT 0x01 // Current version

// Size = 0x34 (dec 50)
struct elf_header_32 {
    union {
        u8 e_ident[EI_NIDENT];

        struct {
            u8 e_magic[4];      // Offset: 0x00, size 4
            u8 e_class;         // Offset: 0x04, size 1
            u8 e_endianness;    // Offset: 0x05, size 1
            u8 e_ident_version; // Offset: 0x06, size 1
            u8 e_os_abi;        // Offset: 0x07, size 1
            u8 e_abi_version;   // Offset: 0x08, size 1
            u8 e_unused[7];     // Offset: 0x09, size 7
        };
    };

    u16 e_type;             // Offset: 0x10, size 2
    u16 e_machine;          // Offset: 0x12, size 2
    u32 e_version;          // Offset: 0x14, size 4
    u32 e_entry;            // Offset: 0x18, size 4
    u32 e_phoff;            // Offset: 0x1C, size 4
    u32 e_shoff;            // Offset: 0x20, size 4
    u32 e_flags;            // Offset: 0x24, size 4
    u16 e_ehsize;           // Offset: 0x28, size 2
    u16 e_phentsize;        // Offset: 0x2A, size 2
    u16 e_phnum;            // Offset: 0x2C, size 2
    u16 e_shentsize;        // Offset: 0x2E, size 2
    u16 e_shnum;            // Offset: 0x30, size 2
    u16 e_shstrndx;         // Offset: 0x32, size 2
};

// Size = 0x40 (dec 64)
struct elf_header_64 {
    union {
        u8 e_ident[EI_NIDENT];

        struct {
            u8 e_magic[4];      // Offset: 0x00, size 4
            u8 e_class;         // Offset: 0x04, size 1
            u8 e_endianness;    // Offset: 0x05, size 1
            u8 e_ident_version; // Offset: 0x06, size 1
            u8 e_os_abi;        // Offset: 0x07, size 1
            u8 e_abi_version;   // Offset: 0x08, size 1
            u8 e_unused[7];     // Offset: 0x09, size 7
        };
    };

    u16 e_type;      // Offset: 0x10, size 2
    u16 e_machine;   // Offset: 0x12, size 2
    u32 e_version;   // Offset: 0x14, size 4
    u64 e_entry;     // Offset: 0x18, size 8
    u64 e_phoff;     // Offset: 0x20, size 8
    u64 e_shoff;     // Offset: 0x28, size 8
    u32 e_flags;     // Offset: 0x30, size 4
    u16 e_ehsize;    // Offset: 0x34, size 2
    u16 e_phentsize; // Offset: 0x36, size 2
    u16 e_phnum;     // Offset: 0x38, size 2
    u16 e_shentsize; // Offset: 0x3A, size 2
    u16 e_shnum;     // Offset: 0x3C, size 2
    u16 e_shstrndx;  // Offset: 0x3E, size 2
};

// p_type
// PT_LOOS to PT_HIOS (PT_LOPROC to PT_HIPROC) is an inclusive reserved ranges for operating system (processor) specific semantics.
#define PT_NULL    0x00000000
#define PT_LOAD    0x00000001
#define PT_DYNAMIC 0x00000002
#define PT_INTERP  0x00000003
#define PT_NOTE    0x00000004
#define PT_SHLIB   0x00000005
#define PT_PHDR    0x00000006
#define PT_LOOS    0x60000000
#define PT_HIOS    0x6FFFFFFF
#define PT_LOPROC  0x70000000
#define PT_HIPROC  0x7FFFFFFF

// Size = 0x20 (dec: 32)
struct elf_program_header_32 {
    u32 p_type;   // Identifies the type of the segment.                                                                                                  Offset: 0x00, size 4
    u32 p_offset; // Offset of the segment in the file image.                                                                                             Offset: 0x04, size 4
    u32 p_vaddr;  // Virtual address of the segment in memory.                                                                                            Offset: 0x08, size 4
    u32 p_paddr;  // On systems where physical address is relevant, reserved for segment's physical address.                                              Offset: 0x0C, size 4
    u32 p_filesz; // Size in bytes of the segment in the file image. May be 0.                                                                            Offset: 0x10, size 4
    u32 p_memsz;  // Size in bytes of the segment in memory. May be 0.                                                                                    Offset: 0x14, size 4
    u32 p_flags;  // Segment-dependent flags (position for 32-bit structure).                                                                             Offset: 0x18, size 4
    u32 p_align;  // 0 and 1 specify no alignment. Otherwise should be a positive, integral power of 2, with p_vaddr equating p_offset modulus p_align.   Offset: 0x1C, size 4
};

// Size = 0x38 (dec: 56)
struct elf_program_header_64 {
    u32 p_type;   // Identifies the type of the segment.                                                                                                  Offset: 0x00, size 4
    u32 p_flags;  // Segment-dependent flags (position for 64-bit structure).                                                                             Offset: 0x04, size 4
    u64 p_offset; // Offset of the segment in the file image.                                                                                             Offset: 0x08, size 8
    u64 p_vaddr;  // Virtual address of the segment in memory.                                                                                            Offset: 0x10, size 8
    u64 p_paddr;  // On systems where physical address is relevant, reserved for segment's physical address.                                              Offset: 0x18, size 8
    u64 p_filesz; // Size in bytes of the segment in the file image. May be 0.                                                                            Offset: 0x20, size 8
    u64 p_memsz;  // Size in bytes of the segment in memory. May be 0.                                                                                    Offset: 0x28, size 8
    u64 p_align;  // 0 and 1 specify no alignment. Otherwise should be a positive, integral power of 2, with p_vaddr equating p_offset modulus p_align.   Offset: 0x30, size 8
};

// sh_type
#define SHT_NULL          0x00000000 // Section header table entry unused
#define SHT_PROGBITS      0x00000001 // Program data
#define SHT_SYMTAB        0x00000002 // Symbol table
#define SHT_STRTAB        0x00000003 // String table
#define SHT_RELA          0x00000004 // Relocation entries with addends
#define SHT_HASH          0x00000005 // Symbol hash table
#define SHT_DYNAMIC       0x00000006 // Dynamic linking information
#define SHT_NOTE          0x00000007 // Notes
#define SHT_NOBITS        0x00000008 // Program space with no data (bss)
#define SHT_REL           0x00000009 // Relocation entries, no addends
#define SHT_SHLIB         0x0000000A // Reserved
#define SHT_DYNSYM        0x0000000B // Dynamic linker symbol table
#define SHT_INIT_ARRAY    0x0000000E // Array of constructors
#define SHT_FINI_ARRAY    0x0000000F // Array of destructors
#define SHT_PREINIT_ARRAY 0x00000010 // Array of pre-constructors
#define SHT_GROUP         0x00000011 // Section group
#define SHT_SYMTAB_SHNDX  0x00000012 // Extended section indeces
#define SHT_NUM           0x00000013 // Number of defined types.
#define SHT_LOOS          0x60000000 // Start OS-specific.

// sh_flags
#define SHF_WRITE            0x00000001 // Writable
#define SHF_ALLOC            0x00000002 // Occupies memory during execution
#define SHF_EXECINSTR        0x00000004 // Executable
#define SHF_MERGE            0x00000010 // Might be merged
#define SHF_STRINGS          0x00000020 // Contains nul-terminated strings
#define SHF_INFO_LINK        0x00000040 // 'sh_info' contains SHT index
#define SHF_LINK_ORDER       0x00000080 // Preserve order after combining
#define SHF_OS_NONCONFORMING 0x00000100 // Non-standard OS specific handling required
#define SHF_GROUP            0x00000200 // Section is member of a group
#define SHF_TLS              0x00000400 // Section hold thread-local data
#define SHF_MASKOS           0x0FF00000 // OS-specific
#define SHF_MASKPROC         0xF0000000 // Processor-specific
#define SHF_ORDERED          0x04000000 // Special ordering requirement (Solaris)
#define SHF_EXCLUDE          0x08000000 // Section is excluded unless referenced or allocated (Solaris)

// Size = 0x28 (dec: 40)
struct elf_section_header_32 {
    u32 sh_name;      // An offset to a string in the .shstrtab section that represents the name of this section.                                         Offset: 0x00, size 4
    u32	sh_type;      // Identifies the type of this header.                                                                                              Offset: 0x04, size 4
    u32 sh_flags;     // Identifies the attributes of the section.                                                                                        Offset: 0x08, size 4
    u32 sh_addr;      // Virtual address of the section in memory, for sections that are loaded.                                                          Offset: 0x0C, size 4
    u32 sh_offset;    // Offset of the section in the file image.                                                                                         Offset: 0x10, size 4
    u32 sh_size;      // Size in bytes of the section in the file image. May be 0.                                                                        Offset: 0x14, size 4
    u32 sh_link;      // Contains the section index of an associated section. This field is used for several purposes, depending on the type of section.  Offset: 0x18, size 4
    u32 sh_info;      // Contains extra information about the section. This field is used for several purposes, depending on the type of section.         Offset: 0x1C, size 4
    u32 sh_addralign; // Contains the required alignment of the section. This field must be a power of two.                                               Offset: 0x20, size 4
    u32 sh_entsize;   // Contains the size, in bytes, of each entry, for sections that contain fixed-size entries. Otherwise, this field contains zero.   Offset: 0x24, size 4
};

// Size = 0x40 (dec: 64)
struct elf_section_header_64 {
    u32 sh_name;      // An offset to a string in the .shstrtab section that represents the name of this section.                                         Offset: 0x00, size 4
    u32	sh_type;      // Identifies the type of this header.                                                                                              Offset: 0x04, size 4
    u64 sh_flags;     // Identifies the attributes of the section.                                                                                        Offset: 0x08, size 8
    u64 sh_addr;      // Virtual address of the section in memory, for sections that are loaded.                                                          Offset: 0x10, size 8
    u64 sh_offset;    // Offset of the section in the file image.                                                                                         Offset: 0x18, size 8
    u64 sh_size;      // Size in bytes of the section in the file image. May be 0.                                                                        Offset: 0x20, size 8
    u32 sh_link;      // Contains the section index of an associated section. This field is used for several purposes, depending on the type of section.  Offset: 0x28, size 4
    u32 sh_info;      // Contains extra information about the section. This field is used for several purposes, depending on the type of section.         Offset: 0x2C, size 4
    u64 sh_addralign; // Contains the required alignment of the section. This field must be a power of two.                                               Offset: 0x30, size 8
    u64 sh_entsize;   // Contains the size, in bytes, of each entry, for sections that contain fixed-size entries. Otherwise, this field contains zero.   Offset: 0x38, size 8
};

#endif // _ELF_H_