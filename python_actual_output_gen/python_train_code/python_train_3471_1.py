n=int(input())
a=list(map(int,input().split()))
b=[]
mx=0
cnt=0
for i in a:
  mx=max(mx,i)
  if mx<=i:
    cnt+=1
print(cnt)