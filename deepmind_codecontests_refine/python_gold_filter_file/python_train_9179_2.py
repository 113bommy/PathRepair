n=int(input())
a=list(str(input()))
c=0
for i in range(0,n,2):
    if a[i]=='a':
        if a[i+1]=='b':
            continue
        else:
            a[i+1]='b'
            c+=1
    else:
        if a[i+1]=='a':
            continue
        else:
            a[i+1]='a'
            c+=1
print(c)
print(''.join(a))