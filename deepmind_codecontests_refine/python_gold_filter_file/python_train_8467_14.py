ser = [0, 1]
def fib(n):
    i = 1
    while i < n:
        ser.append(i)
        i = ser[-1] + ser[-2]
    if i != n:
        return -1
    else:
        return len(ser)

n = int(input())
a, b, c = 0, 0, 0
ans = 1
if n == 0:
    ans = 1
elif n == 1:
    a = 1
elif n == 2:
    a = 1
    b = 1
elif n == 3:
    a = 1
    b = 1
    c = 1
else:
    ans = fib(n)
    if ans != -1:
        a = ser[ans-2]
        b = ser[ans-2]
        c = ser[ans-3]
if ans != -1:
    print(a, b, c)
else:
    print("I'm too stupid to solve this problem")
    