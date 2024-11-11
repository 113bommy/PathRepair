a,b=map(int,input().split())
for i in range(1,10100):
    if i*8//100==a and i//10==b:
        print(i)
        break
else:
    print(-1)