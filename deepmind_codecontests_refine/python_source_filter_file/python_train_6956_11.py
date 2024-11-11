from collections import defaultdict
n=int(input())
s=input()
a=s[:n]
b=s[n:][::-1]
def coloring(x):
    N=1<<n
    dc=defaultdict(int)
    for i in range(N):
        r=''
        b=''
        for j in range(n):
            if i>>j&1:
                r+=x[j]
            else:
                b+=x[j]
        dc[r+'-'+b]+=1
    return dc    

fd=coloring(a)
ld=coloring(b)

for i,j in fd.items():
    ans+=ld[i]*j

print(ans)