n=int(input())
red=[list(map(int,input().split())) for _ in range(n)]
blue=[list(map(int,input().split())) for _ in range(n)]
red.sort()
blue.sort()
 
p=0
for bb in blue:
  lis=[-1,-1]
  for rr in red:
    if rr[0]<bb[0] and rr[1]<bb[1] and lis[1]<rr[1]:
      lis=rr
  if lis!=[-1,-1]:
    red.remove(lis)
    p+=1
print(p)