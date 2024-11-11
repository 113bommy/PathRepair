n,k=[int(x) for x in input().split()]
s=input()
ct=[0 for i in range(26)]
for i in range(len(s)):
    ct[ord(s[i])-ord('A')]=ct[ord(s[i])-ord('A')]+1
flag=1
for i in range(k):
    if ct[i]==0:
        flag=0
min=1e5
if flag==1:
    for i in range(k):
        if ct[i]<min:
            min=ct[i]
    print(k*min)
else:
    print(0)
    
