from sys import stdin, stdout
n = int(stdin.readline())
prices = {}
for i in range(n):
    s = stdin.readline().strip()
    if int(s[0]) == 1:
        ind, a, b, w = map(int, s.split())
        while a != b:
            if a > b:
                if (a, a // 2) not in prices:
                    prices[(a, a // 2)] = w
                else:
                    prices[(a, a // 2)] += w
                a //= 2
            else:
                if (b, b // 2) not in prices:
                    prices[(b, b // 2)] = w
                else:
                    prices[(b, b // 2)] += w                
                b //= 2
    else:
        ind, a, b = map(int, s.split())
        cnt = 0            
        while a != b:
            if a > b:
                if (a, a // 2) in prices:
                    cnt += prices[(a, a // 2)]                
                a //= 2
            else:
                if (b, b // 2) in prices:
                    cnt += prices[(b, b // 2)]                
                b //= 2
        stdout.write(str(cnt) + '\n')
#1