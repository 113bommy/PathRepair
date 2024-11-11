h,w = map(int,input().split())
l=[input() for i in range(h)]
p = [1,1]
cnt = 0
for i in range(h):
  cnt += l[i].count('#')
if cnt == h+w-1:
  print('Possible')
else:
  print('Impossible')