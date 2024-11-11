def A(students_number, voices):
    k = max(voices)
    while True:
        result = 0
        for i in voices:
            result += k - i - i
        if result < 0:
            k += 1
        else:
            return k

students_number = int(input())
voices = [int(x) for x in input().split()]
print(A(students_number, voices))