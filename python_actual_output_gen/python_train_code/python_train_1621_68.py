N=input()
ls=[int(s) for s in input().split()]
ls.sort()
print(ls[N//2]-ls[N//2-1])