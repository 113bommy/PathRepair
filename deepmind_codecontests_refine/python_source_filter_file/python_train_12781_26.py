a,b,c=map(int,input().split())
k=int(input())
cnt=0
while not a<b:
  cnt+=1
  b*=2  
while not b<c:
  cnt+=1
  c*=2  
print('yes' if k>=cnt else 'no')