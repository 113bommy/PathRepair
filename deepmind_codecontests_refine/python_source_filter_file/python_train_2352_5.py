n,m,k=map(int,input().split())
a=[int(x) for x in input().split()]
m-=1
for i in range(1,len(a)):
  x=m-i
  if 0<=x<len(a) and 0<a[x]<k:
    print(10*i)
    break
  x=m+i
  if 0<=x<len(a) and 0<a[x]<k:
    print(10*i)
    break
