n=int(input())
t=sum(map(int,input().split()))
m=int(input())
for _ in range(m):
    l,r=list(map(int,input().split()))
    if t<=r:
        print(t)
        quit()
print(-1)
