n=int(input())
s1,s2=0,0
tab = []
for i in range(n):
    c = list(map(int,input().split()))
    for j in range(1,c[0]+1):
        if(j*2<=c[0]): s1+=c[j]
        else: s2+=c[j]
    if(c[0] & 1):
        s2-=c[(c[0]+1)//2]
        tab.append(c[(c[0]+1)//2])
if(len(tab) & 1):
    tab.sort()
    tab.reverse()
    for i in range(len(tab)):
        if(i & 1): s2+=tab[i]
        else: s1+=tab[i]
print(s1,s2)
