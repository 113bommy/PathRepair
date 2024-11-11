import math

n=int(input())
s=list(map(int,input().split()))
c1,c2,c3,c4=s.count(1),s.count(2),s.count(3),s.count(4)
sum=c4
# sum+=c2//2
# c2=c2%2
if c1<=c3:
    sum+=c1
    sum+=c3-c1
    sum+=math.ceil(c2*2/4)
else:
    sum+=c3
    c1=c1-3
    
    sum+=math.ceil((c1+c2*2)/4)
print(sum)