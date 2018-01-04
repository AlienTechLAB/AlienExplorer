// Further reading:
// https://en.wikipedia.org/wiki/Executable_and_Linkable_Format
// http://www.skyfree.org/linux/references/ELF_Format.pdf
// http://www.sco.com/developers/gabi/2000-07-17/ch4.eheader.html

#ifndef _ELF_H_
#define _ELF_H_

#include "types.h"

// e_ident_version/e_ident[ELF_EI_VERSION]
#define ELF_EI_MAG0    0x00 // File identification
#define ELF_EI_MAG1    0x01 // File identification
#define ELF_EI_MAG2    0x02 // File identification
#define ELF_EI_MAG3    0x03 // File identification
#define ELF_EI_CLASS   0x04 // File class
#define ELF_EI_DATA    0x05 // Data encoding
#define ELF_EI_VERSION 0x06 // File version
#define ELF_EI_PAD     0x07 // Start of padding bytes
#define ELF_EI_NIDENT  0x10 // Size of e_ident[]

// e_class/e_ident[ELF_EI_CLASS]
#define ELF_CLASS_32_BIT 1
#define ELF_CLASS_64_BIT 2

// e_endianness/e_ident[ELF_EI_DATA]
#define ELF_LITTLE_ENDIAN 1
#define ELF_BIG_ENDIAN    2

// e_os_abi/e_ident[ELF_EI_OSABI]
#define ELF_SYSTEM_V        0x00 // SystemV
#define ELF_HP_UX           0x01 // HP-UX
#define ELF_NET_BSD         0x02 // NetBSD
#define ELF_LINUX           0x03 // Linux
#define ELF_GNU_HURD        0x04 // GNU Hurd
#define ELF_SOLARIS         0x06 // Solaris
#define ELF_AIX             0x07 // AIX
#define ELF_IRIX            0x08 // IRIX
#define ELF_FREE_BSD        0x09 // FreeBSD
#define ELF_TRU_64          0x0A // Tru64
#define ELF_NOVEL_MODESTO   0x0B // Novell Modesto
#define ELF_OPEN_BSD        0x0C // OpenBSD
#define ELF_OPEN_VMS        0x0D // OpenVMS
#define ELF_NON_STOP_KERNEL 0x0E // NonStop_Kernel
#define ELF_AROS            0x0F // AROS
#define ELF_Fenix_OS        0x10 // Fenix OS
#define ELF_CLOUD_ABI       0x11 // CloudABI
#define ELF_SORTIX          0x53 // Sortix

