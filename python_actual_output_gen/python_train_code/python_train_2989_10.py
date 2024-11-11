n=int(input())
a=input()
a=a.split()
j=0
for k in range (n):
    a[k]=int(a[k])
a.sort()
if a[0]>1:
    print(1)
elif n==1:
    print(a[0]+1)
else:
    for k in range (1,n):
        if a[j]!=a[k]-1:
            r=a[j]+1
            
        else:
            r=a[n-1]+1
        j+=1
    print(r)