N,M=map(int, input().split())
a=N//2
b=a+1
if N&1:
    for i in range(M):
        print(a,b)
        a-=1
        b+=1
else:
    for i in range(M):
        print(a,b)
        a-=1
        b+=1
        if 2+N//2>b-a>=N//2: b+=1
