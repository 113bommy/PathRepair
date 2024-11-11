s = input()
n = len(s)
ns = ''
count = 97
if n<26:
    print(-1)
else:
    for i in range(n):
        if count<=122 and ord(s[i])<=count:
            ns+=chr(count)
            count+=1
        else:
            ns+=s[i]

    if len(ns)<26:
        print(-1)
    else:
        print(ns)