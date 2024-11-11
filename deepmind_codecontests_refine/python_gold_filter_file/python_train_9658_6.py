n=int(input())
a=list(map(int,input().split()))
c=0
for i in range(0,len(a),2):
  if a[i]%2==1:
    c+=1
print(c)
