a,b,k=map(int,input().split())
a,b = max(0,a-k) , b-max(k-a,0)
print(a,b)