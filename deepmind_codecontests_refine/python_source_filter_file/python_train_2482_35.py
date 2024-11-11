import re
Sd = input()
T = input()

Sdr = Sd[::-1].replace('?', '.')
Tr = T[::-1]

for i in range(len(Sdr)-len(Tr)+1):
    pattern = Sdr[i:i+len(Tr)]
    if re.match(pattern, Tr):
        print(Sdr.replace(pattern, Tr).replace('.', 'a')[::-1])
        break
else:
    print('UNRESTORABLE')
