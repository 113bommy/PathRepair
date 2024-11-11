for _ in range(int(input())):
    a, b = map(int, input().split())
    print("YES" if b-a < a else 'NO')