x = int(input())
while x > 0:
    x = x - 1
    j = int(input())
    l = list(map(int, input().split()))
    s = "NO"
    l = list(set(l))
    if len(l) == j:
        s = "YES"
    print(s)