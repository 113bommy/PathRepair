n=int(input())
s=input()
mx='a'
lol=0
for i in range(1,n):
    if(s[i]>=mx):
        mx=s[i]
        li=i
    else:
        ind=i
        lol=1
        break
if(lol==0):
    print("NO")
else:
    print("YES")
    print(li+1,ind+1)