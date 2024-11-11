n=int(input())
l=[n]
i=1
while(True):
  i+=1
  if n%2==0:
    n=n/2
  else:
    n=3*n+1
  if n in l:
    print(i)
    break
  else:
    l+=[n]