input();
al=[int(i) for i in input().split()]
al.sort()[::-1]
print(sum(al[::2])-sum(al[1::2]))