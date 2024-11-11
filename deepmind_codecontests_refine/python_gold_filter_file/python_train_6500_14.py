
def calculate_stones_value(num_of_elements, elements, num_of_test_cases, test_cases):

    arrenged_elements = sorted(elements)

    sum_elements = [0] * num_of_elements
    sum_arrenged_elements = [0] * num_of_elements

    for i in range(-1, -num_of_elements-1, -1):

        if i == -1:
            sum_elements[i] = elements[-1]
            sum_arrenged_elements[i] = arrenged_elements[-1]
            continue
        
        sum_elements[i] = elements[i] + sum_elements[i+1]
        sum_arrenged_elements[i] = arrenged_elements[i] + sum_arrenged_elements[i+1]

    
    for i in range(num_of_test_cases):
        result = 0

        question = test_cases[i][0]
        initial = test_cases[i][1]
        final = test_cases[i][2]

        if question == 1:
            if final == num_of_elements:
                result = sum_elements[initial-1]
            else:
                result = sum_elements[initial-1] - sum_elements[final]
        else:
            if final == num_of_elements:
                result = sum_arrenged_elements[initial-1]
            else:
                result = sum_arrenged_elements[initial-1] - sum_arrenged_elements[final]

        print(result)


if __name__ == "__main__":
    
    num_of_elements = int(input())
    elements = input().strip().split()
    elements = [int(i) for i in elements]
    num_of_test_cases = int(input())
    test_cases = []

    for i in range(num_of_test_cases):
        test_cases.append(input().strip().split())
        test_cases[i] = [int(j) for j in test_cases[i]]
    
    calculate_stones_value(num_of_elements, elements, num_of_test_cases, test_cases)