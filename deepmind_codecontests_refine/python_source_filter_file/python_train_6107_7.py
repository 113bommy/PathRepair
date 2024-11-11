s = input()
if len(s)<7:
    print("NO")
else:
    a=0
    for i in range(len(s)-7):
        x = s[i:i+7]
        if len(set(x))==1:
            a=1
            break
    print('YES' if a==1 else 'NO')