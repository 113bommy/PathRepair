s = input()
big = 0
small = 0
n = 0
big2 =0
for i in range(len(s)):
  if s[i]=='<':
    big += 1
    n += big
    small =0
    big2 = big
  else:
    small += 1
    n += small
    if small<=big2:
      n-=1
      big =0
print(n)