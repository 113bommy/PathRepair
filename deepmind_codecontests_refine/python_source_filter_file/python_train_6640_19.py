n = int(input())
A = list(map(int, input().split()))
print("APPROVED" if all(a&1 | a%3==0 | a%5==0 for a in A) else "DENIED")