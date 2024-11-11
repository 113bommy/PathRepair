from itertools import accumulate

t = int(input())
for _ in range(t):
    n = int(input())
    jars = [1 if i == '1' else -1 for i in input().split()]
    left = list(accumulate(jars[0:n]))
    right = list(accumulate(jars[2*n-1:n-1:-1]))
    left_dict = {0: 0}
    right_dict = {0: 0}
    for i in range(n):
        left_dict[left[i]] = i+1
        right_dict[right[i]] = i+1
    ans = 0
    for k in left_dict:
        if -k in right_dict:
            ans = max(ans, left_dict[k]+right_dict[-k])
    print(2*n-ans)
