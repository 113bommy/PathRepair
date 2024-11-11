H,N=map(int,input().split())
A=map(int,input().split())
B=sum(A)
ans='Yes'
if B<H:
  ans='No'
print(ans)

