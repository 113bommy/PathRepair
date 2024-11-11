line = input()
vowels = 'AEIOUY'

start = 0
limit = 0
for i in range(len(line)):
    if line[i] in vowels:
        if i - start > limit:
            limit = i - start
        start = i
print(limit)
