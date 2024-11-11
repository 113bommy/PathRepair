s = input()

a, b = s.find('A'), s.rfind('Z')
print(s[a:b + 1])