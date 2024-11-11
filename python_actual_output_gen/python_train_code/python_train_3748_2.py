n = int(input())
s = input()
cnt = 0
for i in range(100,1000):
    p = '{}'.format(i)
    s2 = s
    for j in range(3):#indexのループ
        if s2.find(p[j]) == -1:
            break
        s2 = s2[s2.find(p[j]) +1:]
    else:
        cnt+=1
print(cnt)