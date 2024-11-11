N = int(input())
ls = [int(input()) for _ in range(5)]
X = min(ls)
print((N+X-1)//X+4)