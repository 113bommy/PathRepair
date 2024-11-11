n= int(input())
a=[]
for i in range(n):
    a.append([int(i) for i in input().split()])
s=0 

for i in range(n):
    s=s+a[i][i] + a[i][n-1-i]
k = int((n-1)/2) 
for i in range(n):
    s= s+a[k][i] + a[i][k]
s=s-3*a[k][k]
print(s)

