n=int(input())
x=list(map(int,input().split()))
y=[x[0]]
i=1
while i<n:
    y+=[x[i]-x[i-1]]
    i+=1
i=1
z=[]
while i<=1000 and i<=n:
    if y==y[:i]*(n//i)+y[:(n%i)]:
        z+=[i]
    i+=1
print (len(z))
for i in z:
    print (i,end=' ')