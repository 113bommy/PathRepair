t=int(input())
for _ in range(t):
  n,k,d=map(int,input().split())
  l=list(map(int,input().split()))
  s=l[:d]
  mini=len(s)
  i=0
  j=d
  while(j<n):
    s.pop(0)
    s.append(l[j])
    if len(set(s))<mini:
      mini=len(set(s))
    if mini==1:
      break
    j=j+1
  print(mini)
    