n=int(input())
a=list(map(int,input().split()))[:]
c=k=0
n1=[]
n2=[]
n3=[]
a.sort()
print(1,a[0])
if a[n-1]>0:
    print(1,a[n-1])
    print(n-2,*a[1:n-1])
else:
    print(2,a[n-1],a[n-2])
    print(n-3,*a[1:n-2])
