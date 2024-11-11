a, b=sorted(map(int, input().split()))
g=max(a, b)
f=min(a, b)
i=1
while(i**2<=b):
  i=i+1
h=i-1
x=b-h**2
cnt=0

if h**2+x==b and x**2+h==a and a!=1 and b!=1:
  cnt+=1
  print(cnt)
elif (a==1 and b==1):
  print("2")
else:
  print("0")