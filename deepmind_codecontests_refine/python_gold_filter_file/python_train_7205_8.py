for _ in range(int(input())):
    l = list(map(int, input().split()))
    print('YES' if sum(l) % 3 == 0 and sum(l) / 3 >= max(l[:3]) else 'NO')