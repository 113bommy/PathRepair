n, m = map(int,input().split())


min_answer = n + max(m - n, 0)

max_answer = n + max(0, m - 1)

if n == 0 and m == 0:
    print("0 0")
    exit(0)

if n == 0 :
    print("Impossible")
    exit(0)
    

print(min_answer, max_answer)