// e_machine
#define ELF_EM_NONE 	    0x00    // No machine
#define ELF_EM_M32 	        0x01    // AT&T WE 32100
#define ELF_EM_SPARC 	    0x02    // SPARC
#define ELF_EM_386          0x03    // Intel 80386
#define ELF_EM_68K          0x04    // Motorola 68000
#define ELF_EM_88K 	        0x05    // Motorola 88000
#define ELF_EM_860 	        0x07    // Intel 80860
#define ELF_EM_MIPS 	    0x08    // MIPS I Architecture
#define ELF_EM_S370 	    0x09    // IBM System/370 Processor
#define ELF_EM_MIPS_RS3_LE  0x0A    // MIPS RS3000 Little-endian
#define ELF_EM_PARISC 	    0x0F    // Hewlett-Packard PA-RISC
#define ELF_EM_VPP500 	    0x11    // Fujitsu VPP500
#define ELF_EM_SPARC32PLUS 	0x12    // Enhanced instruction set SPARC
#define ELF_EM_960          0x13    // Intel 80960
#define ELF_EM_PPC          0x14    // PowerPC
#define ELF_EM_PPC64        0x15    // 64-bit PowerPC
#define ELF_EM_V800 	    0x24    // NEC V800
#define ELF_EM_FR20         0x25    // Fujitsu FR20
#define ELF_EM_RH32 	    0x26    // TRW RH-32
#define ELF_EM_RCE          0x27    // Motorola RCE
#define ELF_EM_ARM          0x28    // Advanced RISC Machines ARM
#define ELF_EM_ALPHA 	    0x29    // Digital Alpha
#define ELF_EM_SH           0x2A    // Hitachi SH
#define ELF_EM_SPARCV9      0x2B    // SPARC Version 9
#define ELF_EM_TRICORE 	    0x2C    // Siemens Tricore embedded processor
#define ELF_EM_ARC 	        0x2D    // Argonaut RISC Core, Argonaut Technologies Inc.
#define ELF_EM_H8_300 	    0x2E    // Hitachi H8/300
#define ELF_EM_H8_300H 	    0x2F    // Hitachi H8/300H
#define ELF_EM_H8S 	        0x30    // Hitachi H8S
#define ELF_EM_H8_500 	    0x31    // Hitachi H8/500
#define ELF_EM_IA_64 	    0x32    // Intel IA-64 processor architecture
#define ELF_EM_MIPS_X 	    0x33    // Stanford MIPS-X
#define ELF_EM_COLDFIRE 	0x34    // Motorola ColdFire
#define ELF_EM_68HC12 	    0x35    // Motorola M68HC12
#define ELF_EM_MMA 	        0x36    // Fujitsu MMA Multimedia Accelerator
#define ELF_EM_PCP 	        0x37    // Siemens PCP
#define ELF_EM_NCPU 	    0x38    // Sony nCPU embedded RISC processor
#define ELF_EM_NDR1 	    0x39    // Denso NDR1 microprocessor
#define ELF_EM_STARCORE 	0x3A    // Motorola Star*Core processor
#define ELF_EM_ME16 	    0x3B    // Toyota ME16 processor
#define ELF_EM_ST100 	    0x3C    // STMicroelectronics ST100 processor
#define ELF_EM_TINYJ 	    0x3D    // Advanced Logic Corp. TinyJ embedded processor family
#define ELF_EM_X86_64       0x3E    // x86-64
#define ELF_EM_FX66 	    0x42    // Siemens FX66 microcontroller
#define ELF_EM_ST9PLUS 	    0x43    // STMicroelectronics ST9+ 8/16 bit microcontroller
#define ELF_EM_ST7 	        0x44    // STMicroelectronics ST7 8-bit microcontroller
#define ELF_EM_68HC16 	    0x45    // Motorola MC68HC16 Microcontroller
#define ELF_EM_68HC11 	    0x46    // Motorola MC68HC11 Microcontroller
#define ELF_EM_68HC08 	    0x47    // Motorola MC68HC08 Microcontroller
#define ELF_EM_68HC05 	    0x48    // Motorola MC68HC05 Microcontroller
#define ELF_EM_SVX 	        0x49    // Silicon Graphics SVx
#define ELF_EM_ST19 	    0x4A    // STMicroelectronics ST19 8-bit microcontroller
#define ELF_EM_VAX 	        0x4B    // Digital VAX
#define ELF_EM_CRIS 	    0x4C    // Axis Communications 32-bit embedded processor
#define ELF_EM_JAVELIN 	    0x4D    // Infineon Technologies 32-bit embedded processor
#define ELF_EM_FIREPATH 	0x4E    // Element 14 64-bit DSP Processor
#define ELF_EM_ZSP 	        0x4F    // LSI Logic 16-bit DSP Processor
#define ELF_EM_MMIX 	    0x50    // Donald Knuth's educational 64-bit processor
#define ELF_EM_HUANY 	    0x51    // Harvard University machine-independent object files
#define ELF_EM_PRISM 	    0x52    // SiTera Prism
#define ELF_EM_AARCH64      0xB7    // AArch64
#define ELF_EM_RISC_V       0xF3    // RISC-V

// e_type
#define ELF_ET_NONE   0x0000 // No file type
#define ELF_ET_REL    0x0001 // Relocatable file
#define ELF_ET_EXEC   0x0002 // Executable file
#define ELF_ET_DYN    0x0003 // Shared object file
#define ELF_ET_CORE   0x0004 // Core file
#define ELF_ET_LOPROC 0xFF00 // Processor-specific
#define ELF_ET_HIPROC 0xFFFF // Processor-specific

// e_version
#define ELF_EV_NONE    0x00 // Invalid version
#define ELF_EV_CURRENT 0x01 // Current version

// Size = 0x34 (dec 50)
struct elf_header_32 {
    union {
        u8 e_ident[ELF_EI_NIDENT];

