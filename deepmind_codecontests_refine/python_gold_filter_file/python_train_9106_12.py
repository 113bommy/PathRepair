s, k = input(), int(input())
m = len(s) // k if not len(s) % k else 9999999
b = all([j == j[::-1] for j in [s[i:i+m] for i in range(0, len(s), m)]])
print('NO' if not b or len(s) % k else 'YES')