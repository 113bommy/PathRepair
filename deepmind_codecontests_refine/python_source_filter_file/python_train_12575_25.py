n=int(input())
s=input()
l=0
r=n
while r-l!=1:
  mid=(r+l)//2
  dic={}
  flag=False
  for i in range(n-mid+1):
    tmp=s[i:i+mid]
    if tmp not in dic:
      dic[tmp]=i+mid
    else:
      if dic[tmp]<=i:
        flag=True
        break
  if flag==True:
    l=mid
  else:
    r=mid
print(l,r)