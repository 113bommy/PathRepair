i = int(input())
j = list(map(int, input().split(" ")))
print("{:.12f}".format((sum(j)/i*100)))
