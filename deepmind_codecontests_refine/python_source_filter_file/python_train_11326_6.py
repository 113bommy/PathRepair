h, w, a, b = map(int, input().split())
if a > h / 2:
  if b > w / 2:
    print('No')
    
for i in range(h):
  if i < b:
    print('0'*a + '1'*(h-a))
  else:
    print('1'*a + '0'*(h-a))