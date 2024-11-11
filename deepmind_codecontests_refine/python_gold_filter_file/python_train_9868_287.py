n,r=map(int,input().split())
r+=0 if n>=10 else 100*(10-n)
print(r)