import sys

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = input()
    comp = []
    s = [s[-i-1] for i in range(n)]
    bi = s.pop()
    L = 1
    while s:
        if s[-1]==bi:
            L += 1
            s.pop()
        else:
            comp.append(L)
            L = 1
            bi = s.pop()
    comp.append(L)

    a = 0
    b = 0
    res = 0
    while a<len(comp):
        if comp[a]!=1:
            comp[a] = 0
            res += 1
            a += 1
        else:
            while b<len(comp):
                if comp[b]>=2:
                    break
                else:
                    b += 1
            if b==len(comp):
                comp[a] = 0
                if a+1<len(comp):
                    comp[a+1]=0
                    res += 1
                    a += 2
                else:
                    res += 1
                    a += 1
            else:
                comp[b] -= 1
                res += 1
                comp[a] = 0
                a += 1
    print(res)