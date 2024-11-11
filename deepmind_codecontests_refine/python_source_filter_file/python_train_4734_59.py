s = list(input())
mas = ['A', 'E', 'I', 'O', 'U', 'Y']
while True:
    if s.count(' ') == 0:
        break
    s.remove(' ')
print(['NO', 'YES'][s[len(s) - 2] in mas])