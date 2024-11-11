inp=input()
n=inp.split()
first=list(n[0])
last=list(n[1])
p2=ord(last[0])
flag=0
for i,k in enumerate(first[1:]):
    if ord(k)>p2:
        p1=i
        flag=1
        break
if flag==1:
    ans=''.join(first[:p1+1])
else:
    ans=n[0]
print(ans+last[0])
