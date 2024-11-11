def chkupper(password):
    for i in password:
        if(i.isupper()):
            return True
    return False
def chklower(password):
    for i in password:
        if(i.islower()):
            return True
    return False
def chkdigit(password):
    for i in password:
        if(i.isdigit()):
            return True
    return False




password =input()
#print(password)
#print(len(password))
if(len(password)>5):
    #print('a',len(password))
    if(chkupper(password)):
        #print('b')
        if(chklower(password)):
            #print('c')
            if(chkdigit(password)):
                print('Correct')
            else:
                print('Too weak')
        else:
            print('Too weak')
    else:
        print('Too weak')
else:
    print('Too weak')
