n = int(input())
s = list(input())
d = {}
for char in s:
    if char not in d.keys():
        d[char] = 1
    else:
        d[char] += 1

odd = []
even = []
for char in d.keys():
    for i in range(d[char] // 2):
        even.append(char)
        even.append(char)
    for i in range(d[char] % 2):
        odd.append(char)
# print(len(even), len(odd))
if len(odd) <= 1:
    x = ''.join([even[i] for i in range(1, len(even), 2)])
    y = ''.join(odd)
    print(1)
    print(x + y + x[::-1])
elif len(even) % len(odd) == 0 and (len(even) // len(odd)) % 2 == 0 and (len(even) // len(odd)) > 0:
    print(len(odd))
    x = []
    ratio = len(even) // len(odd)
    indx = 0
    for i in range(len(odd)):
        tail = ''
        while len(tail) < ratio // 2:
            tail += even[indx]
            indx += 2
        x.append(tail + odd[i] + tail[::-1])
    print(' '.join(x))
else:
    ratio = len(even)//len(odd)
    max_length = 1
    for i in range(1,ratio+1,2):
        if (len(even)+len(odd)) % i == 0 and max_length < i:
            max_length = i
    parts = (len(even) + len(odd))//max_length
    print(parts)
    x = []
    indx = 0
    for i in range(len(odd)):
        tail = ''
        while len(tail) < max_length // 2:
            tail += even[indx]
            indx += 2
        x.append(tail + odd[i] + tail[::-1])
    middle = []
    for i in range(parts - len(odd)):
        middle.append(even.pop())
    for i in range(len(middle)):
        tail = ''
        while len(tail) < max_length // 2:
            tail += even[indx]
            indx += 2
        x.append(tail + middle[i] + tail[::-1])
    print(' '.join(x))
    