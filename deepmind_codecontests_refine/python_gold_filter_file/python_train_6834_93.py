
n=int(input())
if n==1:
    print (4)
elif n > 36:
    print (-1)

else:
    s=[]
    temp=n
    while True:
        if temp >= 2:
            s.append('8')
            temp-=2
            if temp == 0:
                break                
        elif temp == 1:
            s.append('4')
            temp-=1
            break
        elif temp == 0:
            break
    print (int(''.join(s)))
