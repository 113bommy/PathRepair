def main():
    minimum_problem , number_of_george_problems = [int(i) for i in input().split()]
    require_problems = [int(i) for i in input().split()]
    george_problems = [int(i) for i in input().split()]
    
    count = 0
    check_point = 0
    for i in range(0, minimum_problem):
        for j in range(check_point, number_of_george_problems):
            if george_problems[j] >= require_problems[i]:
                count += 1
                check_point = j
                break
        

    return minimum_problem - count

print(main())