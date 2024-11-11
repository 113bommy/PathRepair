import math
t = int(input())
while t>0:
    t = t-1
    n,y = map(int,input().split())
    list_arr = list(map(int,input().split()))
    a = math.ceil(sum(list_arr)/y)
    res = map(lambda x : math.ceil(x/y), list_arr)
    b = sum(list(res))
print(min(a,b),max(a,b))