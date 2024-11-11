n,m=map(int,input().split())
s=input()
ACsuu=[0 for i in range(n)]
for i in range(1,n):
  ACsuu[i]=ACsuu[i-1]+(1 if s[i-1:i+1]=="AC" else 0)
for i in range(m):
  a,b=map(int,input().split())
  print(ACsuu[b-1]-ACsuu[a-1])
