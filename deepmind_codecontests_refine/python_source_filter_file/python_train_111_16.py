def solution(n,a):
    i=max(a)
    while i*n<2*sum(a):
        i+=1
    return i
def answer():
    n = int(input())
    a = [int(x) for x in input().split()]
    print(solution(n,a))
answer()