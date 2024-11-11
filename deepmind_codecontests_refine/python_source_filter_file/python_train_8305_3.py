N = int(input())
P = list(map(int, input().split()))

index_lst = [0] * N
for index, i in enumerate(P):
    index_lst[i - 1] = index

left_next_Index = list(range(-1, N - 1)) + [-1]
right_next_Index = list(range(1, N + 1)) + [N]
# print (left_next_Index)
# print (right_next_Index)
ans = 0
for i in range(1, N):
    index = index_lst[i - 1]
    # print (i, index)
    l1 = left_next_Index[index]
    l2 = left_next_Index[l1]
    r1 = right_next_Index[index]
    r2 = right_next_Index[r1]
    # print ('l1 =', l1, ' l2 =', l2, ' r1 =', r1, ' r2 =', r2)
    ans += i * ((index - l1) * (r2 - r1) + (r1 - index) * (l1 -l2))

    left_next_Index[r1] = l1
    right_next_Index[l1] = r1

print (ans)