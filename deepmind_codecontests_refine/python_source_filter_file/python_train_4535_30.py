##n = int(input())
##a = list(map(int, input().split()))
##print(" ".join(map(str, res)))

n = int(input())
x = list(map(int, input().split()))

x.sort()
print(x[int(n/2)-1])