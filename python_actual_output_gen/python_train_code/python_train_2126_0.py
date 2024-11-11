def solve(s, k):
    if len(s) <= k:
        return [s[-1]]
    if s[0] != s[k-1]:
        return [s[k-1]]
    if s[k] != s[-1]:
        return [s[0]] + s[k:]
    return [s[0]] + s[k: k + (len(s)- 1) // k]
    
for _ in range(int(input())):
    n, k = (int(x) for x in input().split())
    s = sorted(list(input()))
    print(solve(s, k))