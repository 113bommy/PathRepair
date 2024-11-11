def solution():

    n, t = [int(i) for i in input().split()]

    q = list(input())

    for i in range(t):
    
        i = 0

        while i<len(q)-1:

            if q[i] == 'B' and q[i+1] == 'G':

                q[i], q[i+1] = q[i+1], q[i]

                i += 1

            i += 1

    print(q)
solution()
