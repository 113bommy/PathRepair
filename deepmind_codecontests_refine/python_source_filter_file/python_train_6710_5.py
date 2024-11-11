n = int(input())
initial = input()[::-1]
final = '{0:04b}'.format(int(initial, 2) + 1)[-n:]
print(sum(list(map(lambda x: 1 if x[0] != x[1] else 0, zip(final, initial)))))
