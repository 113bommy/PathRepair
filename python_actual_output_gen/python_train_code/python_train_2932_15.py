def answer(x):
  print(x)
  exit()

N=int(input())
A=list(map(int,input().split()))
if len(set(A))>=3:
  answer('Yes')
if len(set(A))==1:
  if N//2>=A[0] or A[0]==N-1:
    answer('Yes')
  else:
    answer('No')
A.sort()
if A[0]+1<A[-1]:
  answer('No')
X=1
for i in range(N-1):
  if A[i]==A[i+1]:
    X+=1
  else:
    break
if X==N-1:
  answer('No')
if X+1<=A[-1]<=X+(N-X-1)//2:
  answer('Yes')
else:
  answer('No')