n=int(input())
A=[int(i) for i in input().split()]
B=[int(i) for i in input().split()]
ct1,ct2,ct3=0,0,0
for i in range(n):
  ct1+=(B[i]-A[i])
  ct2+=max(A[i]-B[i],0)
  if B[i]>A[i]:
    ct3+=(B[i]-A[i]-1)//2+1
print("Yes" if ct2+ct3<=ct1 else "No")