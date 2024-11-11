H,N=map(int,input().split())
A=map(int,input().split())
B=sum(A)
ans='YES'
if B<H:
  ans='NO'
print(ans)