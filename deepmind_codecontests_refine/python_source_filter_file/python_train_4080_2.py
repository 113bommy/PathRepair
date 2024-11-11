n,k=tuple(map(int,input().split()))
a=list(map(int,input().split()))
a1=sorted(a)
a=sorted(a)
l=[[0 for i in range(n)]for j in range(20)]
d={}
for j in range(n):
    x=1
    for i in range(20):
        if(i==0):
            l[i][j]=a[j]
        else:
            l[i][j]=a[j]//2 
            a[j]=a[j]//2

value=10**5

for i in range(20):
    for j in range(n):
        if(l[i][j]!=0):
            if(l[i][j] not in d):
                d[l[i][j]]=[1,i]
            else:
                if(d[l[i][j]][0]<k):
                    d[l[i][j]][0]+=1
                    d[l[i][j]][1]+=i 
for i in d:
    if(d[i][0]>=k):
        value=min(value,d[i][1])
#print(d)
temp_ans=0
for j in range(k):
    for i in range(1,20):
        x=2
        if(a1[j]//x  !=0):
            a1[j]=a1[j]//x
        else:
            temp_ans+=i-1
value=min(temp_ans,value)
print(value)