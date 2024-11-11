a,b=map(int,input().split())
for i in range(1,10**5):
  if int(0.08*i)==a and int(0.10*i)==b:
    print(i)
    exit()
print(-1)