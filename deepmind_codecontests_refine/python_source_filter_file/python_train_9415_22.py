
#n songs
# d limit
# t = minutes for n songs
n,d = map(int,input().split())
t = list(map(int,input().split()))
if(((n-1)*10 + sum(t))<d):
    s = sum(t)
    dif = d-s
    print(dif//5)
else:
    print(-1)


