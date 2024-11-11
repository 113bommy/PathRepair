T=int(input())
list=[]
c=-1
d=-1
for i in range(T):
  n=int(input())
  k="Yes"
  for j in range(n):
    a,b=map(int,input().split())
    if a>=b and c<=a and d<=b and (a-c)<=(b-d):
        g=0
    else:
        k="No"
    c=a
    d=b
  c=-1
  d=-1
  list.append(k)
for i in range(len(list)):
  print(list[i])