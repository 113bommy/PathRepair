a,b,money=list(map(int,input().split()))
A=[0]+list(map(int,input().split()))
B=[0]+list(map(int,input().split()))
for i in range(1,a+1):
  A[i]+=A[i-1]
for j in range(1,b+1):
  B[j]+=B[j-1]
b_cnt=b
for a_cnt in range(a+1):
  if A[a_cnt]>money:
    continue
  while A[a_cnt]+B[b_cnt]>money:
    b_cnt-=1
  ans=max(0,a_cnt+b_cnt)
print(ans)