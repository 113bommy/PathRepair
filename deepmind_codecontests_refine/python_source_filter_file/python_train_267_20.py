c,v,v1,a,l = map(int,input().split())
ans = 1
c -= v
v = min(v1, v+a)
while c > l:
    c -= (v-l)
    v = min(v1, v+a)
    ans += 1
print(ans)
