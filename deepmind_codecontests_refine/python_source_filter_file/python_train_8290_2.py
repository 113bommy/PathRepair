s=input()
l=[]
for i in range(10):
    d=input()
    l.append(d)
print(l)
ans=''
i=0
while(i<80):
    ans+=str(l.index(s[i:i+10]))
    i+=10
print(ans)