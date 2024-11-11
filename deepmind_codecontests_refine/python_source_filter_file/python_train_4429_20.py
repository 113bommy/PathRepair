n, c = tuple(map(int, input().split()))
l = tuple(map(int, input().split()))
r = tuple(map(int, input().split()))
time = 0
b_l = 0
b_r = 0
for i in range(n):
   time += r[i]
   b_l += max(0, l[i] - (time * c))

time = 0
for i in range(n - 1, 0, -1):
   time += r[i]
   b_r += max(0, l[i] - (time * c))
   
if b_l > b_r:
   print('Limak')
elif b_l == b_r:
   print('Tie')
else:
   print('Radewoosh')