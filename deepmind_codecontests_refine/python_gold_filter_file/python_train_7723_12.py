def answer():
    n = int(input())
    while n:
        a = int(input())
        b = [int(x) for x in input().split()]
        b.sort()
        m=len(b)
        i=0
        while i<len(b):
            if b[i]>=m:
                done=1
                print(m)
                break
            else:
                i+=1
                m-=1

        if not done:
            print(1)
        n-=1
answer()