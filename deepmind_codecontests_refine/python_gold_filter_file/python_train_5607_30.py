# coding: utf-8
# Your code here!
x,y=map(int,input().split())

if y>=x:
    print(min(y-x,abs(y+x)+1))
    
else:
    print(min(x-y+2,abs(-x-y)+1))


