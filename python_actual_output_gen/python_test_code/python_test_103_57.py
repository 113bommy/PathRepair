n = int(input())
ans = 0
for i in range(n):
    a = input()
    if a == 'Tetrahedron':
        ans += 4
    elif a == 'Cube':
        ans += 6
    elif a == 'Octahedron':
        ans += 6
    elif a == 'Dodecahedron':
        ans += 12
    else:
        ans += 20
print(ans)