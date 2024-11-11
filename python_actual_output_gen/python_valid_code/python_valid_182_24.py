n,k=map(int, input().split())
l=list(map(int, input().split()))
add=0;total=0
l.append(0)
for i in range(n):
  l[i]+=add
  total+=add
  add=0
  x=l[i]+l[i+1]
  if x<k: 
    add=k-x
print(total)
print(l[:n])