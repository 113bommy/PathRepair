def gcd(a, b):
    if b==0:
        return a
    else:
        return gcd(b, a%b)


s = input().split(' ')
a = int(s[0])
b = int(s[1])
c = int(s[2])
d = int(s[3])

r1 = a/b
r2 = c/d

if r1 < r2:
    nom = b*c-d*a
    den = c*b
    g = gcd(nom, den)
    nom = nom//g
    den = den//g
    print(str(nom)+" "+str(den))
else:
    nom = a*d-c*b
    den = d*a
    g = gcd(nom, den)
    #print(nom, den)
    nom = nom//g
    den = den//g
    print(str(nom)+" "+str(den))

