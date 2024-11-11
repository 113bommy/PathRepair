n = int(input())
pis = [int(pi) for pi in input().split()]
prev, current_gap, odd, even = 'd', 0, 0, 0
first_gap = ('e', 0)
even_gaps, odd_gaps, any_gaps = [], [], []
for pi in pis:
    if pi == 0:
        current_gap += 1
    elif pi % 2 == 0:
        even += 1
        if prev == 'o':
            any_gaps.append(current_gap)
        elif prev == 'e':
            even_gaps.append(current_gap)
        else:
            first_gap = ('e', current_gap)
        prev = 'e'
        current_gap = 0
    else:
        odd += 1
        if prev == 'e':
            any_gaps.append(current_gap)
        elif prev == 'o':
            odd_gaps.append(current_gap)
        else:
            first_gap = ('o', current_gap)
        prev = 'o'
        current_gap = 0
if prev == 'd':
    first_gap = ('o', current_gap)
ans = 0
odd_gaps.sort()
even_gaps.sort()
any_gaps.sort()
total_even = n//2
total_odd = n - total_even
rem_odd = total_odd - odd
rem_even = total_even - even

for gap in odd_gaps:
    if rem_odd >= gap:
        rem_odd -= gap
    else:
        ans += 2
for gap in even_gaps:
    if rem_even >= gap:
        rem_even -= gap
    else:
        ans += 2
if current_gap > 0:
    if prev == 'o':
        if current_gap > rem_odd:
            ans += 1
        else:
            rem_odd -= current_gap
    elif prev == 'e':
        if current_gap > rem_even:
            ans += 1
        else:
            rem_even -= current_gap

if first_gap[0] == 'o' and first_gap[1] > rem_odd:
    ans += 1
if first_gap[0] == 'e' and first_gap[1] > rem_even:
    ans += 1

for gap in any_gaps:
    ans += 1

print(ans)
