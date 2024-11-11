a,b,c,k = map(int,input().split())
print(a if k <= a+b else a-(k-a-b))