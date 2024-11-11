num = int(input())
word = input()

count_Z = word.count('z')
count_E = word.count('e')
count_R = word.count('r')
count_O = word.count('o')
count_N = word.count('n')
one = min(count_O, count_N, count_E)

count_O -= one
count_N -= one
count_E -= one
zero = min(count_Z, count_E, count_R, count_O)
print('1 ' * one, '0' * zero, sep='')
