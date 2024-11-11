from string import ascii_lowercase
t=int(input())
for i in range(t):
    n=int(input())
    a=list(int(num) for num in input().split())
    l=['a']*51
    print(''.join(l))
    for z in range(0,len(a)):
        for x in ascii_lowercase:
            if x not in l:
                c=x
                break
        l2=l[:a[z]]+[c]*(51-a[z])
        print(''.join(l2))
        l=l2