t=int(input())
for i in range(t):
    s=input()
    res = sorted(set(s))
    for j in res:
        if s.count(j) != 2 * s.count(j + j):
            print(j,end='')
    print()