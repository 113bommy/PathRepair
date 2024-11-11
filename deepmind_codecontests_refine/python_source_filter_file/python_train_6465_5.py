def B(number, a):
    for i in range(len(a))[:0:-1]:
        a[i] = a[i] - a[i-1]
    appropriate_length = []
    for length in range(1, len(a)):
        if check(a, length):
            appropriate_length.append(length)
    return appropriate_length + [len(a)]
            
def check(a, length):
    iterations = len(a) // length
    if range(len(a) % length):
        iterations += 1
    for x in range(length):
        for index in range(1, iterations):
            if length * index + x < len(a):
                if a[length * index + x] != a[length * (index - 1) + x]:
                    return False
    return True

number = int(input())
a = [int(x) for x in input().split()]

x = B(number, a)
print(len(x))
print(x)