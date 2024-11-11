n = int(input())
l = sorted(list(map(int, input().split())),reverse=True)
print(sum(l[1:len(l)-n:2]))