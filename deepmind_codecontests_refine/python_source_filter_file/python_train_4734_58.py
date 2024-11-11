s = input()
u = s.replace("?"," ")
v = u.replace(" ", "")
l = len(v)
vowel =['a','e','i','o','u','y','A','E','I','O','U','Y']
if v[l-1] in vowel:
    print('Yes')
else:
    print('No')
