#ABC167B
a,b,c,d,k = map(int,input().split())
print(min(a,k)-max(k-a-b,0))