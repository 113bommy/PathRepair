n =int(input())
ans = n * ['o']
i, j = 0, 1
while i + j <= n:
  i, j = j, i + j
  ans[j - 1] = 'O'
print(''.join(ans))