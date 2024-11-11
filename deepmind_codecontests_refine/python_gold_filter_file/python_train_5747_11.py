n = int(input())

def isPrime(val):
    if(val <2):
        return 0
    n = int(val**0.5)+1
    for i in range(2,n):
        if (val%i) ==0:
            return 0
    return val

def titlePaint(n):
    if n < 2 or isPrime(n):
        print(n)
        return 0
    n1 = int(n**0.5)*2
    prime =[]
    dic = dict()
    for i in range(2,n1):
        while n%i==0:
            prime.append(i)
            if i not in dic:
                dic[i] = 1
            else:
                dic[i]+=1
            n/=i
    dic1 = sorted(dic.items(), key=lambda x: x[1])
    if dic1[0][1] ==1:
        print(1)
        return 0
    if not dic:
        print(1)
        return 0
    if len(dic) ==1:
        print(dic1[0][0])
        return 0
    else:
        print(1)
        return 0
titlePaint(n)
