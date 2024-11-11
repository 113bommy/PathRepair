s = input()
n = len(s)

ans = 0
cnt = 0

for i in range(n-1):
    if s[i] == "A":
        cnt += 1
    elif s[i]+s[i+1] == "BC":
        ans += cnt
    elif s[i]+s[i+1] in ("AC","BA","BB","CC"):
        cnt = 0
    
print(ans)