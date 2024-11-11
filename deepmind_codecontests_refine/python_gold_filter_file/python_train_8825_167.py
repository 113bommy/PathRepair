a,b=map(int,input().split())
for i in range(10**6):
    if i*8//100==a and i//10==b:
        print(i)
        exit()
print(-1)