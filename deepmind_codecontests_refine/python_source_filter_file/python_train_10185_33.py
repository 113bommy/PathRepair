A=int(input())
B=int(input())
C=int(input())
X=int(input())
a=0
for i in range(A):
  for j in range(B):
    if 0<=X-500*i-100*j<=50*C:
      a+=1
print(a)