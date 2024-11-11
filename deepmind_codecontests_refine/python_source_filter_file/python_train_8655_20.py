s = input()
count = 0
for i in s:
    if i == 'a':
        count += 1
if count > len(s)//2:
    print(len(s))
else:
    print(count+1)