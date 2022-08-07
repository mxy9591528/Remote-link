# -*- codeing = utf-8 -*-
# @Time : 2022/8/7 20:17
# Author : 马县杨
# @File : demo5.py
# @software: PyCharm
class Student:
    def __init__(self,name,age):
        self.name=name
        self.age=age
    def __str__(self):#object类重写
        return '我的名字是{0}，今年{1}岁'.format(self.name,self.age)
stu=Student('张三',18)
print(dir(stu))
print(stu)
#多态
class Animals:
    def eat(self):
        print('动物会进食')
class Cat(Animals):
    def eat(self):
        print('猫吃鱼...')
class Dog(Animals):
    def eat(self):
        print('狗吃骨头...')
class Person(Animals):
    def eat(self):
        print('人啥都吃...')
def fun(obj):#使用父类掉用子类
    obj.eat()
fun(Cat())
fun(Dog())
fun(Animals())
fun(Person())