s=list(map(int,input().split()))
z=[s[2]-2,s[2]-1,s[2]]
while s[1]<z[1] or s[0]<z[0]:
    z[0]=z[0]-1
    z[1]=z[1]-1
    z[2]=z[2]-1
print(sum(z))
