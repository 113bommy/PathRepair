s = input()
print(len(s) - 1 - s[::-1].index('Z') - s.index('A'))