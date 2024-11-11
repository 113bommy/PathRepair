n = int(input())
i = 0
j = 0
while n>0:
    if n%7==0:
        j = n//7
        ans = ['4'] * i + ['7'] * j
        print("".join(ans))
        break
    n-=4
    i+=1
else:
    print(-1)