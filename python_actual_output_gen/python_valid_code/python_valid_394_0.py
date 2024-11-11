l = int(input())
i = 0
for _ in range(l):
    n, x = list(map(int, input().split()))
    ll = list(map(int, input().split()))
    llmax = max(ll)
    if x in ll:
        print(1)
    elif llmax > x:
        print(2)
    else:
        print(x // llmax + 1)