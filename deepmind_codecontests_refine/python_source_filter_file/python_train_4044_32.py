A=[2,1]
n=int(input())
for i in range(n-2):
  A.append(A[i]+A[i+1])
print(A[-1])