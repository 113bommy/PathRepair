n = int(input())
array = list(map(int, input().split()))
a = 1000000001
amount = 0
for i in range(len(array)):
    c = array[n - i - 1]
    if c < a:
        amount = amount + c
        a = c
    elif c >= a > 0:
        amount = amount + a - 1
        a = a - 1
print(amount)