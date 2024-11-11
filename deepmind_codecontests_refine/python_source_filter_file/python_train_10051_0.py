def main():
    A, B = input().split('e')
    B = int(B)
    s1, s2 = A.split('.')
    if B == 0:
        if s2 == '0':
            print(s1)
        else:
            print(A)
        return
    print(s1, end='')
    for i in range(B):
        if i < len(s2):
            print(s2[i], end='')
        else:
            print(0, end='')
    s2 = s2[i+1:]
    if s2:
        print('.' + s2[i+1:])

main()
    
