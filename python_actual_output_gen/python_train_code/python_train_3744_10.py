n = int(input())
inpt = input()
L = inpt.count('L')
R = inpt.count('R')
U = inpt.count('U')
D = inpt.count('D')


count = 0
count += min(L, R) + min(U, D)
print (count)
