key = 'Bulbasaur'
s = input()
char_count = {}
# init map based on keyword
for ch in key:
    char_count[ch] = 0

for ch in s:
    try:
        char_count[ch] += 1
    except KeyError:
        pass

# 2 u's and 2 a's
char_count['u'] //= 2
char_count['a'] //= 2
#min frequency
#print(char_count)
min_count = 100001
for key, value in char_count.items():
    min_count = min(min_count, value)
print(min_count)
