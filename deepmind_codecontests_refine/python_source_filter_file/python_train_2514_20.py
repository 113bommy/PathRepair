n=int(input())
s=list(input())
lis=list(map(int,input().split()))
lis.insert(0,0)
f=0
for i in range(n):
    if int(s[i])<lis[int(s[i])]:
        f=1
        s[i]=str(lis[int(s[i])])
    elif f==1 and int(s[i])>=lis[int(s[i])]:
        break
print("".join(s))