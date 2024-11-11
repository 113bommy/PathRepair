def solution(n):
    if n % 2 != 0:
        return 0
    if n % 2 == 0:
        return n

n = int(input())
print(solution(n))
