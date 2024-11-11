def is_beautiful(s):
    if s[0] == '1' and s.count('0') == len(s)-1:
        return True
    return False


def main():    
    n = int(input())
    tmp = input().split()
    nb = ''
    cnt = 0
    
    if '0' in tmp:
        print('0')
        return;

    for num in tmp:
        if not is_beautiful(num):
            nb = num
        else:
            cnt += len(num)-1

    print(nb + '0' * cnt)
    return;


main()
    
