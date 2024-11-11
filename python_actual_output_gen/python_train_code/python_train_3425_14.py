a,b=map(int,input().split(":"))
d,e=map(int,input().split(":"))
if b-e<0 and a-d>0:
    r=a-d-1
    R=60+b-e
elif b-e<0 and a-d==0:
    r=23
    R=60+b-e
elif a-d<0 and b-e>=0:
    r=24+a-d
    R=b-e
elif a-d<0 and b-e<0:
    r=24+a-d
    R=60+b-e
else:
    r=a-d
    R=b-e
r=str(r)
R=str(R)
for i in range(2-len(r)):
    r="0"+r
for i in range(2-len(R)):
    R="0"+R
print(r+":"+R)
    
