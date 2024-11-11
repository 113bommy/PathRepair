n = input()
l = map(int,input().split())
s = set()
ans = 1
for i in l:
    s^={i}
    ans = max(ans,len(s))
print(ans)
