n,k = map(int,input().split())
l = list(map(int,input().split()))
x = 0
ma = 0
ans = 0
ans1 = 0
while x < k:
    if l[x]*(n // l[x]) > ma:
        ma = l[x]*(n // l[0])
        ans1 = l[x]
        ans = x
    x += 1
print(ans+1,ans1)