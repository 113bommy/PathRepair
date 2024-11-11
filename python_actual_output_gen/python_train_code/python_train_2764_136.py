n = int(input())
print(sum(list(map(lambda x: x/100, map(int, input().split()))))/n)
