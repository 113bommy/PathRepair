#
# itp1 11d
#
import random


class Cube:
    def __init__(self, u, s, e, w, n, d):
        self.u = u
        self.s = s
        self.e = e
        self.w = w
        self.n = n
        self.d = d

    def rotate(self, dic):
        if dic == "N":
            tmp = self.u
            self.u = self.s
            self.s = self.d
            self.d = self.n
            self.n = tmp
        elif dic == "E":
            tmp = self.u
            self.u = self.w
            self.w = self.d
            self.d = self.e
            self.e = tmp
        elif dic == "W":
            tmp = self.u
            self.u = self.e
            self.e = self.d
            self.d = self.w
            self.w = tmp
        else:
            tmp = self.u
            self.u = self.n
            self.n = self.d
            self.d = self.s
            self.s = tmp


def main():
    N = int(input())
    cubeL = []
    for i in range(N):
        u, s, e, w, n, d = map(int, input().split())
        cube = Cube(u, s, e, w, n, d)
        cubeL.append(cube)

    ret = "Yes"
    for i in range(N):
        for j in range(i+1, N):
            flag = True
            for k in range(10000):
                cubeL[j].rotate(random.choice("NEWS"))
                if cubeL[i].u == cubeL[j].u and cubeL[i].n == cubeL[j].n and cubeL[i].w == cubeL[j].w and cubeL[i].e == cubeL[j].e and cubeL[i].s == cubeL[j].s and cubeL[i].d == cubeL[j].d:
                    flag = False
                    break
            if not flag:
                break
        if not flag:
            ret = "No"
            break
    print(ret)


if __name__ == '__main__':
    main()

