s=input()
l=[]
for i in range(1,len(s)-1,2):
    if s[i] not in l:
        l.append(s[i])
print(l,len(l))