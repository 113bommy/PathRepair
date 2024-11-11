n,a=map(int,input().split())
x=((n-2)*180)/n
b,c=3,x
for z in range(4,n+1):
  v=x-((z-3)*180-(z-3)*x)/2
  if abs(a-v)<x:c,b=v,z
print(1,2,b)