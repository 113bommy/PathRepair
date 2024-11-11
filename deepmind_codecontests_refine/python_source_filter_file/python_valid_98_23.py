t = int(input(""))
for i in range(t):
    n = int(input(""))
    s = input("")
    start = s[0]
    end = 'a' if start == 'b' else 'b'
    res = s.find(end)
    if res == -1:
        print(-1)
    else:
        print(res, res+1)

