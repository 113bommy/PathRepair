n = int(input())
s = '$' + input()
t = ''
i = 1
j = 1
if n==1:
    print(s[1])
else:    
    while i<n:
        t += s[i]
        i += j + 1
        j += 1
    print(t)