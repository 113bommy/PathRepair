n=int(input())
l=list(map(int,input().split()))
b=sorted(l)
ans=[]
for x in b:
    ans.append(b[::-1].index(x)+1)
print(' '.join(map(str,ans)))