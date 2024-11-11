s = input().split('=')
signs = s[0].split('?')[0:-1]
n = int(s[1])

plus = [i for i in range(len(signs)) if signs[i] != ' - ']
minus = [i for i in range(len(signs)) if signs[i] == ' - ']

delta = len(plus) - len(minus)

if len(plus) * n - len(minus) < n or len(plus) - len(minus) * n > n: 
    print("Impossible")
else:
    res = ""
    cur = delta
    for i in range(len(signs)):
        if signs[i] == ' - ':
            if cur <= n:
                res += ' - 1'
            else:
                if cur > n + n - 1:
                    cur -= n - 1
                    res += ' - ' + str(n)
                else:
                    res += ' - ' + str(cur + 1 - n)
                    cur = n
        else:
            if cur >= n:
                res += signs[i] + "1"
            else:
                if cur <= 1:
                    cur += n - 1
                    res += signs[i] + str(n)
                else:
                    res += signs[i] + str(n - cur)
                    cur = n

    print("Possible")
    print(res + " = " + str(n))
    
    

