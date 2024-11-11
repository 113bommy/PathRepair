n=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))

cnt=0
for a,b in zip(A,B):
  if a>b:
    cnt+=a-b
  else:
    cnt-=(b-a)//2
print('Yes' if cnt<=0 else 'No')