


s = input()


count = 0



i = 0

while i < len(s):

    
    if int(s[i]) % 3 == 0:

        count += 1
        i += 1

    elif i < len(s)-1 and (int(s[i:i+2]) % 3 == 0 or int(s[i+1]) % 3 == '0' ):

        count += 1
        i +=2

    elif i < len(s)-2 and ( int(s[i+1:i+3]) % 3 == 0 or int(s[i:i+3]) % 3 == 0 or s[i+2] == '0') :

        count += 1
        i += 3

    else:

        i +=1

    

print(count)



