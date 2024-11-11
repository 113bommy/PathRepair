n,k=map(int,input().split())
print([(k-(n+1)//2)*2,2*k-1][k>(n+1)//2])