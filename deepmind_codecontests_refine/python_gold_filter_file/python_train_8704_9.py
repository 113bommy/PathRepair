f=input()
f=int(f)
while f%10==0:
    f=f//10
f=str(f)
if len(f)==1:
    print('Yes')
else:
    if f[0:(len(f))//2:1]==f[:(((len(f)+1)//2)-1):-1]:
        print('Yes')
    else:
        print('No')