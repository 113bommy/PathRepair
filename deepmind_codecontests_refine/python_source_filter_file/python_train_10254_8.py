def eqivalent_string(a, b):
    if(a == b):
        return True
        
    if(len(a) % 2 != 0):
        return False

    n = len(a)
    a1 = a[0:int(n/2)]
    a2 = a[int(n/2) + 1:n]
    b1 = b[0:int(n/2)]
    b2 = b[int(n/2) + 1:n]

    return (eqivalent_string(a1,b2) and eqivalent_string(a2, b1)) or (eqivalent_string(a1,b1) and eqivalent_string(a2,b2))

a = input()
b = input()

if(eqivalent_string(a,b)):
    print("YES")
else:
    print("NO")