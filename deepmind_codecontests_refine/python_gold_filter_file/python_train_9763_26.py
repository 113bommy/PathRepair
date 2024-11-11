a,b,c,k = map(int,input().split())
print(min(a,k) if k <= a+b else a-(k-a-b))