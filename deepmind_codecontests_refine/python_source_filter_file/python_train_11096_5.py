n = int(input())
a = list(map(int, input().split(' ')))


def sign(n):
    return [1, -1][n % 2]

b1 = [abs(a[i]-a[i-1]) for i in range(1, len(a))]
b1 = [sign(i)*b1[i] for i in range(len(b1))]
b2 = [-x for x in b1]

max_ending_here = b1[0]
max_so_far = b1[0]

for i, x in enumerate(b1):
    if i == 0:
        continue

    if i % 2 == 1:
        max_ending_here += x
    else:
        if x > max_ending_here + x:
            max_ending_here = x
        else:
            max_ending_here += x

    max_so_far = max(max_so_far, max_ending_here)

b1 = b2

max_ending_here = b1[0]
max_so_far2 = b1[0]

for i, x in enumerate(b1):
    if i == 0:
        continue

    if i % 2 == 1:
        max_ending_here += x
    else:
        if x > max_ending_here + x:
            max_ending_here = x
        else:
            max_ending_here += x

    max_so_far2 = max(max_so_far2, max_ending_here)

print(max(max_so_far, max_so_far2))
