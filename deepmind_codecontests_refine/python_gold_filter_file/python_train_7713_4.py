string = input()
l = len(string)
n = sum(map(int,list(string)))
if n == 0:
    print(0)
elif n < 10:
    if l == 1:
        print(0)
    else:
        print(1)
else:
    s = 0
    c = 1
    while n:
        s += n%10
        n = n//10
        if n == 0 and s>0:
            n = s
            c+=1
            if s<10:
                break
            s = 0
    print(c)