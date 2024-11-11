a, b = [int(x) for x in input().split()]
print(len([i for i in range(a,b+1) if str(i) == str(i)[::-1]]))
