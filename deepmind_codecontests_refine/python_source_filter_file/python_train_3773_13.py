numcases = int(input())

def solve():
    newlist = []
    a.sort()
    for i in range(alength):
        if i > alength - i:
            return newlist
        if i == alength - i:
            newlist.append(a[i])
            return newlist 
        newlist.append(a[i])
        newlist.append(a[alength - 1 - i])


for n in range(numcases):
    alength = int(input())
    a = list(map(int, input().split(' ')))
    newlist = solve()
    print(*newlist[::-1])