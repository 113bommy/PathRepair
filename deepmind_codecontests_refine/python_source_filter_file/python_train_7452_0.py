x=input()
l=x.split()
n=int(l[0])
m=int(l[1])
k=int(l[2])
def func_2(m,k):
    if k==1:
        return True
    s=int(m**.5)
    for i in range(2,s+1):
        if not m%i:
            if i>=k or m/i>=k:
                return True
    return False
if func_2(m,k):
    p=n
else :
    p=0
if p%2==0:
    print('Marsel')
else :
    print('Timur')
