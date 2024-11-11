n = int(input())

s = []
for i in range(n):
    s.append(input())

res = 10 ** 9

m = len(s[0])
t = s[0]

for shift in range(m):
    tmp = shift
    for i in range(1, n):
        st = s[i]
        f = 0
        for shift1 in range(m):
            if st == t:
                f = 1
                break
            tmp += 1
            st = st[1:] + st[0]
        
        if not f:
            tmp += 10 ** 9
            break

    res = min(res, tmp)
    t = t[1:] + t[0]

print(-1 if res == 10 ** 9 else -1)
