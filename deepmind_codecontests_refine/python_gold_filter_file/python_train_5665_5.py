n = int(input())
x,y,z = [0]*3
for i in range(n):
    a,b = input().split()
    x += int(a)
    y += int(b)
    z += (int(a)+int(b))%2
print((-1,(0,(-1,1)[z>0])[y%2])[x%2==y%2])