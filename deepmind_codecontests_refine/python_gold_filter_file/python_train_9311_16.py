n=int(input())

s=input()
s1=s.split()
l=[int(i) for i in s1]

dp1=[1 for i in range(len(l))]


for i in range(1,len(l)):

    if l[i]>l[i-1]:

        dp1[i]=dp1[i-1]+1

dp2=[1 for i in range(len(l))]

for i in range(len(l)-2,-1,-1):

    if l[i]<l[i+1]:

        dp2[i]=dp2[i+1]+1
maxlen=max(dp1)

for i in range(0,len(l)):

    if i+1<len(l) and i-1>=0 and l[i+1]>l[i-1]+1:

        maxlen=max(dp1[i-1]+dp2[i+1]+1,maxlen)
        
    if i-1>=0 and l[i]<=l[i-1]:
        
        maxlen=max(maxlen,dp1[i-1]+1)

    if i+1<len(l) and l[i]>=l[i+1]:

        maxlen=max(maxlen,dp2[i+1]+1)

    

print(maxlen)   
