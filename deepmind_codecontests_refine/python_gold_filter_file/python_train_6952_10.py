from itertools import permutations
"""
どの順番に出てくるかをすべて（6通り）ためす
そこからa,b,cのずれ幅の組み合わせ（2000**2）をためす
判定をO(1)ですると
2000*2*6 = 2.4*10**7
x: aとbのずれ幅
y: aとcのずれ幅
"""
def main():
    ss = sorted([input() for _ in range(3)])
    n = len(max(ss, key=len))
    d = [[[None]*n for _ in range(3)] for _ in range(3)]
    ans = n*3
    for s in permutations(ss):
        for i in range(3):
            li = len(s[i])
            for j in range(i, 3):
                lj = len(s[j])
                for k in range(li):
                    ok = True
                    for ni in range(k, li):
                        nj = ni - k
                        if nj >= lj:
                            break
                        if s[i][ni] == "?" or s[j][nj] == "?":
                            continue
                        if s[i][ni] != s[j][nj]:
                            ok = False
                    d[i][j][k] = ok
        f = lambda i, j, k: True if k>=len(s[i]) else d[i][j][k]
        for x in range(n):
            for y in range(n):
                if not f(0, 1, x):
                    continue
                if not f(1, 2, y):
                    continue
                if not f(0, 2, x+y):
                    continue
                now = max([0, len(s[0]), x+len(s[1]), x+y+len(s[2])])
                ans = min(ans, now)
    print(ans)
                
if __name__ == "__main__":
    main()