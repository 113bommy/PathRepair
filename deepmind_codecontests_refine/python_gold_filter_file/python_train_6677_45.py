q = int(input())
cost = []

for i in range(q):
    n,a,b = map(int,input().split())
    if a*2 < b:
        cost.append(n*a)
    else:
        if n%2 == 0:
            cost.append(n*b/2)
        if n%2 == 1:
            cost.append((n//2)*b + a)

for i in range(q):
    print(int(cost[i]))