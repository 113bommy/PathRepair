a,b = map(int, input().split())
x,y,z = map(int, input().split())

na,nb = 0, 0
na = 2*x + y
nb = 3*z + y

print('{} {}'.format(max(na-a,0), max(nb-b, 0)))