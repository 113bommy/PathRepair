n, d = map(int,input().split())
t = list(map(int, input().split()))
sumt = sum(t)
kk = d - 10*n + 10 - sumt
x = kk//5 
print(x+2*n-2 if x>0 else -1)