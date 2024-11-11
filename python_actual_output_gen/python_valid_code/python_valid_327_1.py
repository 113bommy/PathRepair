n,m = input().split()
n=int(n)
m=int(m)
s=0
for i in range(n):
    l=input().split()
    j=0
    while(j<=m):
        if(l[j]=='0' and l[j+1]=='0'):
            j+=2
            continue
        else:
            s+=1
            j+=2

print(s)
