n,t=map(int,input().split())
s=input()
a=[0]*n
a[0]=ord(s[0])-96
for i in range(1,n):
    a[i]=a[i-1]+ord(s[i])-96
print(a)
for _ in range(t):
    l,r=map(int,input().split())
    if(l>1):
        print(a[r-1]-a[l-2])
    else:
        print(a[r-1])
