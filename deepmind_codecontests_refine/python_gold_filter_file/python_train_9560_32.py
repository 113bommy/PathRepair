a,b=map(int,input().split())
c=0
for i in range(a,b+1):
    i=str(i)
    if i[:2]==i[3:][::-1]:c+=1
print(c)