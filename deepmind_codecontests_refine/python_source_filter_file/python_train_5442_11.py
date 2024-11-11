t = int(input())
for _ in range(t):
    n = int(input())
    ch = str(input())
    if(n % 2):
        odd = 0
        even = 0
        for i in range(0, len(ch), 2):
            if (ord(ch[i]) % 2 == 0):
                even = even + 1
            else:
                odd = odd + 1
        if (odd >= even):
            print(1)
        else:
            print(2)
    else:
        odd = 0
        even = 0
        for i in range(1, len(ch), 2):
            if(ord(ch[i])  % 2 == 0):
                even = even + 1
            else:
                odd = odd + 1
        if(odd <= even):
            print(2)
        else:
            print(1)