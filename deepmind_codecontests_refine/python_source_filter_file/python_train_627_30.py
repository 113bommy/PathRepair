a,b,c = map(input().split())
d=0
x=0
for x in range(a,b+1):
    if c%x==0:d+=1
print(d)