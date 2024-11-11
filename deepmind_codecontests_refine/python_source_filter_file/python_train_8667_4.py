number_of = [0] * 100001
n = int(input())
P = list(map(int, input().split()))
for p in P:
    number_of[p - 1] += 1

four_plus = 0
two_plus = 0

for n in number_of:
    four_plus += n//4
    two_plus += n//2

q = int(input())

print('number_of is {}'.format(number_of))
print('four_plus is {}, two_plus is{}'.format(four_plus, two_plus))

for i in range(q):
    s = input()
    lumber_size = int(s.split()[-1]) - 1
    if s.split()[0] == '-':
        number_of[lumber_size] -= 1
        n = number_of[lumber_size]
        if n % 4 == 3:
            four_plus -= 1
        if n % 2 == 1:
            two_plus -= 1
    elif s.split()[0] == '+':
        number_of[lumber_size] += 1
        n = number_of[lumber_size]
        if n % 4 == 0:
            four_plus += 1
        if n % 2 == 0:
            two_plus += 1
    print('number_of is {}'.format(number_of))
    print('four_plus is {}, two_plus is{}'.format(four_plus, two_plus))
    if four_plus >= 1 and two_plus >= 4:
        print('YES')
    else:
        print('NO')


