a,b,c=map(int,input().split())
k=int(input())
M=max(a,b,c)
print(a+b+c-M+M*(2**k))