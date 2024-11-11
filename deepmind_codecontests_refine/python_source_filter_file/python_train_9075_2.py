A2=''
A=input()
if '7' not in A or '4' not in A:
    print(-1)
else:
    for i in A:
        if i=='7' or i =='4':
            A2+=i
    if A2.count('7')>A.count('4'):
        print(7)
    elif  A2.count('7')<=A.count('4'):
        print(4)
        