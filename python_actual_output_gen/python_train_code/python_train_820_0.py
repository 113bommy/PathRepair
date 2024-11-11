n = int(input())
a = list(map(int, input().split()))

abs_a = [abs(v) for v in a]
neg = sum(v < 0 for v in a)
if n % 2 == 0 or neg % 2 == 0 or any(v == 0 for v in a):
    print(sum(abs_a))
else:
    print(sum(abs_a) - 2 * min(abs_a))
