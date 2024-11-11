a=input()
ans=999

for i in range(len(a)-2):
  ans=min(ans,abs(753-int(a[i:i+2])))
  
print(ans)