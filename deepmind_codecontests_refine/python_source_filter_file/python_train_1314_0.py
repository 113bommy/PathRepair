z = 0
o = 1023
n = int(input())
for i in range(n):
    a,b = input().split()
    b = int(b)
    if(a == "&"):
        z = z&b
        o = o&b
    if (a == "^"):
        z = z ^ b
        o = o ^ b
    if (a == "&"):
        z = z | b
        o = o | b
z = '{:010b}'.format(z)
o = '{:010b}'.format(o)
an = 0
r = 0
xo = 0
pw = 512
for i in range(10):
    an+=pw
    if(o[i]=='0' and z[i] == '0'): an-=pw
    if (o[i] == '1' and z[i] == '1'): r+=pw
    if (o[i] == '0' and z[i] == '1'): xo+=pw
    pw//=2
print(3)
print("&",an)
print("|",r)
print("^",xo)



