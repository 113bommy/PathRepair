s = input ()
t = input ()
i = 0
text = ''.join(reversed(s))
if text == t:
    print ('YES')
if text != t:
    print ('NO')
