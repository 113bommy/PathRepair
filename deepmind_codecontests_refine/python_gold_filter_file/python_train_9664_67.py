x,y,z=[int(input()) for i in range(3)]
x-=y
x-=(x//z)*z
print(x)