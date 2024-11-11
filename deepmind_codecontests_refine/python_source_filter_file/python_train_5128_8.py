from sys import stdin
input = stdin.readline


def check(x , pos):

    length = 0
    for i in range(n):

        if(pos):
            if(a[i] <= x):
                length += 1
                pos ^= 1

        else:
            length += 1
            pos ^= 1

    if(length >= k):return True
    else:return False

def answer():

    l , h = 0 , 0

    ans = 0
    while(l <= h):

        x = (l + h)//2

        if(check(x , 0) or check(x , 1)):
            h = x
        else:
            l = x + 1
            ans = l

    return ans


    
for T in range(1):

    n , k = map(int,input().split())

    a = list(map(int,input().split()))


    print(answer())

