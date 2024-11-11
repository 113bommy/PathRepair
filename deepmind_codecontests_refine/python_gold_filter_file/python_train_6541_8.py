n,C = map(int,input().split())
imos = [0]*(10**5+2)
ch = [set() for _ in range(C)]
for i in range(n):
    s,t,c = map(int,input().split())
    c -= 1
    if s in ch[c]:
        ch[c].remove(s)
        imos[s+1] +=1
    else:
        ch[c].add(s)
        imos[s] += 1
    if t in ch[c]:
        ch[c].remove(t)
        imos[t] -= 1
    else:
        ch[c].add(t)
        imos[t+1] -= 1
ans = 0
cnt = 0
for i in imos:
    cnt += i
    ans = max(ans,cnt)
print(ans)