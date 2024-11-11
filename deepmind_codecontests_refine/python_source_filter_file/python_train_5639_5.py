a=int(input())
maxs=0
for i in range(a):
    b,c=map(int,input().split())
    d=c-b+maxs
    maxs=max(maxs,d)
print(maxs)
