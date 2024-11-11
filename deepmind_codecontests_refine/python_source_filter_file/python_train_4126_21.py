n = int(input())
d = {}
e = 10*6
for i in range(max(1, n-e), n+1):
    cnt = i + sum([int(x) for x in str(i)])
    try:
        d[cnt].append(i)
    except KeyError:
        d[cnt] = [i]
ans = len(d.setdefault(n, []))
print(ans)
if ans:
    print(*sorted(d[n]), sep='\n')

