t = int(input())
length = []
tests = []

for i in range(t):
    length += [int(n) for n in input().strip().split()]
    tests += [[int(n) for n in input().strip().split()]]

for test in tests:
    answer = [test[0]]
    i = 1
    while len(answer) < len(test)/2:
        if test[i] not in answer:
            answer += [test[i]]
        i += 1
    print(answer)