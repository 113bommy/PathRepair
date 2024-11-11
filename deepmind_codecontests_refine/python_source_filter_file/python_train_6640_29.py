N = int(input())
A = map(int, input().split())

a = list(filter(lambda i: i%3 != 0 and i%5 != 0 and i % 2 == 0, A)))
print("APPROVED" if len(a) == 0 else "DENIED")