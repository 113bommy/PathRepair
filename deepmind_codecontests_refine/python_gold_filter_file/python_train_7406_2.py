n=int(input())
a=[int(i) for i in input().split()]
a=a+a
e=0
l=[]
for i in range(0,len(a)):
    if(a[i]==1):
        e=e+1
    else:
        l.append(e)
        e=0
l.append(e)
print(max(l))