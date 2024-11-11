for i in range(int(input())):
    n,m=map(int,input().split())
    x=[int(q) for q in input().split()]
    if m <= sum(x):
        print(m)
    else:
        print(sum(x))