n, p = map(int, input().split())
s = input()
res = 0; left = 10**9; right = 0
for i in range(n // 2):
    if s[i] != s[n - i - 1]:
        if p < n // 2:
            if i < p:
                left = min(left, i)
            else:
                right = max(right, i)
        else:
            if i < n - p + 1:
                left = min(left, i)
            else:
                right = max(right, i)
        res += min(abs(ord(s[i]) - ord(s[n - i - 1])),  abs(ord(s[i]) - ord('a') + 1 + ord('z') - ord(s[n - i - 1])), abs(ord('z') - ord(s[i]) + 1 + ord(s[n - i - 1]) - ord('a')))
if p > n // 2:
    p = n - p + 1
if left == 10**9 and right == 0:
    pass
elif left == 10**9:
    res += right - p + 1
elif right == 0:
    res += p - left - 1
else:
    res += right - left + min(right + 1 - p, p - 1 - left)
print(res)
