l=list(map(int,input().split()))
td=(l[1]*l[2])//l[0]
tl=l[3]*l[4]
ts=l[5]//l[7]
tdt=td//l[0]
tlt=tl//l[0]
tst=ts//l[0]
print(min(tdt,tlt,tst))