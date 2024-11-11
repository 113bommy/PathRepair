n,m=map(int,input().split())
s=list(input().split(' '))
t=list(input().split(' '))
q=int(input())
l=[]
i=0
j=0
count=0
while count<n*m:
    l.append(s[i]+t[j])

    if i==n-1:
        i=-1
    if j==m-1:
        j=-1
    i += 1
    j += 1
    count+=1
print(l)
for i in range(q):
    z=int(input())
    z=z%(n*m)
    print(l[z-1])