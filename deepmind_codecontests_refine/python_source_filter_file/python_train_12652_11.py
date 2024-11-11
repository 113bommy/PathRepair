a,ta=map(int,input().split())
b,tb=map(int,input().split())
dep=str(input())
t=int(dep[0])*10*60+int(dep[1])*60+int(dep[3])*10+int(dep[4])-5*60
depb=t-tb
if (depb<0):
    depb=0
else:
    depb=depb-depb%b+b

c=0
while depb<t+ta and depb<=1439:
    c+=1
    depb+=b
print (c)