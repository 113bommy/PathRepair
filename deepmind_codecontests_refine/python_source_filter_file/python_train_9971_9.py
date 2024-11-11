N = int(input())
AB = [list(map(int,input().split())) for _ in range(N)]

A = [i[0] for i in AB]
B = [i[1] for i in AB]
from statistics import median

a_med = median(A)
b_med = median(B)

if N%2==1:
  print(b_med - a_med + 1)
  
else:
  print((b_med - a_med) * 2 + 1)