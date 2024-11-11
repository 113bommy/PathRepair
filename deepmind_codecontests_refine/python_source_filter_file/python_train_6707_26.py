s = input()
print(min(s.count('e') // 3, s.count('t'), s.count('i'), max(0, (s.count('n') - 1) / 2)))