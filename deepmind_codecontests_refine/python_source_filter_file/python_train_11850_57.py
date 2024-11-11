n,m=map(int,input().split())
for i in range(n,m+1):
  if m%i==0:
    print(m//i)
    exit()
print(1)