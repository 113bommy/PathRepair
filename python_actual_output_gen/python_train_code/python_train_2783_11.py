n = int(input())
memo = [{} for i in range(n+1)]
m = 10**9+7

def ppp(l):
    for i in range(4):
        t = list(l)
        if i >= 1:
            t[i-1],t[i] = t[i],t[i-1]
        if "".join(t).count("AGC") >= 1:
            return False
        return True
def dfs(c,l):
    if l in memo[c]:
        return memo[c][l]
    if c == n:
        return 1
    ret = 0
    for b in "AGCT":
        if ppp(l+b):
            ret = (ret + dfs(c + 1,l[1:] + b)) % m
    memo[c][l] = ret
    return ret
print(dfs(0,"TTT"))