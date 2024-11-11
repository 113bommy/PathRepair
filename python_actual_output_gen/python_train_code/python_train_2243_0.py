n = int(input())
for k in range(n):
    nn = input()
    a = list(map(int, input().split()))
    ans = [0]
    for i in range(1, len(a)):
        st = 1
        an = 0
        while st <= a[i - 1]:
            if ((a[i - 1] / st) % 2 - (a[i] / st) % 2) == 1:
                an += st
                a[i] += st
            st *= 2
        ans.append(an)
    print(*ans, sep=' ')