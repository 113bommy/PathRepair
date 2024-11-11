N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
dif_pos, dif_neg = 0, 0
for a, b in zip(A,B):
  if a<b:dif_neg +=(b-a)//2
  elif b<a:dif_pos +=a-b
print('Yes' if dif_neg>=dif_pos else 'No')