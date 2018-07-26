l
echo Removing all -m32 Flags from cFE Build Commands

echo editing psp compiler-options.mak
sed -i 's/-m32//g' $PWD/../psp/fsw/pc-linux/make/compiler-opts.mak
sed -i 's/-melf_i386//g' $PWD/../psp/fsw/pc-linux/make/compiler-opts.mak

echo - editing psp link-rules.mak
sed -i 's/-m32//g' $PWD/../psp/fsw/pc-linux/make/link-rules.mak

echo  - editing tools elf2cfetbl CMakeList.txt
sed -i 's/-m32//g' $PWD/../tools/elf2cfetbl/CMakeLists.txt

echo - editing tools elf2cfetbl/for_build Makefile
sed -i 's/-m32//g' $PWD/../tools/elf2cfetbl/for_build/Makefile

echo !! DONE !!
