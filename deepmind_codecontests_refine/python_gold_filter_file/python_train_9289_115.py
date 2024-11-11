while 1:
        ch=input()
        if ((ch[0]=="A")and(ch[1:].isnumeric())and(len(ch)==7)):
                break
        else:
                continue


print(int(ch[6])%2)
