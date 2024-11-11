n,k=map(int,input().split())
z=[[int(i) for i in input().split()]for j in range(n)]
a=0
for i in range(1 , n):
    a+=((z[i-1][0]-z[i][0])**2+(z[i-1][1]-z[i][1])**2)**0.5
print(a*k//50)