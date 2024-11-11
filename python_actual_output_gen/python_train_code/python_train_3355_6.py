def solve(string, k):
    n = len(string)
    ans = 0
    left = 0
    cur = 0
    for i in range(n):
        cur += (string[i] == 'b')
        while cur > k:
            cur -= (string[left] == 'b')
            left += 1
        ans = max(ans, i - left + 1)
    return ans


n, k = map(int, input().split())
string = list(input())
ans = solve(string, k)
for i in range(n):
    string[i] = ('a' if string[i] == 'a' else 'b')
ans = max(ans, solve(string, k))
print(ans)