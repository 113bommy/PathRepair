n = int(input())
fib1 = 1
fib2 = 0
temp = 0
retString = ""
fibonacci = []
if n == 1:
    fibonacci.append(0)
else:
    while n > fib1:
        temp = fib2
        fib2 = fib1 + fib2
        fib1 = temp
        fibonacci.append(fib2)

for i in range(1, n+1):
    if i in fibonacci:
        retString += "O"
    else:
        retString += "o"
print(retString)