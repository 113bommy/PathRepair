H=int(input())+1
A=[0]+list(map(int,input().split()))
def h(i):
 l=2*i;r=l+1
 if r<H &&l<H :
  if A[i]<A[l]:
   if A[l]<A[r]:A[i],A[r]=A[r],A[i];h(r)
   else:A[i],A[l]=A[l],A[i];h(l)
  elif A[i]<A[r]:A[i],A[r]=A[r],A[i];h(r)
 elif l<H and A[i]<A[l]:A[i],A[l]=A[l],A[i];h(l)
for i in range(H//2,0,-1):h(i)
print(' '+' '.join(map(str,A[1:])))
