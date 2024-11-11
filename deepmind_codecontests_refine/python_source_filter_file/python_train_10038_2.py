"""
    loop through the comp_req
        loop through the complexity
    cause both are sorted so the next element always > the one before
"""

a = input()
b = input()
c = input()

min_prob, num_prob = [int(i) for i in a.split()]
complexity_req = [int(i) for i in b.split()]
complexity = [int(i) for i in c.split()]

j = 0
count = 0
for i in range(min_prob):
    while j < num_prob and complexity[j] < complexity_req[i]:
        j += 1
    if j < num_prob and complexity[j] >= complexity_req[i]:
        continue
    else:
        count += 1
print(count)