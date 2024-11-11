l,r=map(int,input().split())
a=[]
def addLucky(x):
  if x>r:
    return
  a.append(x)
  addLucky(x*10+4)
  addLucky(x*10+7)
addLucky(0)
a.sort()
def result(n):
  res=0
  for i in range(0,len(a)):
    res+=a[i]*(min(a[i],n)-min(a[i-1],n))
  return res
print(result(r)-result(l-1))