import sys
n=int(input())
a=[int(x) for x in input().split()]
m=int(input())
su=sum(a)
for _ in  range(m):
    x,y=map(int,input().split())
    if y>=su:
        print(max(su,y))
        sys.exit()
print(-1)

    
