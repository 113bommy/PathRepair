n=int(input())
a=list(map(int,input().split()))
c=0
for i in range(1,len(a)+1,2):
  if a[i]%2==1:
    c+=1
print(c)