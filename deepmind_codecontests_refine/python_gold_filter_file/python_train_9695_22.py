if __name__ == '__main__':
    n = int(input().strip())
    students = [s for s in map(int, input().strip().split())]

    for i in range(n):
        for j in range(n-i-1):
            if students[j] > students[j+1]:
                t = students[j]
                students[j] = students[j+1]
                students[j+1] = t

    acc = 0
    for i in range(0, n, 2):
        acc += abs(students[i] - students[i+1])

    print(acc)
    # print(students)
