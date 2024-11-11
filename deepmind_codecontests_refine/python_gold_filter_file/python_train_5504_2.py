import sys
N=int(input())
for i in range(N):
    a=input()
    b=input()
    len_a=len(a)
    len_b=len(b)
    c=[]
    kuriage=0
    if(len_a>=len_b):
        for i in range(len_b):
            c.append((kuriage+int(a[len_a-1-i])+int(b[len_b-1-i]))%10)
            kuriage=(kuriage+int(a[len_a-1-i])+int(b[len_b-1-i]))//10
        for i in range(len_b,len_a):
            c.append((kuriage+int(a[len_a-1-i]))%10)
            kuriage=(kuriage+int(a[len_a-1-i]))//10



    else :
        for i in range(len_a):
            c.append((kuriage+int(a[len_a-1-i])+int(b[len_b-1-i]))%10)
            kuriage=(kuriage+int(a[len_a-1-i])+int(b[len_b-1-i]))//10
        for i in range(len_a,len_b):
            c.append((kuriage+int(b[len_b-1-i]))%10)
            kuriage=(kuriage+int(b[len_b-1-i]))//10

    if(kuriage==1):
        c.append(1)

    if(len(c)>=81):
        print('overflow')

    else:
        for i in c[::-1]:
            print(i,end='')
        print('')