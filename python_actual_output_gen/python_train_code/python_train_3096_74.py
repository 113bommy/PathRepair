'''input
4
'''
n = int(input()[-1])
s = 1 + 2**n + 3**n + 4**n
print(s % 5)
