zero = 'zero'
one = 'one'
k_zero = 0
k_one = 0
n = int(input())
s = input()
for i in range(n):
    if s[i] == 'z':
        k_zero += 1
    if s[i] == 'n':
        k_one += 1
for i in range (k_one):
    print(1, end="")
for i in range (k_zero):
    print(0, end="")