from collections import Counter
n = int(input())
l = sorted([(i,j) for i,j in enumerate(map(int, input().split()) , 1)] , key = lambda x : x[1])

tmp = [str(i[0]) for i in l]
ans = [' '.join(tmp)]
for i in range(1,n):
    if l[i-1][1] == l[i][1]:
        tmp[i] , tmp[i-1] = tmp[i-1] , tmp[i]
        ans.append(' '.join(tmp))
        if len(ans) > 4:
            break
            
print('YES\n'+'\n'.join(ans) if len(ans) >= 3 else 'NO')
