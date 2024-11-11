n,f=map(int,input().split())
k=[]
b=0
ans=0
m=False
for i in range(n):
     k.append(input())
     b+=k[i].count("B")
b=(b+1)//2
for i in range(n):
     for j in range(f):
          if k[i][j]=="B":
               ans+=1
          if ans==b:
               print(i+1,j+1)
               m=True
               break
     if m:
          break
