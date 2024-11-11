n,q=map(int,input().split())
s=input()
l=[ord(s[0])-96]
for i in range(1,len(s)):
    l.append(l[i-1]+ord(s[i])-96)
print(l)
for i in range(q):
    lo,r=map(int,input().split())
    if(lo==1): print(l[r-1])
    else:print(l[r-1]-l[lo-2])
        