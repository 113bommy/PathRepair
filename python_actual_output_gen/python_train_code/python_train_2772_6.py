def sti(x):
    o=0
    x=x[::-1]
    k=1
    ans=1
    for i in x:
        l="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_"
        o=l.index(i)*k
        for i in range(0,6):
            if (o&(2**i)):
                ans=(ans*3)%1000000007
    return ans
def bth(x):
    x=x[::-1]
    k=1
    o=0
    for i in x:
        o+=int(i)*k
        k*=2
    return str(o)
def htb(x):
    x=int(x)
    s=""
    while x>0:
        s+=str(x%2)
        x//=2
    return s[::-1]
s=input()
print(sti(s))
