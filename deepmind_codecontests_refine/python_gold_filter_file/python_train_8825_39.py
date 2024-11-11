a,b=map(int,input().split())
for i in range(3000):
    if int(i*0.08)==a and int(i*0.10)==b:
        print(i)
        exit()
print("-1")