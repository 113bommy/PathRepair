def f(n):
    s=str(n)
    return sum([int(s[i]) for i in range(len(s))])

sunuke=[]
for i in range(16):
    for j in range(1,200):
        sunuke.append(j*(10**i)-1)

sunuke=list(set(sunuke))
sunuke.sort()
sunuke.pop(0)
L=len(sunuke)

tmp1,tmp2=sunuke[L-1],f(sunuke[L-1])
ans=[sunuke[L-1]]
for i in range(len(sunuke)-2,-1,-1):
    x=sunuke[i]
    if x*tmp2<=tmp1*f(x):
        ans.append(x)
        tmp1,tmp2=x,f(x)

ans.sort()

    

for i in range(int(input())):
    print(ans[i])