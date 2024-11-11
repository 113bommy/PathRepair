def buildPermutation(n,a,b):
    array = [x for x in range(1,n+1)]
    if abs(a-b) >1:
        return [-1]
    if a==b:
        if (n-2)//2 < a:
            return [-1]
        for x in range(a):
            array[2*(x+1)-1],array[(2*(x+1))] = array[(2*(x+1))],array[2*(x+1)-1]
        return array




    else:
        if (n-3)//2 < min(a,b):
            return [-1]
        if a > b:
            array[0],array[1] = array[1],array[0]
            a-=1
            for x in range(a):
                array[2 * (x + 1)], array[(2 * (x + 1)) + 1] = array[(2 * (x + 1)) + 1], array[2 * (x + 1)]
        else:
            array[-1],array[-2] = array[-2],array[-1]
            b-=1

            for x in range(b):
                array[2*(x+1)-1],array[(2*(x+1))] = array[(2*(x+1))],array[2*(x+1)-1]


        return array



t = int(input())
for _ in range(t):
    n,a,b = map(int,input().split())
    ans = buildPermutation(n,a,b)
    for x in ans:
        print(x,end=" ")
    print()
