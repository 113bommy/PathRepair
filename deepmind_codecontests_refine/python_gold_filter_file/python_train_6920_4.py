input = input().split(" ")
n = int(input[0])
m = int(input[1])
print (min(n, m, (n + m) // 3))