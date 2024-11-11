t= int(input())
for i in range(t):
    n,k= map(int, input().split())
    cn=0
    while(1):
        cn+= n%k; n-= n%k
        if n==0:
            break
        n= n//k; cn+=1
        if n==0:
            break
    print(int(cn))