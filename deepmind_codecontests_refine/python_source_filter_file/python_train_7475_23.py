n,q=map(int,input().split())
s=input()
t=[0]*n
for i in range(n):
  t[i+1]=t[i]+(1 if s[i:i+2]=='AC' else 0)
for j in range(q):
  l,r=map(int,input().split())
  print(t[r-1]-t[l-1])
  
    

    
