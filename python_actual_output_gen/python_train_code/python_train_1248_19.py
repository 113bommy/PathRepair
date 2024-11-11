a=int(input())
b=list(map(int,input().split()))
s=sum(b);k=0
for i in range(a):
    k+=b[i]
    if s//2<=k:exit(print(i+1))