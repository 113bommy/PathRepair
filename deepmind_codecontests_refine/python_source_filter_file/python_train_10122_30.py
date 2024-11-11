
q = int(input())
for _ in range(q):
    a, b = map(int, input().split())
    print(2 if (a-b) & 1 else 1) if a > b else print(0) if not b-a else print(1 if (b-a) & 1 else 1)