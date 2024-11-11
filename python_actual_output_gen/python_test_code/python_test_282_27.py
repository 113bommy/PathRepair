n, x = map(int, input().split())
def get_len(lv):
  m = 1
  for i in range(lv):
    m = m * 2 + 5
  return m  
def count_p(lv, p):
  if p == 0:return 0
  elif lv == 0:return 1
  m = get_len(lv)
  if p > (m-1)/2:
    return (m-1)/2 + 1 - count_p(lv, m-p)
  else:
    return count_p(lv-1,p-1)
print(int(count_p(n, x)))