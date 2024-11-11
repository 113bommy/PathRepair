A,B,C,D,E,F = map(int,input().split())
M = []
S = []

for a in range(1+F//100):
    for b in range(1+F//100):
        if 100*(a*A+b*B)<=F:
            M.append(100*(a*A+b*B))
for c in range(F//C):
    for d in range(F//D):
        if c*C+d*D<=F:
            S.append(c*C+d*D)
M = set(M)
S = set(S)

t = 0
ans1 = 0
ans2 = 0
for m in M:
    for s in S:
        if m==s==0:
            pass
        elif s<=E*m//100 and m+s<=F and t<(s*100)/(m+s):
            t = (s*100)/(m+s)
            ans1 = m+s
            ans2 = s

print(ans1, ans2)