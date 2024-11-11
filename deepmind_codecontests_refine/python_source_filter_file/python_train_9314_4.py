n,x,y=map(int,input().split())
w=[]
for i in range(n):
 a,b=map(int,input().split())
 if (x-a)==0:
   w.append(70)
 else:
   m=float((y-b)/(x-a))
   w.append(m)
print(len(set(w)))