n = int(input())
s = list(map(int,input().split()))
ans = 0
for i in range(n-2):
    a,b,c = s[i:i+3]
    if a<b<c or c<b<a:  ans += 1
print(ans)
