N = int(input())
a = [int(i) for i in input().split()]
sum_a = sum(a)
b = []
c = 0
for i in range(N-1):
    c += a[i]
    b.append(abs(2*c-sum_a))
print(min(b))
