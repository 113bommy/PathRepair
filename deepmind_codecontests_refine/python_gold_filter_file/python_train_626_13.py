a,b,c=map(int,input().split())
d=0
for k in range(a,b+1):
    if c%k==0:
        d+=1
print(d)
