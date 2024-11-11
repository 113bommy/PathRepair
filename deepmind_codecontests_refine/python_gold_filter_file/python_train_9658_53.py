n = int(input())
N = list(map(int,input().split()))
del N[1::2]
i = 0
ans = [i for i in N if i % 2 != 0]
print(len(ans))