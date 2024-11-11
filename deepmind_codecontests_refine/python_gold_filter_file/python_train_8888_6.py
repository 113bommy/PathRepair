def solve(n,a,b):
    cnt = 0


    for i in range(n):
        opener = a[i]
        for j in range(n):
            if i == j and opener == b[j]: continue
            elif i != j and opener != b[j]: continue
            else:
                if opener == b[j]:
                    cnt += 1
                    break

    print(n-cnt)







if __name__ == '__main__':
    n = int(input())
    a = []
    b = []
    for i in range(n):
        l,r = map(int,input().split())
        a.append(l)
        b.append(r)

    solve(n,a,b)