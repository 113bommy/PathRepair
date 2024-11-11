n = int(input())
s = input()
zeros = 0

for a in s:
    if a == 0:
        zeros += 1
if (n - zeros) == zeros:
    print(2)
    print(s[0], s[1:]) 
else:
    print(1)
    print(s)