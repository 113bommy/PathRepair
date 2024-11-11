k=int(input())
a,b=map(int,input().split())
n=1
while k*n<=b:
  n+=1
print('OK' if 100<=(n-1)*k<=120 else 'NG')