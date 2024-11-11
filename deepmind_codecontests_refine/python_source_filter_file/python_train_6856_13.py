n=int(input())
s=0
l=[]
for i in　range(1,n+1):
 s+=i
 l.append(i)
 if s>=n:
  for j in l:
   if j!=s-n:
    print(j)
  break