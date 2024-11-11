n,k=map(int,input().split())
print(['Yes','No'][any(n%i for i in range(1,k))])