a=input()
n=a.split('1')
b=['4','44']
k=0
if n[0]!='1':
    print('NO')
else:
    for i in n:
        if i!='':
            if i not in b:
                k+=1
                print('NO')
                break
    if k==0:
        print('YES')
