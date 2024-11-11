n,k=map(int,input().split())
s=input()
sub=0
count=0
pre=input().split()
for i in range(len(s)):
    if s[i] in pre:
        count+=1
    else:
        sub=count*(count+1)//2
        count=0
if s[n-1] in pre:
    sub=sub+count*(count+1)//2
print(sub)