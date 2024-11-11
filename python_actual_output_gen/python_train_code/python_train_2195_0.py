input()
a=input()
b=input() 
if "0" not in a or "1" not in a or "0" not in b:
    print(0)
else:
    o,z,res = 0,0,0
    o = a.count("0")
    z = a.count("1")
    for i in range(0,len(b)):
        if b[i]=="0":
            if a[i]=="0":
                res+=o
                z-=1
            else:
                res+=z
                o-=1    
    print(res)