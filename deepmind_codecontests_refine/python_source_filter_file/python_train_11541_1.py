a,b,c=map(int,input().split())
for i in range(1,101):
  if a*1%b == c:
    print("YES")
    exit()
print("NO")
