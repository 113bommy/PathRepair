from collections import Counter

n, k = map(int, input().split())
words = list()
for i in range(n):
    words.append(input())
real = input()

# Get only lengths of the passwords.
words = [len(i) for i in words if len(i) <= len(real)]

# Get all lenths of all passwords and their quantity.
c = Counter(words)
sorted_c = sorted(c)  # Sort by key

# Assign a quantity of passwords with the same length as real's,
#  i.e. retrieve the specific value from the dictionary.
real_value = c[len(real)]

# Get the quantity of passwords with a length less than real's
all_but_real = 0
for i in range(len(sorted_c) - 1):
    all_but_real += c[sorted_c[i]]

tmin = 1 + all_but_real + (all_but_real // k) * 5

if (real_value + all_but_real) % 2 != 0:
    tmax = (real_value
            + all_but_real
            + ((real_value + all_but_real) // k) * 5)
else:
    tmax = (real_value
            + all_but_real
            + ((real_value + all_but_real - 1) // k) * 5)

if k == 1:
    if (real_value + all_but_real) % 2 != 0:
        tmax = (real_value
                + all_but_real
                + ((real_value + all_but_real - 1) // k) * 5)
    else:
        tmax = (real_value
                + all_but_real
                + ((real_value + all_but_real - 2) // k) * 5)

print(tmin, tmax)
