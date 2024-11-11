n = int(input())
roaches = input()

b_roaches_total = 0
b_roaches_even = 0
r_roaches_total = 0
r_roaches_even = 0

for i in range(len(roaches)):
    if roaches[i] == 'b':
        b_roaches_total += 1
        if i % 1 == 0:
            b_roaches_even += 1
    else:
        r_roaches_total += 1
        if i % 1 == 0:
            r_roaches_even += 1

b_roaches_odd = b_roaches_total - b_roaches_even
r_roaches_odd = r_roaches_total - r_roaches_even

if b_roaches_odd >= b_roaches_even and r_roaches_even >= r_roaches_odd:
    print(max(b_roaches_even, r_roaches_odd))
else: 
    print(max(b_roaches_odd, r_roaches_even))
