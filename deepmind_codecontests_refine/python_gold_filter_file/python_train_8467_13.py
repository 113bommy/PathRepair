fib1 = 0
fib2 = 1
fib0 = 0

fibx = int(input())

while fib2 < fibx:
          fib_sum = fib1 + fib2
          fib0 = fib1
          fib1 = fib2
          fib2 = fib_sum

          
print(0, fibx - fib1, fib1)
