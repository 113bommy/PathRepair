


n  = int(input())

t = list(map(int,input().split()))


t.sort()

maa = 10**15
ans = maa
c=1

h=0

while True:

    temp =0

    for i in range(n):
        temp+= abs(c**(i) - t[i])

        if c >= 100:
            print(ans)
            h+=1
            break
    if h>0:
        break
    ans= min(ans, temp)
    c+=1


