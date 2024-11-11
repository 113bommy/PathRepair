line=input()
for i in range(int(line)):
    n=input()
    sum=0
    c=0
    ar=[]
    for j in range(len(n)):
        ar.append(n[j])
        sum+=int(n[j])
        if n[j]=='0':
            c+=1
    if c==len(n):
        print('red')
    elif sum%3!=0 or c==0:
        print('cyan')
    elif len(n)<4:
        if '2' in ar or '4' in ar or '6' in ar or '8' in ar:
            print('red')
        else:
            print('cyan')
    else:
        print('red')