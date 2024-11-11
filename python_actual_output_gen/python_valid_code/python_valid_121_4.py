s=input().split()
n=int(s[0])
k=int(s[1])
h=[]
s=input().split()
for x in s:
    h.append(int(x))
h.sort()
hp=[0 for i in range(h[n-1]+2)]
for i in range(n):
    hp[h[i]]=i
for i in range(0,h[n-1]):
    if hp[i+1]==0:
        hp[i+1]=hp[i]
cnt=0
now=0
for i in range(h[n-1]-1,h[0]-1,-1):
    if now+(n-hp[i]-1)<=k:
        now += (n - hp[i])
    else:
        cnt+=1
        now=(n - hp[i])
if now>0:
    cnt+=1
print(cnt)