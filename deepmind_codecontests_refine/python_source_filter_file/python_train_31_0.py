n=input().split()
for i in range(0,len(n)):
    n[i]=int(n[i])

if n[0]/n[1]==100/n[2]:
    print(0)
    exit()

s=n[0]/100

vi=int(s*n[2])
vf=s*n[2]
if vf<=0:
    print(0)
    exit()

if abs(vf - vi) > 0.000001:
    vi+=1



print(vi-n[1])
