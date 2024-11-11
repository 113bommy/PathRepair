n = input()
k = len(n)
ans = int(n[0]) + 9 * (k - 1) - 1
if n[1:] == '9' * (k - 1):
    ans -= 1
print(ans)
