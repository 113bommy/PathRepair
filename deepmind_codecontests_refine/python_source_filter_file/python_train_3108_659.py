A,B = map(int,input().split())
D = A+B
if D > 24:
  D -= 24
print(D)