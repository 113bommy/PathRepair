for _ in range(int(input())):
    s = input()
    i = 0
    req = 0
    ans = []
    while i < len(s):
        if s[i:i+5] == "twone":
            req += 1
            ans.append(i+2)
            i += 5
        elif s[i:i+3] == "one" or s[i:i+3] == "two":
            req += 1
            ans.append(i+1)
            i += 3
        else: 
            i += 1
    print(req)
    for a in ans:
        print(a, end=' ')
    print()

