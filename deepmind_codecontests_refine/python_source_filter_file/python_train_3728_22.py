# coding: utf-8
# Your code here!

x,y,z,k = map(int,input().split())

A = sorted(map(int,input().split()))[::-1]
B = sorted(map(int,input().split()))[::-1]
C = sorted(map(int,input().split()))[::-1]

AB = sorted([a+b for a in A for b in B])[::-1]

ans = sorted([ab + c for ab in AB for c in C])[::-1]

for i in ans[:k]:
    print(i)

