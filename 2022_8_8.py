# -*- codeing = utf-8 -*-
# @Time : 2022/8/8 18:47
# Author : 马县杨
# @File : show_py_file.py
# @software: PyCharm
import os
path=os.getcwd()
lst=os.listdir(path)
for filename in lst:
    if filename.endswith('.py'):
        print(filename)
lst_file=os.walk(path)#遍历当前路径下的所有子路径
for dirpath,dirname,filename in lst_file:
    # print(dirpath)
    # print(dirname)
    # print(filename)
    for dir in dirname:
        print(os.path.join(dirpath,dir))
    print('-----------------------------------')
    for file in filename:
        print(os.path.join(dirpath,file))