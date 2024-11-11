n,m=map(int,input().split())
a=(list(map(int,input().split())))
z=0
for i in range(1,m+1):
    f=a.count(i)
    z+=f*(f-1)/2
k=((len(a)*(len(a)-1))//2)-z
print(k)