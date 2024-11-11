n=int(input())
c=input().split();d=c[:]
for i in range(n-1):
 for j in range(0,n-i-1):
  if c[j][1]>c[j+1][1]:c[j],c[j+1]=c[j+1],c[j]
 m=i
 for j in range(i,n):
  if d[m][1]>d[j][1]:m=j
 d[i],d[m]=d[m],d[i]
print(*c);print("Stable")
print(*d)
print(['Not s','S'][b==s]+'table')
