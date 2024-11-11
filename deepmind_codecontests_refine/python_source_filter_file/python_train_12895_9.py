import math
def p_l(n):
    for i in range(n-1, 2, -1):
        flag=0
        for j in range(2, int(math.sqrt(i)) + 1):
            if i % j == 0:
                flag=1
        if flag==1:continue
        return i
def p_h(n):
    for i in range(n+1,50022):
        flag=0
        for j in range(2, int(math.sqrt(i)) + 1):
            if i % j == 0:
                flag=1
        if flag==1:continue
        return i   
while 1:
    try:
        n=int(input())
        print(p_l(n),p_h(n))
    except:break
