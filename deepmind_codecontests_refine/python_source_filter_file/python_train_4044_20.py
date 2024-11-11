l=[2,1]
n=int(input())
i=0
while i!=n:
  l.append(l[i]+l[i+1])
  i+=1
print(l[n-1])