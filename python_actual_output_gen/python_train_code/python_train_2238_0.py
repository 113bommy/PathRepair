n = int(input())
A = list(map(int , input().split()))
B = list(map(int, input().split()))
if A == B :
    print(-1)
else :
    count = count_1 = 0
    for idx, val in enumerate(A):
        if val == 1 and B[idx] == 0:
            count += 1
        elif B[idx] > val:
            count_1 += 1
    if count == 0 :
        print(-1)
        exit()
    print((count_1 // count) + 1 if count_1 > count else count)



