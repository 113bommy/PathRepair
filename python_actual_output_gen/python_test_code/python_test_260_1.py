def solve(numbers):
    odd_indexes = []
    for i in range(0, len(numbers)):
        if numbers[i] % 2 == 0:
            print(1)
            print(i)
            return
        else:
            odd_indexes.append(i)
            if len(odd_indexes) == 2:
                print(2)
                print("{} {}".format(odd_indexes[0], odd_indexes[1]))
                return
    print(-1)


numberOfTestCases = int(input())
for u in range(0, numberOfTestCases):
    length = int(input())
    temp = input().split(" ")
    test = list(map(int, temp))
    solve(test)
