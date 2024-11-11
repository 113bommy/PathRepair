import sys
f = sys.stdin

n = int(f.readline().strip())

a = f.readline().strip()

res = False

if n>3 and n//5>0:
    for i in range(1, n//5+1):
        for j in range(n-4):
            if j+i*4<n:
                if (a[j]=="*" and a[j+i]=="*" and a[j+2*i]=="*" and
                    a[j+3*i]=="*"  and a[j+4*i]=="*") :
                        res = True
                        break
        if res :
            break
        
if res:
    print("yes")
else:
    print("no")

        
        

