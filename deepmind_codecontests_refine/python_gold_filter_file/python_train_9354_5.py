h,w = map(int, input().split())
l = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
for i in range(h):
  tmp = list(map(str, input().split()))
  if tmp.count('snuke') == 1:
    a = l[tmp.index('snuke')]
    b = str(i + 1)
print(a + b)