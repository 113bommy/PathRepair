s=input()
a=[]
for i in range(len(s)):
    a.append(s[i])
count=0
f1=False
index=-1
for k in range(len(a)):
    if(a[len(a)-1-k]=="]"):
        f1=True
    if(a[len(a)-1-k]==":" and f1):
        index=len(a)-1-k
        break
f1=False
f2=False
f3=False
for j in range(len(a)):
    if(a[j]=="["):
        f1=True
    if(a[j]==":" and f1):
        f2=True
        if(j!=index):
            f3=True
    if(a[j]=="|" and f1 and f2 and j<index):
        count+=1
if(index==-1):print(-1)
elif(f3):print(count+4)
else:print(-1)        