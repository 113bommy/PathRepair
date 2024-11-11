def solution(n, h, listFrnd):
    result = 0
    for i in range(n):
        if listFrnd[i] < h or listFrnd == h:
            result += 1
        elif listFrnd[i] > h:
            result += 2
    return result

n, h = map(int, input().split())
m = list(map(int, input().split()))
print(solution(n,h,m))
