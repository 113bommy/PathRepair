N=int(input())
an=list(map(int,input().split()))
s=sum(an)
b = an[0]

l=[]
a = abs(s-2*b)
for i in range(1,N-1):
    b = b + an[i]
    a=min(a,abs(s-2*b))
print(a)