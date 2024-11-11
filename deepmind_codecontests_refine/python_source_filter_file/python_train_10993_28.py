from sys import stdin
from math import log2

n = int(stdin.readline().strip())

batch_number = int(log2((n+5)/5))
batch_first = (5 * 2 ** batch_number) - 5
current_in_batch = n - batch_first
person = int(current_in_batch / 2 ** batch_number)
# print(batch_number, current_in_batch, person)
print(['Sheldon', 'Leonard', 'Penny', 'Rajesh', 'Howard'][person])
