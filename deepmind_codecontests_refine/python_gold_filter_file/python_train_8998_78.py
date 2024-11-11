'''input
7854
'''
n = int(input()) % 4
s = 1 + 2**n + 3**n + 4**n
print(s % 5)
