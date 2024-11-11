n = int(input())
a = sorted(list(map(int, input().split())))
m = max(a)
print(m,min(a,key=lambda x:abs(m-x*2)))