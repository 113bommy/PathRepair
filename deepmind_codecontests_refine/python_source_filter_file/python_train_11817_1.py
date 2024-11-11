n=int(input())
a=[[i+1]+list(map(int,input().split())) for i in range(n)]
ans=[]
def go():
  pp=0
  global a
  for j in range(1,len(a)):
    a[j][3]-=pp
    if a[j][3]<0: pp+=a[j][2]
  a=[a[i] for i in range(len(a)) if a[i][3]>=0]
  return len(a)

while go():
  nom,v,d,p=a.pop(0)
  ans+=[str(nom)]
  j=0
  while v>0 and j<len(a): a[j][3]-=v; v-=1; j+=1
print(len(ans))
print(' '.join(ans))