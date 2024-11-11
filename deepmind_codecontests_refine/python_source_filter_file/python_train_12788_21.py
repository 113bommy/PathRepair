a,b,c,d,e,f=[int(x) for x in input().split()]

ans=0
ans_s=0
ans_all=0
wlist=[]
slist=[]
for i in range(f//(100*a)+1):
    for j in range((f-i*100*a)//(100*b)+1):
        wlist.append(100*a*i+100*b*j)
for i in range((f*e//100)//c+1):
    for j in range((f*e//100)//d+1):
        slist.append(c*i+d*j)
wlist=set(wlist)
slist=set(slist)
for w in wlist:
    for s in slist:
        if w+s==0:break
        if s*100/(w+s)>ans and w*e/100>=s and w+s<=f:
            ans=s*100/(w+s)
            ans_s=s
            ans_all=w+s
print(ans_all,ans_s)