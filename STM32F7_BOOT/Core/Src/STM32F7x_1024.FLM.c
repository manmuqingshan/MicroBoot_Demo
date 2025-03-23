#include "flash_algo.h"
#define OPS_OFFSET ((uint32_t)&STM32F7x_1024_prog_blob)
static const uint32_t STM32F7x_1024_prog_blob[] = 
{
    0XE00ABE00,0X062D780D,0X24084068,0XD3000040,0X1E644058,0X1C49D1FA,0X2A001E52,0X4770D1F2,
    0X8F4FF3BF,0X02C04770,0X28400DC0,0X0980D302,0X47701D00,0XD801281F,0X477008C0,0X47702004,
    0X490D480C,0X490D6041,0X68016041,0X400A220F,0X68C16002,0X430A22F0,0X694060C2,0XD4060680,
    0X49084807,0X21066001,0X49076041,0X20006081,0X46C04770,0X40023C00,0X45670123,0XCDEF89AB,
    0X40003000,0X00005555,0X00000FFF,0X07C02001,0X680A4902,0X600A4302,0X47702000,0X40023C10,
    0X4813B570,0X21046802,0X6002430A,0X04122201,0X43136803,0X1F036003,0X03E4681C,0X6802D404,
    0X6002438A,0XBD702000,0X4D0B4C0A,0X681E602C,0XD0F44216,0X681E602C,0XD0F04216,0X681E602C,
    0XD0EC4216,0X681E602C,0XD1EF4216,0X46C0E7E7,0X40023C10,0X0000AAAA,0X40003000,0X02C0B5F0,
    0X28400DC0,0X0980D302,0XE0041D00,0XD801281F,0XE00008C0,0X491A2004,0X22F0680B,0X600B4313,
    0X604B2302,0X684C00C0,0X604C4304,0X04042001,0X4325684D,0XF3BF604D,0X680D8F4F,0XD40A03ED,
    0X439C684C,0X680B604C,0X0F1B061B,0X680BD016,0X600B4313,0X4D0BBDF0,0X60354E0B,0X4227680F,
    0X6035D0EE,0X4227680F,0X6035D0EA,0X4227680F,0X6035D0E6,0X4227680F,0XE7E1D1EF,0XBDF02000,
    0X40023C0C,0X0000AAAA,0X40003000,0XB085B5F0,0X681C4B25,0X432C25F0,0X2600601C,0X1CCC605E,
    0X438C2103,0X9404D03D,0X95019600,0X04372601,0X68594D1F,0X43214C1F,0X60594C1C,0X46019002,
    0X4001481D,0X06F64630,0X68129203,0XF3BF518A,0X68198F4F,0XD00D4239,0X6819602C,0XD0094239,
    0X6819602C,0XD0054239,0X6819602C,0XD0014239,0XE7EE602C,0X46066859,0X60594381,0X06096819,
    0XD10A0F09,0X1F099904,0X1D129A03,0X1D009802,0X29009104,0X9E00D1CD,0X6818E003,0X43089901,
    0X46306018,0XBDF0B005,0X40023C0C,0X0000AAAA,0X40003000,0X00000201,0X001FFFFF,0X00000000,
};

static const uint32_t STM32F7x_1024_flash_dev[] = 
{
    0X54530101,0X4632334D,0X31207837,0X4620424D,0X6873616C,0X00000000,0X00000000,0X00000000,
    0X00000000,0X00000000,0X00000000,0X00000000,0X00000000,0X00000000,0X00000000,0X00000000,
    0X00000000,0X00000000,0X00000000,0X00000000,0X00000000,0X00000000,0X00000000,0X00000000,
    0X00000000,0X00000000,0X00000000,0X00000000,0X00000000,0X00000000,0X00000000,0X00000000,
    0X00010000,0X08000000,0X00100000,0X00000400,0X00000000,0X000000FF,0X000003E8,0X00001770,
    0X00008000,0X00000000,0X00020000,0X00020000,0X00040000,0X00040000,0XFFFFFFFF,0XFFFFFFFF,
};

const flash_algo_t onchip_flash_device =
{
    .tFlashops.Init = (void*)(OPS_OFFSET + 0X41),  // Init
    .tFlashops.UnInit = (void*)(OPS_OFFSET + 0X8D),  // UnInit
    .tFlashops.EraseChip = (void*)(OPS_OFFSET + 0XA1),  // EraseChip
    .tFlashops.EraseSector = (void*)(OPS_OFFSET + 0XFD),  // EraseSector
    .tFlashops.Program = (void*)(OPS_OFFSET + 0X18D),  // ProgramPage
    .ptFlashDev = (flash_dev_t const *)STM32F7x_1024_flash_dev // 
};
