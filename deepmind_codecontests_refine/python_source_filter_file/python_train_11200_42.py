

#a, b = map(int, input().split())
n = int(input())
s = 0

for i in range(0,n):
    figure = input()
    if figure == 'Tetrahedron': s+=4
    elif figure == 'Cube': s+=6
    elif figure == 'Octahedron': s+=8
    elif figure == 'Dodecahedron': s+=12
    elif figure == 'Icosahedron': s+=20

print(n)