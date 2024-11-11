def ap(arr):
    ans = 10**20
    for i in [1,0,-1]:
        for j in [1,0,-1]:


            second = arr[1]+ j
            first = arr[0] + i
            d = second - first

            cnt = abs(i)+abs(j)
            prev = second
            for c in range(2,n):
                next_ele = prev + d
                if next_ele - arr[c] == 1:
                    cnt += 1
                elif abs(next_ele - arr[c]) > 1:
                    break
                prev = next_ele
            else:
                ans = min(cnt,ans)
    return -1 if ans == 10**20 else ans
n = int(input())

if n < 3:
    print(0)
else:
    arr = [int(x) for x in input().split()]
    print(ap(arr))



