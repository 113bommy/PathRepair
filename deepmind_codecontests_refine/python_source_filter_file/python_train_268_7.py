def zhadnik(n, k, M, t):
    ans = 0
    i = 0
    while i < k and M > t[i]:
        temp = M // t[i]
        if temp <= n:
            ans += temp
            M -= temp * t[i]
        else:
            ans += n
            M -= n * t[i]
        
        i += 1
    return ans

n, k, M = map(int, input().split()) # n, k <= 45
t = list(map(int, input().split()))
t.sort()

all_task_time = sum(t) # время на решение целой задачи (всех подзадач)

# если бы не было премии за решение всей задачи - тогда только жадник
ans = zhadnik(n, k, M, t)

# попробуем улучшить результат за счет премии за решение l полных задач:
l = 1

while l <= n and M - all_task_time * l >= 0:
    res = l * (k + 1) + zhadnik(n - l, k, M - all_task_time * l, t)
    if res > ans:
        ans = res
    l += 1

print(ans)