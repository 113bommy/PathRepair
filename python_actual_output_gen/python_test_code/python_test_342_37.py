n=int(input())
fl=0
nu=1
i=1
while True:
    if n>=0:
        fl+=1
        i+=1
        nu+=i
        n=n-nu
        #print(nu)
    else:
        break
print(fl)
