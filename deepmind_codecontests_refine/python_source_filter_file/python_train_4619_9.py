number_of_problems = int(input())

solutions = 0
for i in range(number_of_problems):
    confidence = [int(x) for x in input().split(" ")]
    if sum(confidence) == 3:
        solutions += 1

print(solutions)
