n = int(input())
mass = [int(i) for i in input().split()]
mass.sort()
if sum(mass[:n]) == sum(mass[-n:]):
    print(-1)
else:
    print(*mass)