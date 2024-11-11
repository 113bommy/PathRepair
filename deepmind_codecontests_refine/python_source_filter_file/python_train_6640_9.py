n = int(input())
a = list(map(int, input().split()))
print("APPROVED" if all(i % 5 == 0 or i % 3 == 0 for i in a if i % 2 == 0 else "DENIED")