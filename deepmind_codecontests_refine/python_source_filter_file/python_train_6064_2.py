n=int(input())
a=list(map(int,input().split()))
if a[-1]==1:
    a[-1]=2
else:
    a=[1]+a[:n-1]
print(*a)