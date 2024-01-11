#!/bin/bash

# 解压并改名
unzip 2017-10-01-juliet-test-suite-for-c-cplusplus-v1-3.zip
mv C juliet

cd juliet/

# 删掉不相关的缺陷数据集
cd testcases/
rm -r $(ls | grep -v '476\|415\|772\|1091\|401\|775')
cd ..

# 不要生成 __pycache__
export PYTHONDONTWRITEBYTECODE=1
# 更新 testcasesupport/main_linux.cpp，只考虑剩下的函数
python update_main_cpp_and_testcases_h.py

# 替换掉 Makefile 里 hardcode 的 CC 和 CPP 变量
find . -type f -name 'Makefile' -exec sed -i 's/^CC=/CC?=/' {} +
find . -type f -name 'Makefile' -exec sed -i 's/^CPP=/CPP?=/' {} +
# 把 CPP 替换成 CXX
find . -type f -name 'Makefile' -exec sed -i 's/\bCPP\b/CXX/' {} +
# 查看 Makefile 里有没有 CPP 变量，用于 debug
# find . -type f -name 'Makefile' -exec grep '\bCPP\b' {} + | grep CPP

# 最后编译就行了
# make
