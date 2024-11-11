n=int(input())
p=n
i=1
l=1
sd=0
s=0
j=1
while(n>9):
    n=int(n/10)
    i*=10
    l+=1
if p>9:
    while i!=1:
        s=p-i
        if j==1:
            s=s+1
        sd+=s*l
        p=i
        i=i/10
        l-=1
        j+=1
    p=9
print(p+sd)
        