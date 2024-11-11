p,a=1,0
n=input()
for i in list(map(int,input().split())):
  if p<=i:a+=1
  p=max(i,p)
print(a)
