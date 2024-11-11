n = int(input())
s = list(map(int,input().split()))
ans = 0
for i in range(n):
    if s[s[i]-1] == i+1:
        ans += 1
print(ans)