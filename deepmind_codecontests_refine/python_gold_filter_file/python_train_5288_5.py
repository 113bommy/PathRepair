n,k = map(int,input().split())
r,s,p = map(int,input().split())
a = list(input())

hand = {"r":p,"s":r,"p":s}
ans = 0
for i in range(n):
    if a[i-k] == a[i] and i-k >= 0:
        a[i] = "0"
    else:
        ans += hand[a[i]]
print(ans)
