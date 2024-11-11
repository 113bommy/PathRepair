__author__ = 'NIORLYS'


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


def sum_of_digits_base_b(a, b):
    if a < b:
        return a
    return sum_of_digits_base_b(a // b, b) + a % b


n = int(input())
sum_of_digits_all_bases = 0
for i in range(2, n):
    sum_of_digits_all_bases += sum_of_digits_base_b(n, i)
print(str(sum_of_digits_all_bases // gcd(sum_of_digits_all_bases, n - 2)) + '/' + str(
    (n - 2) // gcd(sum_of_digits_all_bases, n - 2)))
