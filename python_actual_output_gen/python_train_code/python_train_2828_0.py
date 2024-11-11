t = int(input())
for i in range(t):
    a, b = input().split()
    a = int(a)
    b = int(b)
    dif = abs(a - b)
    n = int((2*dif) ** 0.5)
   
    for j in range(5):
        S = int(n * (n - 1) / 2)
        if S >= dif and (S - dif) % 2 == 0:
            print(n)
            break
        n += 1