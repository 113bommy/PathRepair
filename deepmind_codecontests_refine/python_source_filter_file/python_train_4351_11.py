A = []
for _ in range(3):
  A　+= list(map(int,input().split()))
N = int(input())
B = [int(input()) for _ in range(N)]
C = [0]*9
for i in B:
  if i in A:
    x = A.index(i)
    C[x] = 1
if C[0]*C[1]*C[2] == 1 or C[3]*C[4]*C[5]==1 or C[6]*C[7]*C[8] ==1 or C[0]*C[3]*C[6] ==1 or C[1]*C[4]*C[7]==1 or C[2]*C[5]*C[8] ==1 or C[0]*C[4]*C[8] ==1 or C[2]*C[4]*C[6] ==1:
  print("Yes")
else:
  print("No")
  