n,k=map(int,input().split())
print(k if n<k else (n//k+1)*k)