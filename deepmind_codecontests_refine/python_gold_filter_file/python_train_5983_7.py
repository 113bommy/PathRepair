def findMirror(counter, n):
    return n - counter - 1


def checkForward(counter, n, st):
    total = 0
    done = [0] * (n + 1)
    mid = int(n/2)
    high = 0
    if counter<=mid:
        high = mid
    else:
        high = n-1
    i = 0
    steps = 0
    while counter <= high:
        i=i+1
        if done[counter] == 0:
            mirror = findMirror(counter, n)
            temp = abs(ord(st[counter]) - ord(st[mirror]))
            total = total + min(temp,26-temp)
            done[mirror] = 1
            if min(temp,26-temp)!=0:
                steps=i
        # print(counter, total)
        counter = counter + 1
    return total,max(steps-1,0)


def checkBack(counter, n, st):
    total = 0
    done = [0] * (n + 1)
    mid = int(n/2)
    low = 0
    if counter <= mid:
        low = 0
    else:
        low = mid
    i = 0
    steps = 0
    while counter >= low:
        i=i+1
        if done[counter] == 0:
            mirror = findMirror(counter, n)
            temp = abs(ord(st[counter]) - ord(st[mirror]))
            total = total + min(temp, 26 - temp)
            done[mirror] = 1
            if min(temp,26-temp)!=0:
                steps=i
        # print(counter, total)
        counter = counter - 1
    return total,max(steps-1,0)


def main():
    n, start = list(map(int, input().split()))
    st = input()
    a,left = checkBack(start-1,n,st)
    b,right = checkForward(start-1,n,st)
    startVal = abs(ord(st[start - 1]) - ord(st[findMirror(start - 1, n)]))
    startVal = min(startVal, 26 - startVal)
    print(a+b+left+right+min(left,right)-startVal)

main()
