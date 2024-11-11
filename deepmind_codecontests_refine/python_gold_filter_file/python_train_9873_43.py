N,A,B = map(int,input().split())
a = 0
for i in range(1,N+1):
    s = sum(map(int,str(i)))
    if A <= s <= B:
        a += i
print(a)