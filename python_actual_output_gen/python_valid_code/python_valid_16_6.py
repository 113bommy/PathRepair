n=int(input())
a=list(map(int,input().split()))
s=sum(a)
x=[]
for i in range(n):
    if ((s-a[i])//(n-1))==a[i]:
        x.append(i+1)
print(len(x))
for i in range(len(x)):
    print(x[i],end=" ")
print()    

    