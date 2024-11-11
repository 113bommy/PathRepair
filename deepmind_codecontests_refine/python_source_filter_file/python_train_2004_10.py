def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))
import bisect
#python3 codeforces_1360G.py
def yuh(N,M,A,B):
    times = 1
    for a in range(1,M + 1):
        if (a * M) % N == 0:
            times = a
            break
    original_start = 0
    original_end = A - 1
    for i in range(N):
        start = (i * times + original_start) % M
        end  = (i * times + original_end) % M
        for j in range(M):
            if end < start:
                if j >= start or j <= end:
                        
                    value = 1

                else:
                    value = 0
                if j == M - 1:
                    print(value)
                else:
                    print(value, end = "")
            else:
                if j >= start and j <= end:
                    value = 1

                else:
                    value = 0
                if j == M - 1:
                    print(value)
                else:
                    print(value, end = "")

test_cases = inp()
for test in range(test_cases):
    N,M,A,B = inlt()
    if N * A != M * B:
        print("NO")
        continue
    else:
        print("YES")
        yuh(N,M,A,B)