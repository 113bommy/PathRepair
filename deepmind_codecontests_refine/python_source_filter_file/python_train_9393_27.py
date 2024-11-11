test_cases = int(input())
inputs = []

for i in range(test_cases):
    s = int(input())
    inputs.append(s)

for i in inputs:
    if i == 1:
        print(-1)

    elif i > 1:
        print(int("2"*i)+1)
