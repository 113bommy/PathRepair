def solve():
    s = input()
    l = len(s)
    i = 0
    ans = []
    while i < l:
        if i + 5 <= l:
            # print(s[i:i+5])
            if s[i:i+5] == "twone":
                ans.append(i+3)
                i += 4
                continue
        if i + 3 <= l:
            if s[i:i+3] == "two" or s[i:i+3] == "one":
                ans.append(i+2)
                i += 2
        i += 1
    print(len(ans))
    for a in ans:
        print(a, end = " ")
    print()
        
 
 
 
t = int(input())
while t > 0:
    solve()
    t -= 1