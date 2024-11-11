n= int(input())
l= list(map(int, input().split()))
ans= "APPROVED"
for i in l:
  if i%2==0:
    if i%3 != 0 and i%5 !=0:
      ans= "DENIED"
print(ans)