# cook your dish here
n=int(input())
while n :
    n-=1
    m,k=list(map(int ,input().split()))
    N="NO"
    y="YES"
    if k>m:print(N)
    elif k%2 and m%2 :print(y)    
    elif not(k%2 or m%2):print(y)
    else:print(N)

