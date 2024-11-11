def solve(n, k, s):
    ans = 0
    c = {"a": 0, "b": 0}
    l = 0
    cur_len = 0
    for r in range(n):
        cur_len += 1
        c[s[r]] += 1
        while l <= r and min(c.values()) > k:
            c[s[l]] -= 1
            cur_len -= 1
            l += 1
        ans = max(ans, cur_len)
    return ans

print(solve(10, 1, "bbabbabbba"))

# n, k = map(int, input().split())
# s = input()
# print(solve(n, k ,s))
