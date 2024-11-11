n = int(input())

def bfs(s):
  if int(s) >= n:
    return 0
  return ('3' in s and '5' in s and '7' in s) + bfs(s+'3') + bfs(s+'5') + bfs(s+'7')

print(bfs(''))