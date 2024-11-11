def check(s, it):
    pos = 0
    cur = len(it)
    for i in range(len(s)):
        if pos == cur: break
        if s[i] == it[pos]:
            pos += 1
        
    return pos == cur
n = int(input())
s = str(n)
a = []
ans = 10**20
for i in range(1, n):
    if i * i > n:break
    else:
        it = str(i * i)
        if check(s, it):
            ans = min(ans, len(s) - len(it))
print(-1) if ans == 10**20 else print(ans)

