a,b=map(int,input().split())
for i in range(10*b,15*b):
  if int(i*0.08)==a and int(i*0.1)==b:
    print(i)
    exit()
print(-1)