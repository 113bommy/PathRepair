import math
import bisect



MAX_D = 100000+7
# MAX_D = 20
seq = [float(math.ceil((n*n)/2.0)) for n in range(MAX_D)]


t = int(input())

for g in range(1, t+1):

    dk = input().split(" ")
    d = float(dk[0])
    k = float(dk[1])

    if d == k:
        print("Ashish")
        continue

    ratio = (d*d)/(k*k)


    # marker = bisect.bisect_left(seq, ratio, lo=1, hi=len(seq)) - 1

    left = 1
    right = len(seq) - 1
    marker = None
    prec = 20
    while left <= right:
        middle = math.floor((left + right)/2)
        # print(f"l: {left} m: {middle} r: {right} seq[middle]: {seq[middle]:.30f} ratio: {ratio:.30f}")
        if seq[middle] == ratio:
            marker = middle
            break
        elif(seq[middle] < ratio):
            marker = middle            
            left = middle + 1
        elif (seq[middle] > ratio):
            right = middle - 1



    # n_marker = -1
    # prec = 20
    # for i in range(1, len(seq)):
    #     if(round(seq[i], prec) <= round(ratio, prec)):
    #         n_marker = i
    #     else:
    #         break
    

    # if n_marker != marker:
    #     print("-----------------------------")
    #     print(f"index: {marker}")
    #     print(f"new index: {n_marker}")
    #     print(f"d: {d} k: {k}")

    if(marker % 2 == 0):
        print("Utkarsh")
    else:
        print("Ashish")
