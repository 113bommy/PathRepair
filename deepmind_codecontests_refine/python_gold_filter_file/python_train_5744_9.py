def get_sum(t) :
    sum = 0
    while(t > 0) :
        sum += t%10
        t = t // 10
    return sum
n = int(input())
sum = get_sum(n)
if(sum % 4 == 0) :
    print(n)
else :
    for i in range(1, 10) :
        k = n + i
        l = get_sum(k)
        if(l % 4 == 0) :
            print(k)
            break