from math import ceil
def blocks(arr):
    n=len(arr)
    s=sum(arr)
    k=max(ceil(s/(n-1)),max(arr))
    return ((n-1)*k)-s

t=int(input())
for i in range(t):
    input()
    print(blocks(list(map(int,input().strip().split()))))