xyz =[]
def input1():
    global xyz
    if len(xyz)==0:
        xyz=[i for i in input().split()]
        xyz=xyz[::-1]
    
    v=xyz[-1]
    del xyz[-1]
    return v

#___________________________________________________________________________

a = int(input1())
d = int(input1())
m = int(input1())

g = int(input1())
p = int(input1())
b = int(input1())

x = g - a
y = x + p - d
z = y + x + b - m

if x < 0 or y < 0 or z < 0 :
    print ( "NO" )

else :
    print ( "YES" )

