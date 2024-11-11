from sys import stdin

def r(): return stdin.readline().strip()
def r_t(tp): return map(tp, r().strip().split())
def r_a(tp): return list(r_t(tp))

def solve(n, k , s):
    ones, i, nxt, ans = list(), 0, 0, 0
    for j in range(n):
        if s[j]=="1": ones.append(j)
    if not ones: return max(1,n//(k+1))
    ones.append(float("inf"))
    
    while i < n:
        if s[i]=="0":
            if (i+k+1)<=ones[nxt]: ans, i = ans+1, i+k+1
            else: i=ones[nxt]
        else: i, nxt = i+k+1, nxt+1
    return ans
    


def main():
    cases = int(r())
    for case in range(cases):
        n, k = r_t(int)
        s = r()
        print(solve(n, k, s))


main()