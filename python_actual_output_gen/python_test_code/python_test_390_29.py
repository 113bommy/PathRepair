ans=0
for i in range(int(input())):
  if i%3!=0 and i%5!=0:
    ans+=i
print(ans)