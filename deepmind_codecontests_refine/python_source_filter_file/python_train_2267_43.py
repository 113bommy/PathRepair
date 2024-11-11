X,N=map(int,input().split())
li=list(map(int,input().split()))
sa = 101
for i in range(101):
    if sa > abs(X-i) and not i in li:
        sa = abs(X-i)
        ans = i
print(ans)
