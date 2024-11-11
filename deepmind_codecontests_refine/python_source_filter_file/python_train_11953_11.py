n=int(input());aa=[input()for i in range(3)];ans=0
for i in range(n):
  a,b,c=aa[0][i],aa[1][i],aa[2][i]
  if not a==b==c:
    if a!=b!=c:ans+=2
    else:ans+=1
print(ans)