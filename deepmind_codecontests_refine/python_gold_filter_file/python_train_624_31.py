a,b,c = map(int,input().split())
d=0
for x in range(a,b+1):
    if c%x==0:d+=1
print(d)