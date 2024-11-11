def solution(a,b):
    #print(b)
    for x in b:
        if x!=4 and x!=7:
            return "NO"
    #print(b[:int(len(b)/2)])

    if sum(b[:int(len(b)/2)])!=sum(b)/2:
        return "NO"
    return "YES"
def answer():
    a=int(input())
    b = [int(x) for x in list(input())]
    print(solution(a,b))
answer()
