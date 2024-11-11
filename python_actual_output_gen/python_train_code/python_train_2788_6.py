while True:
    n = int(input())
    if n == 0:
        break
    score = {"A": 0, "B": 0}
    for _ in range(n):
        A, B = map(int, input().split())
        if A > B:
            score["A"] += A
        elif A < B:
            score["B"] += B
        else:
            score["A"] += A
            score["B"] += B
    print(score["A"], score["B"])