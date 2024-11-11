n = int(input())
a = list(map(int, input().split()))
a.sort()
diff, s, i, val = set(), set(), 0, 0
while i<n-1:
    diff.add(a[i+1] - a[i])
    i += 1
diff = list(diff); diff.sort()
if n == 1: 
    print(-1)
elif n == 2:
    s.add(a[0] - diff[0])
    s.add(a[1] + diff[0])
    if diff[0]%2 == 0:
        s.add(a[0] + diff[0]//2)
    print(len(s))
    s = list(s); s.sort()
    for ele in s:
        print(ele, end = " ")
else:
    if len(diff) == 1:
        s.add(a[0] - diff[0])
        s.add(a[n-1] + diff[0])
    elif len(diff) == 2:
        if diff[0] == diff[1]//2:
            i = 0
            while i<n-1:
                if a[i+1] - a[i] == diff[1]:
                    s.add(a[i] + diff[0])
                    val += 1
                i += 1 
    if val > 1:
        print(0)
    else:
        print(len(s))
        s = list(s); s.sort()
        for ele in s:
            print(ele, end = " ")
                    