        struct {
            u8 e_magic[4];      // 0x7F followed by ELF(45 4c 46) in ASCII; these four bytes constitute the magic number.                       Offset: 0x00, size 4
            u8 e_class;         // This byte is set to either 1 or 2 to signify 32 or 64-bit format, respectively.                              Offset: 0x04, size 1
            u8 e_endianness;    // This byte is set to either 1 or 2 to signify little or big endianness, respectively.                         Offset: 0x05, size 1
                                // This affects interpretation of multi-byte fields starting with offset 0x10.
            u8 e_ident_version; // Set to 1 for the original version of ELF.                                                                    Offset: 0x06, size 1
            u8 e_os_abi;        // Identifies the target operating system ABI. It is often set to 0 regardless of the target platform.          Offset: 0x07, size 1
            u8 e_abi_version;   // Further specifies the ABI version. Its interpretation depends on the target ABI.                             Offset: 0x08, size 1
                                // Linux kernel (after at least 2.6) has no definition of it.[5] In that case, offset and size of ELF_EI_PAD are 8.
            u8 e_unused[7];     // Currently unused.                                                                                            Offset: 0x09, size 7
        };
    };

    u16 e_type;      // Specify whether the object is relocatable, executable, shared, core or processor-specific. See ELF_ET_* defines above.  Offset: 0x10, size 2
    u16 e_machine;   // Specifies target instruction set architecture.                                                                          Offset: 0x12, size 2
    u32 e_version;   // Set to 1 for the original version of ELF.                                                                               Offset: 0x14, size 4
    u32 e_entry;     // This is the memory address of the entry point from where the process starts executing.                                  Offset: 0x18, size 4
    u32 e_phoff;     // Points to the start of the program header table. It usually follows the file header immediately.                        Offset: 0x1C, size 4
    u32 e_shoff;     // Points to the start of the section header table.                                                                        Offset: 0x20, size 4
    u32 e_flags;     // Interpretation of this field depends on the target architecture.                                                        Offset: 0x24, size 4
    u16 e_ehsize;    // Contains the size of this header, normally 64 Bytes for 64-bit and 52 Bytes for 32-bit format.                          Offset: 0x28, size 2
    u16 e_phentsize; // Contains the size of a program header table entry.                                                                      Offset: 0x2A, size 2
    u16 e_phnum;     // Contains the number of entries in the program header table.                                                             Offset: 0x2C, size 2
    u16 e_shentsize; // Contains the size of a section header table entry.                                                                      Offset: 0x2E, size 2
    u16 e_shnum;     // Contains the number of entries in the section header table.                                                             Offset: 0x30, size 2
    u16 e_shstrndx;  // Contains index of the section header table entry that contains the section names.                                       Offset: 0x32, size 2
};

// Size = 0x40 (dec 64)
struct elf_header_64 {
    union {
        u8 e_ident[ELF_EI_NIDENT];

        struct {
            u8 e_magic[4];      // 0x7F followed by ELF(45 4c 46) in ASCII; these four bytes constitute the magic number.                       Offset: 0x00, size 4
            u8 e_class;         // This byte is set to either 1 or 2 to signify 32 or 64-bit format, respectively.                              Offset: 0x04, size 1
            u8 e_endianness;    // This byte is set to either 1 or 2 to signify little or big endianness, respectively.                         Offset: 0x05, size 1
                                // This affects interpretation of multi-byte fields starting with offset 0x10.
            u8 e_ident_version; // Set to 1 for the original version of ELF.                                                                    Offset: 0x06, size 1
            u8 e_os_abi;        // Identifies the target operating system ABI. It is often set to 0 regardless of the target platform.          Offset: 0x07, size 1
            u8 e_abi_version;   // Further specifies the ABI version. Its interpretation depends on the target ABI.                             Offset: 0x08, size 1
                                // Linux kernel (after at least 2.6) has no definition of it.[5] In that case, offset and size of ELF_EI_PAD are 8.
            u8 e_unused[7];     // Currently unused.                                                                                            Offset: 0x09, size 7
        };
    };

