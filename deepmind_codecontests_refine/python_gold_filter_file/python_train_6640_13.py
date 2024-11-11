n=int(input())
ans="APPROVED"
for i in list(map(int,input().split())):
  if i%2==0:
    if i%3!=0 and i%5!=0:ans="DENIED"
print(ans)
