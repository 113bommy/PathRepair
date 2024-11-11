t = int(input())
for i in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    j = 0
    s = set()
    s.add(0)
    while j < len(l)-1 :
        while j < len(l) - 1  and l[j] > l[j+1] :
            j+=1
        s.add(j)
        while j < len(l) - 1 and l[j] < l[j+1] :
            j += 1
        s.add(j)
    s.add(len(l)-1)
    sum = 0
    print(len(s))
    for element in sorted(s):
        print(l[element], end = ' ')