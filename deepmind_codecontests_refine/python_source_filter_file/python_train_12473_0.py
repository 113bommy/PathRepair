n=int(input())
h=[int(i) for i in input().split()]
db=[0]*n
db[1]=abs(h[0]-h[1])
for i in range(2,n):
    db[i]=min(db[i-2]+abs(h[i-2]-h[i]),db[i-1]+abs(h[i-1]+h[i]))
print(db[n-1])