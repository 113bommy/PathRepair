s = input()
m = len(s)
if '2' in s:
    index = s.find('2')
    s = ''.join(list(sorted(list(s[:index])))) + s[index:].replace('1', '').ljust(m - index, '1')
else:s = ''.join(list(sorted(list(s))))
print(s)