n=int(input())
arr=list(map(int,input().split()))
neg=[]
i=1
while i<n+1:
    if arr[i-1]<0:
        neg.append(i)
    i+=1
a=0
count=0
m=len(neg)
if m==0:
    print('0 '+str((n*n+n)//2))
else:
    i=0
    b=0
    c=0
    if m>1:
        while i<m-1:
            if i%2==1:
                count+=(c+neg[i]-a)*(neg[i+1]-neg[i])
                c+=neg[i]-a
            else:
                count+=(b+neg[i]-a)*(neg[i+1]-neg[i])
                b+=neg[i]-a
            a=neg[i]
            i+=1
    if m%2==1:
        count+=(b+neg[-1]-a)*(n+1-neg[-1])
    else:
        count+=(neg[-1]-a)*(n+1-neg[-1])
    print(str(count)+' '+str(((n*n+n)//2)-count))
    