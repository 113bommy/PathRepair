# -*- coding: utf-8 -*-

n = int(input())
a = list(map(int,input().split()))

for i in range(n):
    for j in range(i+1,n):
        if a[i]+a[j] in a:
            print(a.index(a[i]+a[j]),i,j); quit()

print(-1)
