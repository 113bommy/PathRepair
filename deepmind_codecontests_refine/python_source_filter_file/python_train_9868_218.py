n,r=map(int,input().split())
if n<10:
    r+=100*(10-r)
print(r)