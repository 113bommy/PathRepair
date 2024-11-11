n, A, B, C, T = input().split()
n, A, B, C, T = int(n), int(A), int(B), int(C), int(T)
ti = [int(i) for i in input().split()]
s = 0
if B >= C:
    s = n * A
else:
    for i in ti:
        s += (5 + (C - B) * (T - i))
print(s)
