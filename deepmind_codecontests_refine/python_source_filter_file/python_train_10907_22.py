x,k,d=map(int,input().split())
print(max(abs(x)-k*d,(x%d,-x%d)[k-x//d&1]))