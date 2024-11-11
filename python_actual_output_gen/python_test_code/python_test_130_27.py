s = input()
t = input()
c=0
i=0
j=0
while (j<len(t)-1) and (i<len(s)-1):
    if s[i] == t[j]:
        c+=1
        i+=1
    j+=1
    
print(c+1)