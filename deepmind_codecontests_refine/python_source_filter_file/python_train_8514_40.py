import bisect
s=list(input())
t=list(input())
N=len(s)
sd={x:[] for x in sorted(set(s))}
if not set(t) <= set(sd.keys()):
    print(-1)
    exit()

for i,c in enumerate(s):
    sd[c].append(i)
index=0
ans=0
for c in t:
    i=bisect.bisect_left(sd[c],index+1)

    if i==len(sd[c]):
        ans+=1
        i=bisect.bisect_left(sd[c],0)
    index=sd[c][i]
print(ans*N+index+1)
