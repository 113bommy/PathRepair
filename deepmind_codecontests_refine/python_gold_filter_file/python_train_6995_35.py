lst=[4,7,44,47,74,77,444,447,477,474,777,774,744,747]
c=14
n=int(input())
for i in range(c):
    if n%lst[i]==0:
        print('YES')
        break
else:
    print('NO')