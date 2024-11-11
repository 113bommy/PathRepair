from math import ceil
t=int(input())

for _ in range(t):
    Li,vi,li,ri=map(int,input().split())
    start=vi*ceil(li/vi)
    print(Li//vi-(ri-start)//vi-int(start<=ri))