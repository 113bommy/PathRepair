from itertools import groupby, zip_longest
for i in range(int(input())):
    ans = "yes"
    a = [list(i[1]) for i in groupby(input())]
    b = [list(i[1]) for i in groupby(input())]
    for i, j in zip_longest(a, b, fillvalue=["."]):
        if i[0] != j[0] or len(j) < len(i):
            ans = "NO"
    print(ans)
            
        
    