    u16 e_type;      // Specify whether the object is relocatable, executable, shared, core or processor-specific. See ELF_ET_* defines above.  Offset: 0x10, size 2
    u16 e_machine;   // Specifies target instruction set architecture.                                                                          Offset: 0x12, size 2
    u32 e_version;   // Set to 1 for the original version of ELF.                                                                               Offset: 0x14, size 4
    u64 e_entry;     // This is the memory address of the entry point from where the process starts executing.                                  Offset: 0x18, size 8
    u64 e_phoff;     // Points to the start of the program header table. It usually follows the file header immediately.                        Offset: 0x20, size 8
    u64 e_shoff;     // Points to the start of the section header table.                                                                        Offset: 0x28, size 8
    u32 e_flags;     // Interpretation of this field depends on the target architecture.                                                        Offset: 0x30, size 4
    u16 e_ehsize;    // Contains the size of this header, normally 64 Bytes for 64-bit and 52 Bytes for 32-bit format.                          Offset: 0x34, size 2
    u16 e_phentsize; // Contains the size of a program header table entry.                                                                      Offset: 0x36, size 2
    u16 e_phnum;     // Contains the number of entries in the program header table.                                                             Offset: 0x38, size 2
    u16 e_shentsize; // Contains the size of a section header table entry.                                                                      Offset: 0x3A, size 2
    u16 e_shnum;     // Contains the number of entries in the section header table.                                                             Offset: 0x3C, size 2
    u16 e_shstrndx;  // Contains index of the section header table entry that contains the section names.                                       Offset: 0x3E, size 2
};

// p_type
// ELF_PT_LOOS to ELF_PT_HIOS (ELF_PT_LOPROC to ELF_PT_HIPROC) is an inclusive reserved ranges for operating system (processor) specific semantics.
#define ELF_PT_NULL    0x00000000
#define ELF_PT_LOAD    0x00000001
#define ELF_PT_DYNAMIC 0x00000002
#define ELF_PT_INTERP  0x00000003
#define ELF_PT_NOTE    0x00000004
#define ELF_PT_SHLIB   0x00000005
#define ELF_PT_PHDR    0x00000006
#define ELF_PT_LOOS    0x60000000
#define ELF_PT_HIOS    0x6FFFFFFF
#define ELF_PT_LOPROC  0x70000000
#define ELF_PT_HIPROC  0x7FFFFFFF

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
#define ELF_SHT_NULL          0x00000000 // Section header table entry unused
#define ELF_SHT_PROGBITS      0x00000001 // Program data
#define ELF_SHT_SYMTAB        0x00000002 // Symbol table
#define ELF_SHT_STRTAB        0x00000003 // String table
#define ELF_SHT_RELA          0x00000004 // Relocation entries with addends
#define ELF_SHT_HASH          0x00000005 // Symbol hash table
#define ELF_SHT_DYNAMIC       0x00000006 // Dynamic linking information
#define ELF_SHT_NOTE          0x00000007 // Notes
#define ELF_SHT_NOBITS        0x00000008 // Program space with no data (bss)
#define ELF_SHT_REL           0x00000009 // Relocation entries, no addends
#define ELF_SHT_SHLIB         0x0000000A // Reserved
#define ELF_SHT_DYNSYM        0x0000000B // Dynamic linker symbol table
#define ELF_SHT_INIT_ARRAY    0x0000000E // Array of constructors
#define ELF_SHT_FINI_ARRAY    0x0000000F // Array of destructors
#define ELF_SHT_PREINIT_ARRAY 0x00000010 // Array of pre-constructors
#define ELF_SHT_GROUP         0x00000011 // Section group
#define ELF_SHT_SYMTAB_SHNDX  0x00000012 // Extended section indeces
#define ELF_SHT_NUM           0x00000013 // Number of defined types.
#define ELF_SHT_LOOS          0x60000000 // Start OS-specific.

// sh_flags
#define ELF_SHF_WRITE            0x00000001 // Writable
#define ELF_SHF_ALLOC            0x00000002 // Occupies memory during execution
#define ELF_SHF_EXECINSTR        0x00000004 // Executable
#define ELF_SHF_MERGE            0x00000010 // Might be merged
#define ELF_SHF_STRINGS          0x00000020 // Contains nul-terminated strings
#define ELF_SHF_INFO_LINK        0x00000040 // 'sh_info' contains SHT index
#define ELF_SHF_LINK_ORDER       0x00000080 // Preserve order after combining
#define ELF_SHF_OS_NONCONFORMING 0x00000100 // Non-standard OS specific handling required
#define ELF_SHF_GROUP            0x00000200 // Section is member of a group
#define ELF_SHF_TLS              0x00000400 // Section hold thread-local data
#define ELF_SHF_MASKOS           0x0FF00000 // OS-specific
#define ELF_SHF_MASKPROC         0xF0000000 // Processor-specific
#define ELF_SHF_ORDERED          0x04000000 // Special ordering requirement (Solaris)
#define ELF_SHF_EXCLUDE          0x08000000 // Section is excluded unless referenced or allocated (Solaris)

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