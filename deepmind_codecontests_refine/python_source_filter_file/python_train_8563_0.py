number = int(input())

def get_sum(num) :
    return sum([i for i in num])

def convert(num , base) :
    rem = []
    while num >= base :
        rem.append(num % base)
        num //= base
    return (rem + [num % base])[::-1]

num = sum([get_sum(convert(number , b)) for b in range(2 , number)])
den = len(range(2 , number))

def simplest_form(num , den) :
    return max([i for i in range(1 , den + 1) if num % i == 0 and den % i == 0])

cancel = simplest_form(num , den)

print(str((num) / cancel) + "/" + str((den / cancel)))
