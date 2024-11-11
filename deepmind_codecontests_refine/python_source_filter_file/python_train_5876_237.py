s = input ()
t = input ()
i = 0
text = ''.join(reversed(s))
if text == t:
    print ('Yes')
if text != t:
    print ('No')
