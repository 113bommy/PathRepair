n = int(input())
a = [int(x) for x in input().split()]
ans = [int(x)%2 for x in a]
if 1 in ans and 0 in ans:
    print(*sorted(a))
else:
    print(*a)