n,m = [int(i) for i in input().split()]
p = [int(i) for i in input().split()]
q = [int(i) for i in input().split()]
def gcd(a,b):
    if(b == 0):
        return a
    return gcd(b,a%b)
if(len(p) < len(q)):
    print('0/1')
elif(len(p) == len(q)):
    a,b = p[0],q[0]
    g = gcd(a,b)
    print('{}/{}',a//g,b//g)
elif(p[0]*q[0] > 1):
    print('Infinity')
else:
    print('-Infinity')

