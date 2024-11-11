def answer():
    n = int(input())
    s = map(int, input().split())
    s = sorted(s)

    for i in range(0, max(s)+1):
        s1 = []
        for j in s:
            s1.append(j^i)
        if s == sorted(s1):
            return(i)
    else:
        return(-1)

for _ in range(int(input())):
    print(answer())