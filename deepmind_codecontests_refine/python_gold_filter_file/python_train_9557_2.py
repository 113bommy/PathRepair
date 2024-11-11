n = int(input())
pow2s = [2**item for item in range(32)]
if n in pow2s:
    print("No")
    exit()
print("Yes")
print(n+1, n+2)
for i in range(3, n+1, 2):
    print(1, i)
    print(1, i - 1)
    print(i, n + i - 1)
    print(i - 1, n + i)
if n % 2 == 0:
    upper = 1 << (n.bit_length() - 1)
    lower = n ^ 1 ^ upper
    print(upper, n)
    print(lower, n + n)