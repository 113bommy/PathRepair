
def partition(a,b,c,p,r):
  x = a[r]
  i = p - 1
  
  for j in range(p,r):
    if x >= a[j]:
      i += 1
      a[i],a[j] = a[j],a[i]
      b[i],b[j] = b[j],b[i]
      c[i],c[j] = c[j],c[i]
      
  a[i+1],a[r] = a[r],a[i+1]
  b[i+1],b[r] = b[r],b[i+1]  
  c[i+1],c[r] = c[r],c[i+1]
  return i+1
  
def quickSort(a,b,c,p,r):
  if p < r:
    q = partition(a,b,c,p,r-1)
    quickSort(a,b,c,p,q-1)
    quickSort(a,b,c,q+1,r)
  
def checkStable(a,b):
  for i in range(1,len(a)):
    if a[i-1] == a[i]:
      if b[i-1] > b[i]:
        return "Not stable"
  return "Stable"
  
n = int(input())
mark = [""]*n
num = [0]*n
count = [i for i in range(n)]
for i in range(n):
  mark[i],num[i] = input().split()
num = list(map(int,num))

quickSort(num,mark,count,0,n)
print(checkStable(num,count))
for i in range(n):
  print(mark[i],num[i])