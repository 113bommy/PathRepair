a = input()
b = input()

if a==b:
    print('YES')
elif len(a)!=len(b):
    print('NO')
else:
    a = [i for i in a]
    b = [i for i in b]
    if(sorted(a)==sorted(b)):
        c=0
        for i in range(len(a)):
            if a[i]!=b[i]:
                c+=1
                if c>1:
                    print('NO')
                    break
        else:
            print('YES')
    else:
        print('NO')