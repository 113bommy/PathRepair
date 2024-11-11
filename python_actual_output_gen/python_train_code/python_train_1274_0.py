def self() :
    n=int(input())
    d=list(map(int,input().split()))
    a,b=map(int,input().split())
    j=-1
    f=d[j]
    k=0
    while a<b :
        a+=1
        
        j+=1
        f=d[j]
        k+=f
    print(k)
self()