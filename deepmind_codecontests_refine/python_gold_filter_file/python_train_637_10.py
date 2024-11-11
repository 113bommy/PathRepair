n,m = map(int,input().split())
chs = list(map(int,input().split()))
key = list(map(int,input().split()))
eve = 0
for i in range(n):
    if chs[i]%2==0:
        eve+=1
for i in range(m):
    if key[i]%2==0:
        eve+=1
print(min(eve,n+m-eve,m,n))
