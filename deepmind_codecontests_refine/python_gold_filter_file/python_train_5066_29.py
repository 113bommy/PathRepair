n, m = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))

dorm = 0
sum_rm = a[dorm]

for le in b:
    while le > sum_rm:
        dorm += 1
        sum_rm += a[dorm]

    print(dorm+1, le - sum_rm + a[dorm])
