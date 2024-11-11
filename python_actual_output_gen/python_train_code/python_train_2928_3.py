n, k = map(int,input().split())
s = input()
l = [0]
for i in range(n-1):
    if s[i+1] != s[i]:
        l.append(i+1)
l.append(n+1)

ans = 0
for i in range(len(l)-1):
    ind = min(i+2*k + int(s[i]=="1"), len(l) - 1)
    ans = max(ans, l[ind] - l[i])

print(ans)