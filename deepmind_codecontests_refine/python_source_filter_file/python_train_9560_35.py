f, t = [int(i) for i in input().split()]
print(len([i for i in range(f, t) if str(i) == str(i)[::-1]]))

