ABC = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
for i in range(int(input())):
    n = int(input())
    s = list(input())
    error = 0
    for i in range(n//2):
        if s[i] == ABC[0] or s[-i-1] == ABC[0]:
            if s[-i-1] == ABC[1] or s[i] == ABC[1]:
                print('NO')
                error = 1
                break
            elif abs(ABC.index(s[i]) - ABC.index(s[-i-1])) == 1 or  abs(ABC.index(s[i]) - ABC.index(s[-i-1])) >= 3:
                print('NO')
                error = 1
                break
        elif s[i] == ABC[25] or s[-i-1] == ABC[25]:
            if s[-1-i] == ABC[24] or s[i] == ABC[25]:
                print('NO')
                error = 1
                break
            elif abs(ABC.index(s[i]) - ABC.index(s[-i-1])) == 1 or  abs(ABC.index(s[i]) - ABC.index(s[-i-1])) >= 3:
                print('NO')
                error = 1
                break
        else:
            if abs(ABC.index(s[i]) - ABC.index(s[-i-1])) == 1 or  abs(ABC.index(s[i]) - ABC.index(s[-i-1])) >= 3:
                print('NO')
                error = 1
                break
    if error == 0:
        print('YES')