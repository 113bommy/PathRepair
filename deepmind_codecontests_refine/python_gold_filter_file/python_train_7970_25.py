n,k=map(int,input().split())
time=240-k
i=1
while time>=5*i and i<=n:
    time-=i*5
    i+=1
print(i-1)