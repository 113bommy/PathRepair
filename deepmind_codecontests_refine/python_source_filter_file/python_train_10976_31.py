n,k = map(int, input().split())

a = list(map(int, input().split()))

print(int(len([i for i in a if i < 5 - k])/3))