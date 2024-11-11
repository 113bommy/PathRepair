def solution(n):
    if n % 2 != 0:
        return 0
    if n % 2 == 0:
        return 2**(n//2)

n = int(input())
print(solution(n))
