s = input()
n = len(s)
print(5)
print('R', n-1)
n += 1
print('R', n-1)
n+=1
print('L', n-1)
n += n-2
print('R', 2)
n += n-2
print('R', n-1)