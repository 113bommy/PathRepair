


def check(s):
    i = 0
    while i < len(s) - 2:
        x = ''.join(sorted(s[i:i + 3]))
        if 'ABC' == x:
            return True
        i += 1

    return False



if __name__=='__main__':
    s = input().strip()

    if check(s):
        print('Yes')
    else:
        print('No')




