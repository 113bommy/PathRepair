no_of_problems = int(input())
no_of_attempted_problems = 0
for i in range(no_of_problems):
    people_who_knows_answer_list = list(map(int, input().split()))
    # print(people_who_knows_answer_list)
    if sum(people_who_knows_answer_list) >= 2:
        no_of_attempted_problems += 1

    print(no_of_attempted_problems)
