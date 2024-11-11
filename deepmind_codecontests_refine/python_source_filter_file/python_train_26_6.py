
def check(a , b , c, d):
    if (a==b):
        return False
    if (a==c):
        return False
    if (a==d):
        return False
    if (b==c):
        return False
    if (b==d):
        return False
    if (c==b):
        return False
    return True

r=(input().split())
c=(input().split())
d=(input().split())
r = list(map(int, r))
c = list(map(int, c))
d = list(map(int, d))
t=False
total=(r[0]+r[1]+c[0]+c[1]+d[0]+d[1])/3
for i in range(10):
    a=i
    for j in range(10):
        b=j
        for k in range(10):
            for z in range(10):
                if total==a+b+k+z:
                    if r[0]== (a+b):
                        if r[1]== (k+z):
                            if c[0] == (a + k):
                                if c[1] == (b+z):
                                    if d[0] == (a+z):
                                        if d[1] == (k + b):
                                            if check(a,b,k,z):
                                                t=True
                                                print(a,b)
                                                print(k,z) 
                                                
                                            
                                            
if not t :
    print(-1)