b=int(input())

a= [[int(j) for j in input().split()] for i in range(b)] 
print(a)
sum=0
gum=0
rum=0
drum=0
d=int((b-1)/2)
for i in range(b):
    sum=sum+a[d][i]
    gum=gum+a[i][d]
    for j in range(b):
        if(i==j):
            rum=rum+a[i][j]
        if((i+j)==b-1):
            drum=drum+a[i][j]

c=int(sum+gum+rum+drum-(3*a[d][d]))

print(c)