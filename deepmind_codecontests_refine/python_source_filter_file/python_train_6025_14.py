from collections import deque

n,l=map(int,input().split())
a=list(map(int,input().split()))

s=""

for i in range(1,n):
  if a[i-1]+a[i]>l:
    s="p"
    break

if s=="":
  print("Impossible")
  exit()
print("Possible")
  
for j in range(1,i):
  print(j)
for j in range(1,len(a)-i):
  print(len(a)-j)
  
print(i)
  
