a,b,c=map(int,input().split())
flag="No"
for i in range(1,100):
  if a*i%b==c:
    flag="Yes"
    break
print(flag)