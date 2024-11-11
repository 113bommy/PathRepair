(n, k), p, c = [[*map(int, i.split())] for i in open(0)]

def solve(x, t):
    visit = [0] * n
    visit[x] = 1
    loop = [0] * n
    count = 0
    ans = c[p[x] - 1]
    l = True
    sub = 0
    while True:
        x = p[x] - 1
        if l:
            if visit[x]:
                if loop[x]:
                    ln = sum(loop)
                    if t > l:
                        sub += (t//ln -1)*count*(count>0)
                        t %= ln
                        t += ln
                    l = False
                count += c[x]
                loop[x] = 1
            visit[x] = 1
        sub += c[x]
        t -= 1
        ans = max(sub, ans)
        if t < 1:
            return ans


print(max(solve(i, k) for i in range(n)))
