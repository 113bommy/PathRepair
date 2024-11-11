x,y,z = map(int,input().split())
s = 0
s += x-y
print('+' if s>z and s>0 else '-' if s<z and s<0
        else '0' if s==z==0 else '?')
