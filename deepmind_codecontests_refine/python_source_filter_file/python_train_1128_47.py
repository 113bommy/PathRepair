n=int(input())
a=list(map(int,input().split()))
a=list(map(lambda x:x//400,a))
cnt=0
z=[]
for i in a:
  if i>=8:
    cnt+=1
  else:
    z.append(i)
print(len(set(z)),len(set(z))+cnt)
