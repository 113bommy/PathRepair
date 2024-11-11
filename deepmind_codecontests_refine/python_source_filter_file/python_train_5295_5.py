s=input()
if s==s[::-1]:
    opt=len(s)-3 
    if opt&1: 
        print('First')
    else:
        print('Second')
else: 
    opt=len(s)-2 
    if opt&1:
        print('First')
    else:
        print('Second')