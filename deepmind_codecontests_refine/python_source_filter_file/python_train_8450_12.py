def main():
    import sys
    #input = sys.stdin.readline

    n = int(input())
    s = list(input())

    p = 0
    a = 0
    b = 0
    for i in range(n//2):
        if s[i] == '?':
            a += 1
        else:
            p += int(s[i])
    
    for i in range(n//2,n):
        if s[i] == '?':
            b += 1
        else:
            p -= int(s[i])
    
    print(p,a,b)

    if a == b:
        if p == 0:
            print('Bicarp')
        else:
            print('Monocarp')
    elif a > b:
        a -= b
        if -p == a*9//2:
            print('Bicarp')
        else:
            print('Monocarp')
    else:
        b -= a
        if p == b*9//2:
            print('Bicarp')
        else:
            print('Monocarp')

if __name__ == '__main__':
    main()