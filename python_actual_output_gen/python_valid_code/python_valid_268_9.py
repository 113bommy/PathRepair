N = int(input())
S_1 = list(input())
S_2 = list(input())



if S_1[0] == S_2[0]:
    res = 3
    flag = 0
    i = 1
else:
    res = 6
    flag = 1
    i = 2

while i != N:
    if S_1[i] == S_2[i]:
        if flag == 0:
            res *= 2 
        else:
            res *= 1
            flag = 0
        i += 1

    else:
        if flag == 0:
            res *= 2
            flag = 1
        else:
            res *= 3
        i += 2
        
ans = res%100000007

print(ans)    