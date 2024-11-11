from sys import stdin
input = stdin.readline
q = int(input())
for _ in range(q):
    n =  int(input())
    l = list(map(int,input().split()))
    s = sum(l)
    if s%n != 0:
        print(-1)
    else:
        print(3*n-3)
        goal = s // n
        for i in range(n-1):
            l2 = l[i+1]
            brak = (-l2)%(i+1)
            print(1, i+2, brak)
            l[i+1] += brak
            l[0] -= brak
            print(i+2,1, l[i+1]//(i+2))
            l[0] += l[i+1]
            l[i+1] = 0
        for i in range(n-1):
            print(1,i+2,goal)
