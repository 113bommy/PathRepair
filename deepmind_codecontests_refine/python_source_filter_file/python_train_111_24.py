n=int(input())
A=list(map(int,input().split()))
s=sum(A)
m=max(A)
l=0
for i in A:
    l+=(m-i)
if(l>s):
    print(m)
else:
    while(l<s):
        m+=1
        l=0
        for i in A:
            l+=(m-i)
    print(m)


