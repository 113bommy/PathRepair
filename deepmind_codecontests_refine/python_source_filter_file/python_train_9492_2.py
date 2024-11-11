from math import gcd




def factors(x):
    result = []
    i = 1

    while i * i <= x:

        if x % i == 0:
            result.append(i)

            if x // i != i:
                result.append(x // i)
        i += 1

    return result



n = int(input())
array = list(map(int, input().split()))
if n>1:
 a = gcd(array[0], array[1])
 for i in range(n - 1):
    d = gcd(a, array[i])
    a = d
 print(len(factors(a)))
else:
    print(len(factors(array[0])))