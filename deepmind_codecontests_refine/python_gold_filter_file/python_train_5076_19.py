def f(b, sequence: list):
    slices = []
    odd_count = 0  # нечетное
    even_count = 0  # четное
    for i, v in enumerate(sequence):
        if v % 2:
            even_count += 1
        else:
            odd_count += 1
        if even_count == odd_count:
            if i + 1 < len(sequence):
                slices.append(abs(v - sequence[i+1]))
            odd_count = even_count = 0
    slices.sort()
    slices_count_before_b = 0
    for v in slices:
        if v <= b:
            b -= v
            slices_count_before_b += 1
        else:
            break
    return slices_count_before_b

# r = f(4, [1,2,5,10,15,20])
# assert r == 1, r
# r = f(100, [1,2,5,10,15,20])
# assert r == 2, r
# r = f(100, [1,2,3,4,5,6])
# assert r == 2, r
# r = f(10, [1,3,2,4])
# assert r == 0, r
# r = f(1, [6,9,4,4,1,1])
# assert r == 0, r
# r = f(2, [2,2,9,3,6,9,10,7,7,6])
# assert r == 2, r
# r = f(4, [2,2,9,3,6,9,10,7,7,6])
# assert r == 2, r
# r = f(1, [2,2,9,3,6,9,10,7,7,6])
# assert r == 1, r
# r = f(10, [1,2])
# assert r == 0, r


in_n, in_b = [int(i) for i in input().split()]
in_seq = [int(i) for i in input().split()]
print(f(in_b, in_seq))