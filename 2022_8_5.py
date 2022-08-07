# -*- codeing = utf-8 -*-
# @Time : 2022/8/5 19:35
# Author : 马县杨
# @File : demo9.py
# @software: PyCharm
a = 10
lst = ['Hello world', 10]  # 列表存储多种不同数据
print(id(a))
print(type(lst))
print(id(lst))
print(id(lst[1]))
lst = ['Hello world', 10, 'Hello world']
print(lst.index('Hello world'))  # 优先最近
print(id(lst[0]), id(lst[2]))
print(lst.index('Hello world', 1, 3))  # 左闭右开
print(lst[2], lst[-1])  # 负数从后向前数
lst = ['a', 'b', 'c', 'd', 1, 2, 3, 4, 5, 6, 7]
print(lst[1:6])
print(lst[0:7:2]) #切片
lst1=lst[0:12:3]
print(lst1)
print(lst[1:6:])
print(lst[:6:2])
print(lst[0::2])
print(lst[::-1])# 从后向前
print(lst[12::-1])