s = input()
n = len(s)
for i in range(n-1):
    if i < n-2:
        if s[i] == s[i+1]:
            print(i+1,i+2)
            break
        elif s[i] == s[i+1]:
            print(i+1,i+2)
            break
        else:
            continue
    else:
        if s[i] == s[i+1]:
            print(i+1,i+2)
        else:
            print(-1,-1)