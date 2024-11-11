word = input()

count_ones = 0
cur_word = ''

for c in word:
    if int(c)==1:
        count_ones += 1
        
    if int(c)!=1:
        cur_word = cur_word + c

res = ''
found = 0

for c in cur_word:
    if c==2 and found==0:
        found = 1
        for i in range(count_ones):
            res += '1'
        
        res += '2'
    else:
        res += c

if found==0:
    for i in range(count_ones):
        res += '1'

print(res)