n, k = [int(i) for i in input().split()]
s, b, ans = input(), 0, []
for i in range(n):
    if b and s[i] == ')':
        ans.append(')')
        b -= 1
    elif s[i] == '(' and len(ans) + 2 <= k:
        ans.append('(')
        b += 1
print(*ans, sep='')