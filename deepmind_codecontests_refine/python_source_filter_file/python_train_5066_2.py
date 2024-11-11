

n, m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]

def letters(a, b):
    i, rooms = (0, 0)
    for letter in b:
        if (letter - rooms) > a[i]:
            i += 1
            rooms += a[i-1]
        print(i + 1, letter - rooms)

letters(a, b)
