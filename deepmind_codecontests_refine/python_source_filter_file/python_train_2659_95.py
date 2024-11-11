x,y=map(int,input().split())
s=input().split()
z=0
for i in range(x):
    if int(s[i])<y:
        z=z+1
    else:
        z=z+2
print(z)