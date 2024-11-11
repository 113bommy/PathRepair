s = input()
A = set()
for i in s:
    A.add(i)
Range = {}

for item in A:
    key = s.find(item)
    Range[item] = key
    for i in range(key+1,len(s)):
        if s[i] == item :
            if i - key > Range[item] :
                Range[item] = i - key
            key = i
    if len(s) - key > Range[item] :
            Range[item] = len(s) - key
min = 1000000000
for item in Range.values():
    if item < min :
        min = item
print(item)