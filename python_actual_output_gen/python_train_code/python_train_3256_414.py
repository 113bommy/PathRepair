# coding: utf-8
a,b,c,d = map(int,input().split())

print(max(a*b,b*c,c*d,b*c,b*d,c*d))

