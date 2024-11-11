n=input()
for i in range(len(n)-1,-1,-1):
    x=int(n[i])
    a=''
    if x < 5:
        a+='0-|'
    else:
        a+='-0|'
        x-=5

    t=''
    for j in range(x):
        t+='0'
    a+=t+'-'+('0'*(4-x))
    print(a)

    