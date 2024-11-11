a,b=map(int,input().split())
c=0
for i in range(1251):
    if int(i*0.08)==a and int(i*0.1)==b:
        print(i)
        exit()
print(-1)