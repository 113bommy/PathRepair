n,k=map(int,input().split())
s=input()
s=sorted(s)
c=k-1
s1=s[0]
l=0
for i in range(1,n):
    if((ord(s[i])-ord(s1[l]))>1):
        c-=1
        s1+=s[i]
        l+=1
    if(c==0):
        break
if(c==0):
    a=0
    for k in s1:
        a+=ord(k)-ord('a')+1
    print(a)
else:
    print(-1)


