INPUT = input().split()
n = int(INPUT[0])
a = int(INPUT[1])
b = int(INPUT[2])
c = int(INPUT[3])

def min(arr):
    min = arr[0]
    for e in arr:
        if e < min:
            min = e
    return min

n = n % 4
if n == 0:
    k = 0
elif n == 1:
    k = min([7*a, 5*a+b, 3*a, a+b, a+3*a, c])
elif n == 2:
    k = min([2*a, 6*a, b, 2*c])
elif n == 3:
    k = min([a, c+b, c+2*a, 3*c])

print(k)
