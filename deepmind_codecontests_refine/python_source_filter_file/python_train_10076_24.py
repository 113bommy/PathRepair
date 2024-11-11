N=int(input())
P=list(map(int,input().split()))
b=[]
a=0
for i in range(N):
  if P[i]<=b:
    b=P[i]
    a+=1
print(a)
    
