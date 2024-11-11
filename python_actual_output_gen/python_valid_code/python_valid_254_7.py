k,r=map(int,input().split())
a=[0,r]
for i in range(1,10):
    if (k*i)%10 in a:
        print(i)
        