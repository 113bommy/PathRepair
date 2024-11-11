def digitsum(n):
    s = str(n)
    array = list(map(int, s))
    return sum(array)

def list_to_num(l):
    s = 0
    for i in range(len(l)):
        s += l[i]*pow(10,i)
    return s

k = int(input())

def func(a):
    n = a+1
    if a == 0:
        return 1
    elif n/digitsum(n)==1:
        return n
    else:
        s = str(n)
        array = list(map(int, s))[::-1]
        if len(list(set(array)))==1 and list(set(array))[0]==9:
            n =list_to_num(array)+1
            s = str(n)
            array = list(map(int, s))[::-1]
        min = pow(10,15)
        ans = 0
        for i in range(len(array)):
            for j in range(array[i]+1,10):
                array[i] = j
                temp = list_to_num(array)/digitsum(list_to_num(array))
                if temp < min:
                    min = temp
                    ans = list_to_num(array)
        return ans


n = 0
for i in range(k):
    print(func(n))
    n = func(n)