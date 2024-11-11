n, a, b = map(int,input().split())
s = list(map(int,input().split()))
k = -1
p = 0
for i in range(n//2):
    if s[i] != s[k]:
        if s[i] != 2 and s[k] != 2:
            print(-1)
            exit()
        elif s[i] == 0 or s[k] == 0:
            p += a
        else:
            p += b
    if s[i]==s[k]==2:
        p += min(a,b)*2
    k-=1
if n%2 == 1:
    if s[n//2] == 2:
        p += min(a,b)
print(p)