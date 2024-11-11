from collections import Counter

N = int(input())
A = list(map(int, input().split()))

numbers = Counter(list(range(not N % 2, N, 2)) * 2)
if N % 2:
    numbers[0] = 1
if Counter(A) == numbers:
    print(pow(2, (N // 2), int(10e9 + 7)))
else:
    print(0)
