string = input()
# string = "vvvovvv"
# string = "vvovooovovvovoovoovvvvovovvvov"

prev = ""

n_string = []
for item in string:
    if item == prev and item == 'v':
        n_string.append('w')
    elif item == 'o':
        n_string.append(item)
    prev = item

counter = 0
prev = []
for item in n_string:
    if item == 'w':
        counter += 1
    prev.append(counter)

counter = 0
ahead = []
for item in reversed(n_string):
    if item == 'w':
        counter += 1
    ahead.append(counter)

counter = 0
n = len(n_string)
for i in range(n):
    if n_string[i] == 'o':
        counter += (prev[i] * ahead[n - i - 1])
# print(n_string)
# print(prev)
# print(ahead)
print(counter)
