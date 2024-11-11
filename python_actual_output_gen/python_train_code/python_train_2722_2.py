from sys import stdin
n=int(stdin.readline())
a=sorted(map(int,input().split()))
m=(n-1)//2
c=0
b=[]
for i in range(n):
    b.append(a[(1-i%2)*(n//2)+i//2])
for i in range(1,m):
    if b[i*2-1]<min(b[i*2-2],b[i*2]):
        c+=1
print(c)
for i in range(n):
    print(b[i], end=' ')
                    
    

