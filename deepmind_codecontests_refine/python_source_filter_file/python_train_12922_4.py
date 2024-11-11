def calculate_inestability(ls):
    return max(ls) - min(ls)


n = int(input())
seq = list(map(int, input().split()))

if n == 2:
    print(0)
else:
    minimum = seq[0]
    idx_min = 0
    maximum = seq[-1]
    idx_max = n-1
    for idx, i in enumerate(seq):
        if i <= minimum:
            minimum = i
            idx_min = idx
        elif i >= maximum:
            maximum = i
            idx_max = idx
    if minimum == maximum:
        print(0)
    else:
        del seq[idx_max]
        ins_max = calculate_inestability(seq)
        seq.insert(idx_max, maximum)
        del seq[idx_min]
        ins_min = calculate_inestability(seq)
        if ins_max >= ins_min:
            print(ins_min)
        else:
            print(ins_max)