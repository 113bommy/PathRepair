n = int(input())
c = list(map(int, input().split()))

s1 = ''
s2 = ''
INF = 1e16
c1 = 0
c2 = 0

for i in range(n):
    s = input()
    sr = s[::-1]
    c11 = c1 if s1 < s else INF
    c21 = c2 if s2 < s else INF
    c12 = c1+c[i] if s1 < sr else INF
    c22 = c2+c[i] if s2 < sr else INF
    s1 = s
    s2 = sr
    c1 = min(c11, c21)
    c2 = min(c12, c22)
    
ans = min(c1, c2)
if ans >= INF:
    print(-1)
else:
    print(ans)
