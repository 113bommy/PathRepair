#   https://codeforces.com/contest/1248/problem/A
for _ in range(int(input())):
    n1 = int(input())
    l1 = list(map(int, input().split()))
    n2 = int(input())
    l2 = list(map(int, input().split()))
    e1,o1,e2,o2 = 0,0,0,0
    for i in l1:
        e1 += not(i&1)
        o1 += (i&1)
    for i in l2:
        e2 += not(i&1)
        o2 += (i&1)
    print((o1*o2) + (e2*e2))
