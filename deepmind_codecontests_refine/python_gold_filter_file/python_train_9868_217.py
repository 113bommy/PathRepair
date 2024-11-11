n,r=list(map(int,input().split()))
if n<10:
    r+=100*(10-n)
print(r)