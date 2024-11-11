# coding: utf-8

n = int(input())

for i in range(n):
    t,x,y = map(int,input().split())
    if t<x+y or (t%2) != (x+y)%2:
        print("NO")
        exit()
        
print("YES")