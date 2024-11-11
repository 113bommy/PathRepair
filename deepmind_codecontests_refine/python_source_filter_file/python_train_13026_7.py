n,k = list(map(int, input().split()))
a  = list(map (int, input().split()))
ans = []
d = {}
time_k = 1
f = True
for i in a:
    if i not in d :
        d[i] = [time_k]
        ans.append(time_k)
    else:
        if time_k in d[i]:
            for j in range(1,k+1):
                if j not in d[i]:
                    d[i].append(j)
                    ans.append(j)
                    time_k = j
                    break
                else:
                    f = False
        else:
            d[i].append(time_k)
            ans.append(time_k)
    if time_k == k:
        time_k = 1
    else:
        time_k +=1

if f and len(set(ans)) == k:
    print('YES')
    for i in ans:
        print(i,end=' ')
else:
    print('NO')


