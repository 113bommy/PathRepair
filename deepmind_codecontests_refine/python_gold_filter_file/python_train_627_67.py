a,b,c=map(int,input().split())
y=0
for d in range(a,b+1):
    if c%d==0: y+=1
print(y)
