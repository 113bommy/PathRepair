import bisect
def s(n):
    global d
    prime = [True for i in range(n+1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n+1, p):
                prime[i] = False
        p += 1
    l=0
    pri=[]
    for p in range(2, n+1):
        if prime[p]:
            pri.append(p)
            d[p]=True
        else:
            d[p]=False
    return pri
def gcd(a,b):
    if a%b==0:return b
    return gcd(b,a%b)
d={}
arr=s(100000)
for i in range(int(input())):
    n=int(input())
    p=1+n
    if d[p]==True:an1=p
    else:an1=arr[bisect.bisect_left(arr,1+n)]
    q=an1+n
    if d[q]==True:an2=q
    else:an2=arr[bisect.bisect_left(arr,1+2*n)]
    an=an1*an2//gcd(an2,an1)
    print(an)