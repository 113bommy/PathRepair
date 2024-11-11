'''
(a+b)=(a^b)+2*(a&b)
'''
def check(a,b):
    # a and vala
    for i in range(20):
        if a&(1<<i):
            if b&(1<<i):
                return False
    return True
# print(check(1,5))
def f(s,x):
    if (s-x)%2!=0:
        return 0
    nd=(s-x)//2
    bd=0
    if nd==0:
        bd=2
    if check(nd,x):
        btcnt=(bin(x).count("1"))
        return (2**(btcnt))-bd
    return 0

a,b=map(int,input().strip().split())

print(f(a,b))