n = int(input())

a= list(input().split())
total = 0


for i in range (0,n):

    for j in range (2*len(a[i])-1,-1,-1):

        total +=  int(a[i][j//2])*n*(10**(2*len(a[0])-1-j))
       
print(total%998244353)
