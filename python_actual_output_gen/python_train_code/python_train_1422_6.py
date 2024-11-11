v = int(input())
x = len(str(v))
s = 0
if(x == 1):
    s = v
else:
    
    s = 9
    while(x != 1):
        s += (1+v-pow(10,x-1))*x
        v = pow(10,x-1)
        x-=1
print(s)