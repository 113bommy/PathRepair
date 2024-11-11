a=input()
a=a.replace(' ','')
l=['a','e','i','o','u']
if a[-2].lower() in l:
    print('yes'.upper())
else:
    print('no'.upper())