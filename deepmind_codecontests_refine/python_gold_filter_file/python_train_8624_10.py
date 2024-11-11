n = int(input())
s = [c == 'o' for c in input()]
def next_s(s, flag):
  d = {'S' : 'W', 'W' : 'S'}
  if flag:
    return s
  else:
    return d[s]

def sim(s0):
  ans = ['.' for _ in range(n+1)]
  ans[0] = s0[0]
  ans[1] = s0[1]
  for i in range(2, n+1):
    if ans[i-1] == 'S':
      ans[i] = next_s(ans[i-2], s[i-1])
    else:
      ans[i] = next_s(ans[i-2], not s[i-1])
  res = ans[1] == ans[-2]
  if s0[0] == 'S':
    if res == s[0] and ans[-1] == ans[0]:
      return ans[:-1]
  else:
    if res != s[0] and ans[-1] == ans[0]:
      return ans[:-1]
  return False

def solve():
  for item in ["SS", "SW", "WS", "WW"]:
    ans = sim(item)
    if ans:
      return print(''.join(ans))
  return print(-1)

solve()
