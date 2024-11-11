N = int(input())
ls = [int(input()) for range(5)]
X = min(ls)
print((N+X-1)//X+4)