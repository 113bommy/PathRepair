def findString(n, k):
    rank = 1
    b1 = 2
    b2 = 1
    while rank != k:
        difference = 0
        difference = b1-(b2+1)
        if (rank + difference) > k:
            if b1 == b2+1:
                b1+=1
                b2=1
            else:
                b2+=1
            rank+=1
        else:
            b1+=1
            b2=1
            rank+=difference
    newList = ["a"] * n
    newList[n-b1] = "b"
    newList[n-b2] = "b"
    return ''.join(newList)

if __name__ == "__main__":
    t = int(input())
    for i in range(t):
        n, k = map(int, input().split())
        print(findString(n, k))
