n=int(input())
s=input()
ma=0
d={'R':0,'G':0,'B':0}
d[s[0]]+=1
for i in range(1,n):
    if(s[i-1]==s[i]):
        d[s[i-1]]+=1
    else:
        ma+=d[s[i-1]]-1
        d[s[i-1]]=0
        d[s[i]]=1
if(n==1):
    print(0)
else:
    if(s[-2]==s[-1]):
        ma+=d[s[-1]]
    print(ma)

             