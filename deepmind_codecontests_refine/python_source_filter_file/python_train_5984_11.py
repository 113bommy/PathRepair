S = input()

freqs = dict()
for letter in S:
    if letter in freqs:
        freqs[letter] += 1
    else:
        freqs[letter] = 1

doubles = 0
for f in freqs.values():
    doubles += f

print(doubles)