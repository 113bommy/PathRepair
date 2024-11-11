s=input()
l1=[]
count=1
l1.append(s)
for i in range(0,len(s)-1):
    s=s[1:]+s[:1]
    if s not in l1:
        count+=1
        l1.append(s)
print(count)