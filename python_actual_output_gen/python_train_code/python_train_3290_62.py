test_cases = int(input())

inp = [input().split(" ") for i in range(test_cases)]

ratings = [(int(i[1]) , int(i[2])) for i in inp]

can_handle = [i for i in ratings if i[0] >= 2400 and i[0] > i[1]]

if len(can_handle) >= 1 :
    print("YES")
else :
    print("NO")
