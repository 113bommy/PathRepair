a,b,c=map(int,input().split())
ans=[]
def dsum(x):
    if(x<=0 or x>=1e9):
        return -1
    else:
        ans=0
        for i in str(x):
            ans+=int(i)
        return ans
for s in range(1,73):
    x=b*(s**a) + c
    if dsum(x)==s:
        ans.append(x)
ans.sort()
print(len(ans))
for i in ans:
    print (i,end=" ")