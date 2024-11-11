md =1e9+7
t=int(input())
for _ in range(t):
    n,k=map(int,input().split())
    x=bin(k)[2:][::-1]
    np=1 
    ans=0
    for i in range(len(x)):
        if x[i]=='1':
            ans+=np 
            ans%=md 
        else:
            pass 
        np*=n 
    print(int(ans))