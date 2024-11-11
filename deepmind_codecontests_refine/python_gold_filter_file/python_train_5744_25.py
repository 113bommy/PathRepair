n = int(input())
for i in range(n,n+7):
    b = i
    val = 0
    while i > 0:
        val += i%10
        i = i//10
    if val%4==0:
        print(b)
        break