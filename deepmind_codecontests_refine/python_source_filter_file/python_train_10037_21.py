def main():
    # c = input()
    c = "aabbbaaaa"
    c = list(c)
    v=c[0]
    k = 1
    for i in range(1,len(c)):
        if(v == c[i]):
            k +=1
            if(k>2):
                c[i] = ' '
        else:
            v=c[i]
            k=1
    c = [i for i in c if i != ' ']
    for i in range(len(c)-1):
        if(c[i]==c[i+1]):
            if(i+3 < len(c) and c[i+2]==c[i+3]):
                c[i+3] = ' '
    c = [i for i in c if i != ' ']
    return c

print(''.join(main()))