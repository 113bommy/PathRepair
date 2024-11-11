def pwc(a,b,n,s):
    c=s%n
    if(c<=b):
        print('yes')
        return
    elif((a*n)+b >=s):
        print('yes')
    else:
        print('no')
    return
n=int(input())
for i in range(n):
    t=input()
    l= list(map(int,t.split(" ")))
    pwc(l[0],l[1],l[2],l[3])