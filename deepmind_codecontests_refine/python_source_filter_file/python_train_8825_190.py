a,b=map(int,input().split())
for i in range(1,10**8):
  if int(0.08*i)==a and int(0.1*i)==b:
    print(i)
    exit()
print(-1)