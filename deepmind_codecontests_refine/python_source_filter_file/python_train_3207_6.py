s = input()
sa = s.replace('LR','L,R')
sb = sa.split(',')
ans = ''
for hoge in sb:
  poge = len(sb)
  g = hoge.find('RL')
  if poge%2 == 0:
    r = poge//2
    l = poge//2
  else:
    if g%2 == 0:
      r = poge//2
      l = r + 1
    else:
      l = poge//2
      r = l + 1
  an = '0 '*(g-1)+str(r)+' '+str(l)+' 0'*(poge-g-1)+ ' '
  ans += an
print(ans)