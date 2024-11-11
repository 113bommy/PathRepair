

def alphaNum(x):
    if x == 'a':
        return -1
    return 1

def numAlpha(x):
    if x == -1:
        return 'a'
    return 'b'

n = int(input())

s = list(map(alphaNum,list(input())))

k = 0
l = 0
for i in range(0,n,2):
    l = s[i] + s[i + 1]
    if l != 0:
        if s[i+1] == 1:
            s[i+1] = -1
        else:
            s[i+1] = 1
        k += 1

s = list(map(numAlpha,s))
print(k)
for i in range(n):
    print(s[i],end ='')
