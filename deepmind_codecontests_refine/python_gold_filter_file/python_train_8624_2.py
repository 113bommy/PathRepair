N = int(input())
S = input()

ans = [''] * N

def other(s):
  if s == 'S':
    return 'W'
  else:
    return 'S'

def calc(S):
  global ans
  for i, s in enumerate(S):
    if s == 'o':
      if ans[i] == 'S':
        ans[(i+1)%N] = ans[i-1]
      else:
        ans[(i+1)%N] = other(ans[i-1])
    else:
      if ans[i] == 'S':
        ans[(i+1)%N] = other(ans[i-1])
      else:
        ans[(i+1)%N] = ans[i-1]

ans[-1] = 'S'
ans[0] = 'S'
calc(S)
if (ans[0], ans[-1]) == ('S', 'S'):
  print(''.join(ans))
  quit()

ans[-1] = 'S'
ans[0] = 'W'
calc(S)
if (ans[0], ans[-1]) == ('W', 'S'):
  print(''.join(ans))
  quit()

ans[-1] = 'W'
ans[0] = 'S'
calc(S)
if (ans[0], ans[-1]) == ('S', 'W'):
  print(''.join(ans))
  quit()

ans[-1] = 'W'
ans[0] = 'W'
calc(S)
if (ans[0], ans[-1]) == ('W', 'W'):
  print(''.join(ans))
  quit()

print(-1)