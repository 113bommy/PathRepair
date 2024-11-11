a,b,c=map(int, input().split())
k=int(input())
d=max(a,b,c)
print(a+b+c+d*(2**k)-d)
