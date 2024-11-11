n = int(input())
A = 1023
B = 0
a = 1023
b = 0
print(4)
for i in range(n):
    s = str(input())
    if s[0] == '&':
        a = a & int(s[2:])
        b = b & int(s[2:])
    elif s[0] == '|':
        a = a | int(s[2:])
        b = b | int(s[2:])
    elif s[0] == '^':
        a = a ^ int(s[2:])
        b = b ^ int(s[2:])
Al = [1,1,1,1,1,1,1,1,1,1]
Bl = [0,0,0,0,0,0,0,0,0,0]
al = [0 for kk in range(10)]
bl = [0 for kk in range(10)]
#print(a,b)
for i in range(9,-1,-1):
    if a >= 2 ** i:
        al[i] = 1
        a -= 2**i
for i in range(9,-1,-1):
    if b >= 2 ** i:
        bl[i] = 1
        b -= 2**i
#print(al,bl)
And = []
Or = []
Xor = []
for i in range(10):
    if al[i] == 0 and bl[i] == 0:
        And.append(i)
    if al[i] == 0 and bl[i] == 1:
        Xor.append(i)
    if al[i] == 1 and bl[i] == 1:
        Or.append(i)
print(And, Or, Xor)
###
r = 0
for i in range(10):
    if i not in And:
        r += 2**i
print("&", r)
###
r = 0
if Xor == []:
    print("^ 0")
    print("^ 0")
elif Xor == [0]:
    print("^ 0")
    print("& 1")
#elif len(Xor) == 1:
    #r = 2**(max(Xor)+1) - 1
    #print("^", r)
    #print("| 1")
else:
    r = 2**(max(Xor)+1) - 1
    print("^", r)
    r = 0
    for i in range(max(Xor) + 1):
        if i not in Xor:
            r += 2**i
    print("^", r)
###
r = 0
for i in range(10):
    if i in Or:
        r += 2**i
print("|", r)
#print((1023 | 999)^689)
#print((0 | 999)^689)
#print((300 | 999)^689)
#print((((300 & 350)^31)^15)|326)