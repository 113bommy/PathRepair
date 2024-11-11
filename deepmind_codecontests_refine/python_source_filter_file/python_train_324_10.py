n=int(input())
l=[int(i) for i in input().split()]
lp=[]
li=[]
for i in range(n):
    if l[i]%2==0:
        lp.append(l[i])
    else:
        li.append(l[i])
li=sorted(li)
li=li[::-1]
lp=sorted(lp)
lp=lp[::-1]
print(lp)
print(li)
if (len(lp)==len(li)) or abs(len(lp)-len(li))==1 :
    print(0)
elif len(li)>len(lp):
    print(sum( li[len(lp)+1::]))
else:
    print(sum( lp[len(li)+1::]))