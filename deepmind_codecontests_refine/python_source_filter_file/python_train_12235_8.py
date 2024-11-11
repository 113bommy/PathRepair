n = int(input())
if n == 2:
    print(24)
    exit(0)
if n == 3:
    print(2 * 4 * 3 * 4 + 4 * 4 * 4)
    exit(0)
 
#print((n - 1) * (4 * 3 ** 2 * 4 ** (n - 4)))
otv = 4 * (6 * 4 ** (n - 3) + (n - 3) * 9 * 4 ** (n - 4))
print(otv)  
