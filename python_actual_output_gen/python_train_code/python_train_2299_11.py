n=int(input())
ans="APPROVED"
for i in list(map(int,input().split())):
  if a%2==0:
    if a%3!=0 and a%5!=0:ans="DENIED"
print(ans)