# A. Kuroni and the Gifts

for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    b = list(map(int, input().split()))
    b.sort()
print(' '.join((str(x) for x in a)))
print(' '.join((str(x) for x in b)))
