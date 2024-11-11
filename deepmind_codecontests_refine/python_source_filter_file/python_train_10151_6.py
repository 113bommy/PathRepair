def gcd (a, b): 
    while b:
        a %= b
        c = a
        a = b
        b = c
    return a

def lcm (a, b):
    return a // gcd (a, b) * b

v = input().split(' ')
t = int(v[0])
a = int(v[1])
b = int(v[2])
if a>b:
    c = a
    a = b
    b = c

l = lcm(a, b)
all = t;
good = (t/l)*(a);

if t>l: 
    good-=a;
    good+=(min(t%l+1,a));

good+=(min(t, a-1));

g=gcd(good, all);
good//=g
all//=g

print(str(int(good))+'/'+str(int(all)))
