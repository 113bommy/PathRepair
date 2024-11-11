def main():
    a, b, c = [input() for _ in [0]*3]
    p = [(a, b, c), (a, c, b), (b, a, c), (b, c, a), (c, a, b), (c, b, a)]

    def check(x, y):
        lx, ly = len(x), len(y)
        ans = {lx}
        for i in range(lx):
            for j in range(min(ly, lx-i)):
                if x[i+j] != y[j] and (x[i+j] != "?" and y[j] != "?"):
                    break
            else:
                ans.add(i)
        return ans

    def check2(x, y, z):
        lx, ly, lz = len(x), len(y), len(z)
        ans = lx+ly+lz
        dxy, dyz, dxz = d[(x, y)], d[(y, z)], d[(x, z)]
        for i in dxy:
            ans = min(ans, max(lx, i+ly)+lz)
            for j in dyz:
                if i+j in dxz or i+j >= lx:
                    ans = min(ans, max(lx, i+ly, i+j+lz))
            for j in range(ly, lx-ly):
                if i+j in dxz:
                    ans = min(ans, max(lx, i+j+lz))
        return ans

    d = {(x, y): check(x, y) for x, y, z in p}
    print(min([check2(x, y, z) for x, y, z in p]))


main()