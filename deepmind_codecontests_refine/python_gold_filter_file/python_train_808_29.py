n=int(input())
a=list(map(int,input().split()))
b=[0]*64
for i in range(n):
    for j in range(a[i].bit_length()):
        if a[i]>>j & 1: b[j]+=1
c=0
for i in range(64):
    c+=(b[i]*(n-b[i])*2**i) % 1000000007
print(c%1000000007)
