n,k=list(map(int,input().split()))
a=pow((9+8*(n+k)),0.5)-3
a//=2
print(n-a)