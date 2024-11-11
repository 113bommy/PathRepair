y, w = input('').split(' ')
y = int(y)
w = int(w)
 
if y >= w:
    likely = 6 - y
else:
    likely = 6 - w
 
if likely == 1 :
    print('1/3')
elif likely == 2:
    print('1/2')
elif likely == 3:
    print('2/3')
elif likely  == 4:
    print('5/6')
elif likely == 5:
    print('6/6')
else:
    print('1/6')