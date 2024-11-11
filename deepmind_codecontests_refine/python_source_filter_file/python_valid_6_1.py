import sys

# from io import BytesIO
# from os import read, fstat
# input = BytesIO(read(0, fstat(0).st_size)).readline
# from os import path
#
# if path.exists("Input.txt"):
#     sys.stdin = open("Input.txt", "r")
#     sys.stdout = open("Output.txt", "w")
input = lambda: sys.stdin.readline().rstrip()

# input = sys.stdin.buffer.readline


# SOME SHIT
# map(int, input().split())
# sys.stdout.write("") ~ |
def solve_tc():
    n, m = map(int, input().split())
    main = [0 for _ in range(n+1)]
    ans = m
    for i in range(m):
        tmp1, tmp2 = map(int, input().split())
        if not main[min(tmp1, tmp2)]:
        	ans-=1
        main[min(tmp1, tmp2)] = main[min(tmp1, tmp2)] +1
       
       
    for _ in range(int(input())):
        k = list(map(int, input().split()))
        if k[0] == 1:
            tmp1, tmp2 = k[1], k[2]
            if not main[min(tmp1, tmp2)]:
                ans-=1
            main[min(tmp1, tmp2)] = main[min(tmp1, tmp2)] +1
        elif k[0] == 2:
            tmp1, tmp2 = k[1], k[2]
            a, b = main[tmp1], main[tmp2]
            main[min(tmp1, tmp2)] = main[min(tmp1, tmp2)] -1
            if not main[min(tmp1, tmp2)]:
        	    ans+=1
        elif k[0] == 3:
            print(ans)










solve_tc()