h,w,a,b = map(int, input().strip().split(' '))

for i in range(w):
  print('1'*a+'0'*(w-a) if b < w else '0'*a+'1'*(w-a))
