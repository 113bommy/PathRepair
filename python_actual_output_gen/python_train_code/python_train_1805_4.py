n=int(input())
m=list(map(int,input().split()))
z=[]
x=1
for i in range(n-1):
    if m[i]==m[i+1]:
        z.append(x)
        x=1
        continue
    if m[i]*2<=m[i+1]:
        z.append(x)
        x=1
    else:
        x+=1
z.append(x)
print(max(z))
        
        
