a,b,c = map(int, input().split())
t = a
q, r = divmod(t, b)
for i in  range(1, 10**5+1):
    q, r = divmod(r*10, b)
    #print(q)
    if q == c:
        print(i)
        exit()
else:
    print(-1)
