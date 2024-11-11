from sys import stdin

numbers = stdin.readline().split('+')
numbers.sort()
print('+'.join(numbers))