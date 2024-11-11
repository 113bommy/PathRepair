__author__ = "runekri3"

N = int(input())
M = list(map(int, input().split()))
R = list(map(int, input().split()))

total_days = 100000
days_you_washed = 0

for D in range(total_days):
    for i in range(N):
        if D % M[i] == R[i]:
            days_you_washed += 1
            break

print(days_you_washed / total_days)
