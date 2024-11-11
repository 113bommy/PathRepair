N = int(input())
AN = list(map(int,input().split()))

AN.sort()
print(sum(AN[1:]))