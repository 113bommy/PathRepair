A=input()
B=input()
C=0
for i in range(N):
  if A[i] != B[i]:
    C+=1
print(C)