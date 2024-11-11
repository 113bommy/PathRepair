
def merge(string, k):
    arr = []
    mrgstring = []
    prevstar = False
    temp = 0
    for i in range(1, len(string)+1):
        
        if string[-1*i] == '*':
            prevstar = True
            temp +=1
        else:
            if prevstar:
                mrgstring.append('*')
                arr.append(k * temp + 1)
                temp = 0
                prevstar = False
            mrgstring.append('a')
    if prevstar:
        mrgstring.append('*')
        arr.append(k * temp + 1)
    #print('arr= ', arr)
    mrgstring.reverse()
    mrgstring = ''.join(mrgstring)
    #arr.reverse()
    return arr, mrgstring

def f(string ,arr, x):
    farr = []
    x= x-1
    #print(string, arr, x)
    for i in arr:
        if i == 0:
            farr.append(0)
        else:
            farr.append(x%i)
            x= int(x/i)
    #print(string, farr, x)
    farr.reverse()
    temp= ''
    j = 0
    for i in string:
        if i == '*':
            temp+= 'b'* int(farr[j])
            j+=1
        else:
            temp+='a'
    print(temp)

t = int(input())
for i in range(t):
    n , k, x = list(map(int, input().split(' ')))
    q = input()
    arr , mstr = merge(q, k)
    f(mstr, arr, x)


