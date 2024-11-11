a,b=map(int,input().split())
for i in range(0,101):
    if int(i*0.08)==a and int(i*0.1)==b:
        print(i)
        exit()

print(-1)