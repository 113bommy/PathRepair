'''
Ax+By+C=0
find any point whose coordinates are integer.

Now consider Ax+By=gcd(A,B)
->Ax+By=-C/z and -C/z=gcd(A,B)
->Axz + Byz + C = 0 and z=-C/gcd(A,B)

According to Euclidean Algorithm, we could get x,y
'''

def CF_7C():
    A,B,C=list(map(int,input().split()))
    if A==0:
        if C%B != 0:
            print(-1)
        else:
            print(0,-C//B)
    elif B==0:
        if C%A != 0:
            print(-1)
        else:
            print(-C//A,0)
    else:
        #s[-2] and t[-2] are the solution of the equation s*A + t*B = gcd(A,B)
        s,t,g=extended_gcd(A,B)
        x,y=-s*C//g,-t*C//g
        if A*x+B*y+C!=0:
            print(-1)
        else:
            print(x,y)
    return

# recursive
def gcd(a,b):
    if b!=0:
        return gcd(b,a%b)
    else:
        return a

def extended_gcd(a,b):
    q=[]
    while b!=0:
        q.append(a//b)
        a,b=b,a%b
    #a is the gcd(a,b)
    s=[1,0]
    t=[0,1]
    for i in range(0,len(q)):
        s.append(s[-2]-q[i]*s[-1])
        t.append(t[-2]-q[i]*t[-1])
    #After the iteration, s[-2] and t[-2] are the solution of the equation s*A + t*B = gcd(A,B)
    #s[-1]*A + t[-1]*B = 0
    #print(s,t,a)
    return (s[-2],t[-2],a)

CF_7C()