_, dna = input(), input(); l = [dna.count(x) for x in set(dna)]
print(l.count(l[0]) ** len(dna) % (10**9 + 7))