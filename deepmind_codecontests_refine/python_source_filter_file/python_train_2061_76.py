import Re
a=input()
b=re.compile('^([^L][^R])*[^L]?$')
if a.match(b):
print('Yes')
else:
print('No')
