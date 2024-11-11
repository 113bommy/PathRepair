a,b=map(int,input().split())
for i in range(1,101):
    if i*108//100==a and i*11//10==b:
        print(i)
        exit()
print(-1)