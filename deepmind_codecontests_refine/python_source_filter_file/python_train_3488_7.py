k,a,b=map(int,input().split())
print(b//k-a//k-min(0,a%k)+1)