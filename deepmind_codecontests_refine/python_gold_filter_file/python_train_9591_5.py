n,k=map(int,input().split())
a=list(map(int,input().split()))
print(max([abs(sum(a)-sum(a[i::k])) for i in range(k)]))

    
