
n = int(input())
a = 0
while n % 7:
     a += 1
     n -= 4
print('4'*a + '7'*(n // 7) if n >= 0 else -1)

