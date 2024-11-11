n=int(input())
s=input()
tmp=0
for i in range(n-10):
    if s[i]=="8":
        tmp+=1
    else:
        tmp-=1
if tmp<=0:
    print("NO")
else:
    print("YES")
