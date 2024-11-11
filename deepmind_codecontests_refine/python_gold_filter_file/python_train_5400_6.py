# -*- coding:shift-jis -*-
x=input()
def f(n):
 if n==0:return 1
 return f(n-1)*n
print(f(int(x)))