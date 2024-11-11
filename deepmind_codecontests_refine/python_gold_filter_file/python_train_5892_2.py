# B. Odd sum
n = int(input())
vals = input().split()
a_list = [int(val) for val in vals]

# we use max_even, max_odd as the values (and they will be updated when you go through the list)
max_even = None
max_odd = None
#[2, 4, 6, 8, 10, -1], o + e => o, e + o => o
# [1, 3, 5, 7, 9, -2], e + e => e, o + o => e
for a in a_list:
  me = max_even
  mo = max_odd
  if a % 2 == 0: # even
    if mo is not None:  # if mo is None, no need to update
      max_odd = max(mo, mo+a)
    if me is not None:
      max_even = max(me, a, me+a)
    else:
      max_even = a
  else:  # odd
    # 4 cases: mo, me both None, mo None, me not None, mo not None, me None, mo, me both not None
    if me is None and mo is None:
      max_odd = a
    elif me is None: # mo is not None
      max_odd = max(mo, a)
      max_even = mo + a
    elif mo is None: # me is not None
      max_odd = max(me+a, a)
    else:
      max_odd = max(mo, me+a, a)
      max_even = max(me, mo+a)

print(max_odd)
