w = input().lower()

l = len(w)

s = ''

for i in range(l):
    if w[i] not in 'aeiou':
        s = s + '.' + w[i]
        
print(s)