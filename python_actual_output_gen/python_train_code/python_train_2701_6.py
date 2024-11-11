n=int(input())
s=list(map(int,input().split()))
p=None
d=s[n-1]-s[n-2]
n1=s[n-1]+d
if(n1 > s[n-1] and n1 <=15):
    p="UP"
elif(n1 < s[n-1] and n1 >=0):
    p="DOWN"
elif(s[n-1]==15):
    p="DOWN"
elif(s[n-1]==0):
    p="UP"
else:
    p=-1
    
if(len(s)==1 and (s[n-1]!=15 or s[n-1]!=0)):
    p=-1
print(p)