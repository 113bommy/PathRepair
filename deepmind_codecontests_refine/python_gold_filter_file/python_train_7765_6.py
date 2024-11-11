n=int(input())
t=sum(map(int,input().split()))
m=int(input())
for _ in range(m):
    l,r=list(map(int,input().split()))
    if t<=r:
        print(max(t,l))
        quit()
print(-1)
