import sys

content = sys.stdin.readlines()
elements = content[1]
unique = set(elements.split(' '))
unique.discard('0')
unique.discard('')
print(len(unique))
