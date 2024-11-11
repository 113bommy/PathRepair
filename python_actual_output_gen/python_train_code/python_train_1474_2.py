a,s,d=map(int,input().split())
l=[]
for i in range(1,min(a,s)+1):
  if a%i==0 and s%i==0:
    l.append(i)
print(l[-2])