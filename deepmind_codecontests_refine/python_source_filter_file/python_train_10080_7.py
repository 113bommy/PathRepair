s=input()
n=len(s)
k=int(input())
l=[]
for i in range(n):
  for j in range(i,n):
    a=s[i:j+1]
    l.append(a)
l=set(l)
l=list(l)
l.sort()
print(l[k-1])