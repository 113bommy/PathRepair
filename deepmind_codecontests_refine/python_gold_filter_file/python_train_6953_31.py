n=int(input())
ans='No'
for i in range(1,10):
  if n//i<10 and n%i==0:
    ans='Yes'

print(ans)
