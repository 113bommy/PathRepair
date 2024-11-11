# Given integer n
inArr = input().split()
n = int(inArr[0])
k = int(inArr[1])

# if the last digit of the number is non-zero, she decreases the number by one;
# if the last digit of the number is zero, she divides the number by 10 (i.e. removes the last digit). 

for i in range(k):
    if n % 10 != 0:
        n = n - 1
    else:
        n = n / 10

print(n)