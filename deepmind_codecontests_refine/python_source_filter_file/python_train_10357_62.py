n = int(input())
A = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
     "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
B = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
if n < 20:
    print(A[n])
else:
    a = (n // 10) - 2
    b = n % 10
    if b == 0:
        print(B[a])
    else:
        print(B[a],"-", A[b])
