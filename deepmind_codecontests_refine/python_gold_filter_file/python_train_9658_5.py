n=int(input())
a=list(map(int,input().split()))
ct=0
for i in range(n):
  if i%2==0 and a[i]%2==1:
    ct+=1
print(ct)