import sys
input=sys.stdin.readline
print=sys.stdout.write
n=int(input())
ar=list(map(int,input().split()))
p2=[2**i for i in range(1,64)]
d=dict()
for x in ar:
    try:
        d[x]+=1
    except:
        d[x]=1
ans=0
for x in p2:
    for el in set(ar):
        if el*2 != x:
            try:
                ans+=(d[el]*d[x-el])
            except:
                pass
        else:
            ans+= (d[el]*(d[el]-1))//2
print(str(int(ans)))