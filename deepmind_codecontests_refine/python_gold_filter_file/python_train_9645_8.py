n=int(input())
a=list(map(int,input().split()))
c=[]
for i in range(len(a)):
    if(a[i]!=0):
        c.append(a[i])
a=list(set(c))
a=sorted(a)
print(len(a))
