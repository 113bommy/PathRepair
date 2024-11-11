n=int(input())
a=list(input())
f=input().split()
i=0
while i<n and int(f[int(a[i])-1])<int(a[i]): i+=1
while i<n and int(f[int(a[i])-1])>=int(a[i]): 
    a[i]=f[int(a[i])-1]
    i+=1
print(''.join(a))
