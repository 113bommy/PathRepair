n = int(input()) + 1
while(True):
    if(len(set(str(n))) == 4):
        print(n)
        break
    else:
        n += 1