k=int(input())
s=list(input())
s.sort()
count=0
s1=""
l=len(s)
for i in range(l):
    if i%k==0:
        ch=s[i]
    if s[i]==ch:
        count+=1
if (count==l & count%k==0):
    for j in range(0,l,k):
        s1+=s[j]
    print(s1*k)
else:
    print("-1")
	        
    
