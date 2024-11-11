n = int(input())
s = input()
c, i = 0, 0
while i < n - 3:
        if s[i] == 'x' and s[i + 1] == 'x' and i < n:
                i += 2
                while i < n and s[i] == 'x':
                        c += 1
                        i += 1
        else:
                i += 1
print(c)