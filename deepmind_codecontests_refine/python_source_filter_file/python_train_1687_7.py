def prime(x):
    if(count%x==0):
        return True
    return False


n = int(input())
a = list(map(int, input().split()))
count = 0
b = [0]
for i in range(n):
    if (a[i] == 1):
        b.append(i + 1)
        count += 1
jump = 0
i, j, k, add, inc, dj, tera = 0, 0, 0, 0, 0, 0, 0
mini=999999999999
s=1
if (count == 1):
    print(-1)
else:
    while(s*s<=count):
        i, j, k, add, inc, dj, tera = 0, 0, 0, 0, 0, 0, 0
        while prime(s):
            if(s==1):
                jump=count
            else:
                jump=s
            i = j + 1
            j += jump
            dj = j
            k = i + jump // 2
            inc = 1
            tera = 1
            if (i == count + 1):
                break
            while tera <= jump // 2:
                add += (abs(b[i] - b[k]) + abs(b[dj] - b[k])) * inc
                i += 1
                dj -= 1
                tera += 1
        if(add>0):
            mini=min(mini,add)
        s+=1
    print(mini)