s = input()
e = {'0':'zero','1':'one','2':'two','3':'three','4':'four','5':'five',
    '6':'six','7':'seven','8':'eight','9':'nine'}

tens = ['ten','eleven','twelve','thirteen','fourteen','fifteen',
    'sixteen', 'seventeen', 'eighteen','nineteen']

t = {'2':'twenty','3':'thirty','4':'fourty', '5':'fifty', '6':'sixty',
    '7':'seventy','8':'eighty','9':'ninety'}
    
if len(s)==1:
    print (e[s])
elif s[0] == '1':
    p = int(s[1])
    print (tens[p])
else:
    o = t[s[0]]
    if s[1]!='0':
        o += '-' + e[s[1]]
    print (o)