n=int(input())
for i in range(0,n):
  a,b=map(int,input().split())
  if(a%b==0 and a!=b):
    print(b-a)
  elif(a%b!=0):
    print(b-(a%b))
  else:
    print(0)