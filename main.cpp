#if defined(__linux__)
  #include <features.h>
  #ifndef __USE_GNU
    #define __MUSL__
  #endif
#endif

#include <sys/stat.h>
#include <cstring>
#include <iomanip>
#include <iostream>

int main(int argc, char * argv[])
{
  struct stat s;
  std::memset(&s, 0xFF, sizeof s);
  if (stat("/bin/ls", &s))
    return 1;

  std::cout

#define HEX(V) " (" << std::hex << std::showbase << V << std::dec << ")"

#define TS(F, X) std::setw(2) << offsetof(struct timespec, X) << ":" << std::setw(1) << sizeof(timespec::X) << " " << #X << HEX(s.F.X) << std::endl

#define FLDV(X) << std::setw(3) << offsetof(struct stat, X) << ":" << std::setw(3) << sizeof(stat::X) << " " << #X << HEX(s.X) << std::endl
#define FLDT(X) << std::setw(3) << offsetof(struct stat, X) << ":" << std::setw(3) << sizeof(stat::X) << " " << #X << std::endl << "  " << TS(X, tv_sec) << "  " << TS(X, tv_nsec) << "  " << std::setw(2) << sizeof(struct timespec) << std::endl
  
#if defined(__linux__)
  #if defined(__MUSL__)
    #if defined(__arm__)
      << "linux-musl-arm:" << std::endl
      FLDV(st_dev)
      FLDV(__st_dev_padding)
      FLDV(__st_ino_truncated)
      FLDV(st_mode)
      FLDV(st_nlink)
      FLDV(st_uid)
      FLDV(st_gid)
      FLDV(st_rdev)
      FLDV(__st_rdev_padding)
      FLDV(st_size)
      FLDV(st_blksize)
      FLDV(st_blocks)
      FLDT(__st_atim32)
      FLDT(__st_mtim32)
      FLDT(__st_ctim32)
      FLDV(st_ino)
      FLDT(st_atim)
      FLDT(st_mtim)
      FLDT(st_ctim)
    #elif defined(__aarch64__)
      << "linux-musl-arm64:" << std::endl
      FLDV(st_dev)
      FLDV(st_ino)
      FLDV(st_mode)
      FLDV(st_nlink)
      FLDV(st_uid)
      FLDV(st_gid)
      FLDV(st_rdev)
      FLDV(__pad)
      FLDV(st_size)
      FLDV(st_blksize)
      FLDV(st_blocks)
      FLDT(st_atim)
      FLDT(st_mtim)
      FLDT(st_ctim)
      FLDV(__unused)
    #elif defined(__x86_64__)
      << "linux-musl-x64:" << std::endl
      FLDV(st_dev)
      FLDV(st_ino)
      FLDV(st_nlink)
      FLDV(st_mode)
      FLDV(st_uid)
      FLDV(st_gid)
      FLDV(__pad0)
      FLDV(st_rdev)
      FLDV(st_size)
      FLDV(st_blksize)
      FLDV(st_blocks)
      FLDT(st_atim)
      FLDT(st_mtim)
      FLDT(st_ctim)
      FLDV(__unused)
    #else
      #error Undefined architecture
    #endif
  #else
    #if defined(__arm__)
      << "linux-arm:" << std::endl
      FLDV(st_dev)
      FLDV(__pad1)
      FLDV(__st_ino)
      FLDV(st_mode)
      FLDV(st_nlink)
      FLDV(st_uid)
      FLDV(st_gid)
      FLDV(st_rdev)
      FLDV(__pad2)
      FLDV(st_size)
      FLDV(st_blksize)
      FLDV(st_blocks)
      FLDT(st_atim)
      FLDT(st_mtim)
      FLDT(st_ctim)
      FLDV(st_ino)
    #elif defined(__aarch64__)
      << "linux-arm64:" << std::endl
      FLDV(st_dev)
      FLDV(st_ino)
      FLDV(st_mode)
      FLDV(st_nlink)
      FLDV(st_uid)
      FLDV(st_gid)
      FLDV(st_rdev)
      FLDV(__pad1)
      FLDV(st_size)
      FLDV(st_blksize)
      FLDV(__pad2)
      FLDV(st_blocks)
      FLDT(st_atim)
      FLDT(st_mtim)
      FLDT(st_ctim)
      FLDV(__glibc_reserved)
    #elif defined(__x86_64__)
      << "linux-x64:" << std::endl
      FLDV(st_dev)
      FLDV(st_ino)
      FLDV(st_nlink)
      FLDV(st_mode)
      FLDV(st_uid)
      FLDV(st_gid)
      FLDV(__pad0)
      FLDV(st_rdev)
      FLDV(st_size)
      FLDV(st_blksize)
      FLDV(st_blocks)
      FLDT(st_atim)
      FLDT(st_mtim)
      FLDT(st_ctim)
      FLDV(__glibc_reserved)
    #else
      #error Undefined architecture
    #endif
  #endif
#elif defined(__APPLE__)
  #if defined(__aarch64__)
    << "macos-arm64:" << std::endl
    FLDV(st_dev)
    FLDV(st_mode)
    FLDV(st_nlink)
    FLDV(st_ino)
    FLDV(st_uid)
    FLDV(st_gid)
    FLDV(st_rdev)
    FLDT(st_atimespec)
    FLDT(st_mtimespec)
    FLDT(st_ctimespec)
    FLDT(st_birthtimespec)
    FLDV(st_size)
    FLDV(st_blocks)
    FLDV(st_blksize)
    FLDV(st_flags)
    FLDV(st_gen)
    FLDV(st_lspare)
    FLDV(st_qspare)
  #elif defined(__x86_64__)
    << "macos-x64:" << std::endl
    FLDV(st_dev)
    FLDV(st_ino)
    FLDV(st_nlink)
    FLDV(st_mode)
    FLDV(st_uid)
    FLDV(st_gid)
  #else
    #error Undefined architecture
  #endif
#else
  #error Unknown OS
#endif
    << sizeof(struct stat) << std::endl;
}
