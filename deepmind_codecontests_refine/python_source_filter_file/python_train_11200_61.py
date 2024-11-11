def main():
    res = 0
    n = int(input())
    dct = {"Icosahedron":20, "Cube":6, "Tetrahedron":4, "Dodecahedron":12, "Octahedron":8}
    for i in range(n):
        res += dct[input().strip()]
    return res
main()