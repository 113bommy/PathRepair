q = int(input())
for query in range(q):
    n, a, b = map(int, input().split())
    s = input()
    pod = []
    count = 1
    for i in range(1, n):
        if s[i] != s[i - 1]:
            pod.append(count)
            count = 1
        else:
            count += 1
    pod.append(count)
    wyn = n * a + 2 * n * b + 2 * b
    for i in range(len(pod)):
        if i % 2 == 0:
            if i == 0 or i == len(pod) - 1:
                wyn -= max(0, b * pod[i]-a)
            else:
                wyn -= max(0, b * (pod[i] -1) - 2 * a)
    if len(pod) == 1:
        print((n + 1) * b + n * a)
    else:
        print(wyn)