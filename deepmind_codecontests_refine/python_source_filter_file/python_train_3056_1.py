s=input()
j=0
i=1
s=s+' '
while i!=len(s):
    j=i-1
    if s[j]=='/'==s[i]:
        while s[j]==s[i]:
            index=i
            s=s[:index]+s[index+1:]
    
    i+=1 
l=len(s)-2
if s[l]=='/':
    index=l
    s=s[:index]+s[index+1:]       
print(s)

