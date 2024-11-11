o_case = int(input())
act = list(map(int, input().split()))
case_ind = 0
sol = 0
for x in act:
    if case_ind == 0 and x == -1:
        sol += (-1)
    else:
        case_ind += 1
print(sol)