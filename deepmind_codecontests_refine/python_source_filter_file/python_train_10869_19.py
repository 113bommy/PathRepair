n=int(input())
l=list(map(int,input().split()))
m=abs(l[0]-l[-1])
a,b=1,n
for i in range(n-1):
    if m>abs(l[i]-l[i+1]):
        m=abs(l[i]-l[i+1])
        a,b=i,i+1
print(a,b)