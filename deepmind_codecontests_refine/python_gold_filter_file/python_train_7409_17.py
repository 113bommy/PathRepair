len,add = map(int, input().split())

liste = list(map(int,input().split()))
num = 0
i = 0

while(i < len - 1):
    if ( liste[i] < liste[i + 1]):
        i +=1
    elif( liste[i] == liste[i + 1]):
        liste[i + 1] += add
        i += 1
        num +=1

    else:
        val = (liste[i] - liste[i + 1])/add
        m = int(val)
        if(val >= m): m += 1
        liste[i + 1] += m * add
        num += m
        i += 1

print(num)


