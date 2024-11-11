s=input()
v="AEIOUY"
prev=0
maxi=0
for i in range(len(s)):
    if s[i] in v:
        maxi=max(maxi,i-prev)
        prev=i
#maxi=max(maxi,len(s)-1-prev)
print(maxi)
    
