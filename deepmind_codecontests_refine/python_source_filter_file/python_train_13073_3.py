n=int(input())
s=list(input())
m=list(input())
for i in range(0,n):
    s[i]=int(s[i])
    m[i]=int(m[i])

a=[0]*(10)
b=[0]*(10)
for i in range(0,n):
    a[m[i]]+=1
    b[m[i]]+=1
s.sort()
count=n
for i in range(0,n):
    temp=s[i]
    for i in range(temp,n+1):
        if(a[i]>0):
            count-=1
            a[i]-=1
            break
print(count)
count=0
for i in range(0,n):
    temp=s[i]
    for i in range(temp+1,n+1):
        if(b[i]>0):
            count+=1
            b[i]-=1
            break
print(count)
    

            