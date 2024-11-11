s=input()
s=list(s)
s1=[0]*len(s)
for i in range(len(s)):
    if s[i]=='-':
        s[i]=1
        s1[i]=-1 
    else:
        s[i]=-1 
        s1[i]=1 
def kadane(s):
    maxi=-1 
    curr=0 
    for i in s:
        curr=max(curr+i,i)
        maxi=max(maxi,curr)
    return maxi 
#print(max(kadane(s),kadane(s1)))
print(kadane(s))