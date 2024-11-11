t=int(input())
while t:
    n,d=map(int,input().split())
    a=list(map(int,input().split()))
    if n==0:
        print('0')
        break
    for i in range(1,n):
        while a[i]>0 and d>=i:
            a[i]-=1
            a[0]+=1
            d-=i
    print(a[0])        
    t-=1