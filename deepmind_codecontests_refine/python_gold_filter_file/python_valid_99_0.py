for _ in range(int(input())):
    n = int(input())
    s = list(input())

    O = s.count('2')
    W = s.count('1')

    if 0 < O < 3:
        print("NO")
    else:
        table = [ ['=' for j in range(n)] for i in range(n) ]

        for i in range(n):
            table[i][i] = 'X'

        for i in range(n):
            if s[i] == '1':
                for j in range(n):
                    if i == j: continue

                    if s[j] == '1':
                        table[i][j] = '='
                    else:
                        table[i][j] = '+'
            else:
                for j in range(n):
                    if i == j: continue
                    
                    if s[j] == '1':
                        table[i][j] = '-'
                    else:
                        table[i][j] = '='

        l = []

        for i in range(n):
            if s[i] == '2':
                l.append(i)

        # print('=>', l)

        for i in range(len(l)):
            next = l[(i+1) % len(l)]

            # print('=>', i, next)

            table[l[i]][next] = '+'
            table[next][l[i]] = '-'
        
        print('YES')
        for row in table:
            print(''.join(row))
                


