n=int(input())
c=[]
for i in range(n):
   l=list(map(int,input().split()))
   c.append(((24-l[0])*60)-l[1])
for k in c:
    print(k)