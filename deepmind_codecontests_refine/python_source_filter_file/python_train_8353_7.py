import math
nb_cases = int(input())
while nb_cases > 0:
    nb_cases -= 1

    n, k = [int(x) for x in input().split()]
    s = input()
    nb_letters = [0]*26

    # Compter nb occurences de chaque lettre
    for pos in range(n):
        nb_letters[ord(s[pos]) - 97] += 1
    min_val = 0

    for x in range(1, n+1):
        y = x/max(1, math.gcd(k%x, x))
        new_letters = [int(nb_letter/y) for nb_letter in nb_letters]
        nb = sum(new_letters)
        if nb*y >= x:
            min_val = x
print(min_val)
