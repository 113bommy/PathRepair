x,y,z = map(int,input().split())
s = 0
s += x-y
print('+' if abs(s)>z and s>0 else '-' if abs(s)<z and s<0
        else '0' if s==z==0 else '?')