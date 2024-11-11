from sys import stdin

in1 = stdin.readline().split()
in2 = list(stdin.readline())

t = None
g = None

for i in range(len(in2)):
    if(in2[i] == "G"):
        g = i
        
for i in range(len(in2)):
    if(in2[i] == "T"):
        t = i
        
        
#check distance
distance = t-g

p = True

if(distance % (int)(in1[1]) != 0):
    print("NO1")
else:
    while g != t :
        if(distance<0):
            g-=(int) (in1[1])
            if(in2[g] == '#'):
                p = False
                break
        else:
            g+=(int) (in1[1])
            if(in2[g] == '#'):
                p = False
                break
                
    if(p):
        print("YES")
    else:
        print("NO2")
               

