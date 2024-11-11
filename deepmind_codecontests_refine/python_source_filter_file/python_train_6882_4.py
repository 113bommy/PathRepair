N = int(input())

s = str(N)

K = str(int(s[0]) - 1) + ("9" * (len(s) - 1))

b = str(N - int(K))

ans = 0
for s in K:
    ans += int(s)
for s in b:
    ans += int(b) 
print(ans)