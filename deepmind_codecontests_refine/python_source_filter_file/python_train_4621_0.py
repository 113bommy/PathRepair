n = int(input())
p = []
f = []
def prime(x):
    for i in range(2,x):
        if x % i == 0:
            return False
    return True
    
def factorize(x):
    i = 2;
    while(i*i <= x):
        while(x % i == 0):
            f.append(i)
            x /= i
        i = i+1
    
    if(x > 1):
        f.append(x)
    f.reverse()
    

x = 2
while(len(p) < 70):
    if prime(x):
        p.append(x)
    x = x + 1

factorize(n)
if(n == 1):
    print(n)
else:
    sum = f[0]
    ans = p[0] ** (f[0]-1)
    for i in range(1,len(f)):
        c1 = ans * (p[i] ** (f[i]-1))
        c2 = ans / (2 ** (sum-1)) * (2 ** (sum*f[i]-1))
        if(c1 < c2):
            ans = c1
        else:
            ans = c2
            sum *= f[i]
    print(ans)
            