n,k=map(int,input().split())
time=240-k
i=1
while time>=5 and i<=n+1:
    time-=i*5
    i+=1
print(i-2)