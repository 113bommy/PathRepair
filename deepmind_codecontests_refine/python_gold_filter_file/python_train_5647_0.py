#codeforces - Little Artem

t = int(input())

while t != 0:
    n, m = map(int, input().split())
    if n*m %2 != 0:
        for i in range(n):
            result =''
            for j in range(m):
                if (j+i) %2 == 0:
                    result += 'B'
                else:
                    result += 'W'
            print(result)
    else:
        result =''
        for i in range(n):           
            for j in range(m):
                if j == 1 and i == 1:
                    result += 'B'
                    if j == m-1 and i != n-1:
                        result+='\n'
                    continue
                if (j+i) %2 == 0:
                    result += 'W'
                else:
                    result += 'B'
                if j == m-1 and i != n-1:
                    result+='\n'
        print(result)
    t -= 1