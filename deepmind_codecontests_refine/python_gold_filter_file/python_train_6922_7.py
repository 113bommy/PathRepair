n_a, n_b = tuple(map(int, input().split()))
k, m = tuple(map(int, input().split()))
a = list(map(int, input().split()))[:k]
b = list(map(int, input().split()))[-m:]


num_a = a[-1]
num_b = b[0]

if num_a < num_b:
    print ('YES')
else:
    print ('NO')