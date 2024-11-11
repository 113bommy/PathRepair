s = input()
ans = 'No'
c = s.find('C')
if c != -1:
	f = s[c:].find('F')
    if f != -1:
      ans = 'Yes'
print(ans)