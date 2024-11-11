x,y,z=*[int(input()) for i in range(3)]
x-=(x//y)*y
x-=(x//z)*z
print(x)