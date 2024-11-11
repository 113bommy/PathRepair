n = int(input())
a = [int(i) for i in input().split()]
parlament_count = sum(a)
coalence_ind = [1]
coalence_sum = a[0]
if a[0] >= parlament_count//2 + 1:
    print(1)
    print(1)
else:
    for i in range(1, len(a)):
        if a[0] >= 2*a[i]:
            coalence_sum += a[i]
            coalence_ind.append(i + 1)
    if coalence_sum >= parlament_count // 2 + 1:
        print(len(coalence_ind))
        print(*coalence_ind)
    else:
        print(0)