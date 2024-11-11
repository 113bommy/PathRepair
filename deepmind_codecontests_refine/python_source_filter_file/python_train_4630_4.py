def solve():
    n = int(input())
    list_of_students = [i for i in input().split()]
    one_list = [z for z in range(len(list_of_students)) if list_of_students[z] == '1']
    two_list = [z for z in range(len(list_of_students)) if list_of_students[z] == '2']
    three_list = [z for z in range(len(list_of_students)) if list_of_students[z] == '3']

    first_output = (min(len(one_list), len(two_list), len(three_list)))
    if first_output == 0:
        print("0")
    else:
        print(first_output)
        for i in range(first_output):
            print(f"{one_list[i]} {two_list[i]} {three_list[i]}")
    
solve()
