n = int(input())
l = [int(input(i)) for i in range(n)]
print(sum(l)-int(0.5*max(l)))