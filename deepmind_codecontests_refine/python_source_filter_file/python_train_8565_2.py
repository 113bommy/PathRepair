T = int(input())
for t in range(T):
    n = int(input())
    A = [int(x) for x in input().split()]
    B = [int(x) for x in input().split()]
    max_wait = 0
    driving_time = 0
    nA = []
    nB = []
    # tuple (a, b)
    both = []
    # clean from bad drives
    for i in range(n):
        if B[i] >= A[i]:
            max_wait = max(max_wait, A[i])
        else:
            nA.append(A[i])
            nB.append(B[i])
            both.append((A[i], B[i]))
    
    both.sort(key=lambda tup: tup[0] - tup[1], reverse=True)
    # print(both)
    
    for tup in both:
        if tup[0] <= max_wait:
            del tup
            continue
        if driving_time + tup[1] < max(max_wait, tup[0]):
            driving_time += tup[1]
        else:
            max_wait = max(max_wait, tup[0])
    # print(both)
    print(max(max_wait, driving_time))
    
