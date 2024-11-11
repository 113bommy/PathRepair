from collections import Counter

input()
s = input()

components = (
    Counter(),
    Counter(),
    Counter((2, )),
    Counter((2, 3)),
    Counter( { 2: 3, 3: 1 } ),
    Counter( { 2: 3, 3: 1, 5: 1 } ),
    Counter( { 2: 4, 3: 2, 5: 1 } ),
    Counter( { 2: 4, 3: 2, 5: 1, 7: 1 } ),
    Counter( { 2: 8, 3: 2, 5: 1, 7: 1 } ),
    Counter( { 2: 8, 3: 4, 5: 1, 7: 1 } ),
)

cn = Counter()
for c in s:
    cn += components[ord(c) - 48]
for n in (7, 5, 3, 2):
    for i in range(cn[n]):
        cn -= components[n]
        print(n, end="")
print()
