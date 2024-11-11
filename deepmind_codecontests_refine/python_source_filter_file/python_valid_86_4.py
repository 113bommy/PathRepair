# link: https://codeforces.com/contest/1566/problem/C

for _ in range(int(input())):
    n = int(input())
    a = list(input())
    b = list(input())
    if len(set(a + b)) == 1:
        if "1" in set(a + b):
            print(0)
        else:
            print(1) 
    else:
        ans = 0
        diff = set()
        same = set()
        i = 0
        for first, second in zip(a, b):
            if first != second:
                diff.add(i)
            else:
                same.add(i)    
            i += 1
        i = 0    
        for f, s in zip(a, b):    
            if f == s:
                if i in same and (i-1) in same and a[i-1] != a[i]:
                    ans += 2
                    same.remove(i-1)
                    same.remove(i)
                elif i in same and (i+1) in same and a[i+1] != a[i]:        
                    ans += 2
                    same.remove(i+1)
                    same.remove(i)
                elif i in same and a[i] == '1':
                    if (i-1) in diff:
                        diff.remove(i-1)
                        same.remove(i)
                        ans += 2
                    elif (i+1) in diff:
                        diff.remove(i+1)
                        same.remove(i)
                        ans += 2                 
            i += 1        
        ans += 2*len(diff)
        for i in same:
            if a[i] == "0":
                ans += 1
        print(ans)         