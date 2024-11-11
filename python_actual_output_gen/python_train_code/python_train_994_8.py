t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    s1 = set()
    s2 = set()
    counter = 0
    for k in range(n):
        now = list(map(int, input().split()))
        for j in range(m):
            if now[j] == 1:
                s1.add(j)
                s2.add(k)
                counter += 1
    s1 = len(s1)
    s2 = len(s2)
    if min(s1, s2) % 2 == 0:
        print("Vivek")
    else:
        print("Ashish")
    