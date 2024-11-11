# HEY STALKER
n = int(input())
l = list(map(int, input().split()))
idx = {}
for t in range(n):
    idx[l[t]] = t+1
if n < 4:
    print(1)
else:
    l.sort()
    d = {}
    for t in range(1, n):
        d[l[t]-l[t-1]] = d.get(l[t]-l[t-1], 0) + 1
    if len(d) > 3:
        print(-1)
    else:
        if len(d) == 1:
            print(idx[l[-1]])
        else:
            def check(L, dx):
                for i in range(1, len(L)):
                    if L[i] - L[i-1] != dx:
                        return False
                return True
            def solve(cx):
                k = []
                for tc in l:
                    k.append(tc)
                for j in range(1, n):
                    if k[j] - k[j-1] != cx:
                        k2 = k[:j] + k[j+1:]
                        k1 = k[:j-1] + k[j:]
                        if check(k1, cx):
                            print(idx[k[j-1]])
                            return 1
                        elif check(k2, cx):
                            print(idx[k[j]])
                            return 1
                        return 0
            for t in d:
                ans = solve(t)
                if ans == 1:
                    exit()
            print(-1)