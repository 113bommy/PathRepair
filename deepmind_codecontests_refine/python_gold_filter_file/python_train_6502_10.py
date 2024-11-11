def con(a,b):
    if a==0 or a<b:
        return 0
    if a==b or b==0:
        return 1
    if b==1 :
        return a
    return con(a-1,b-1)*a//b

s=[int(i) for i in input().split(' ')]
mini=s[0]//s[1]
mini2=0
maxi=con(s[0]-s[1]+1,2)
if (s[0]%s[1]>0):
    mini2=1
mini=con(mini,2)*(s[1]-s[0]%s[1])
mini+=con(s[0]//s[1]+1,2)*(s[0]%s[1])
s=str(int(mini))+" "+str(int(maxi))
print(s)