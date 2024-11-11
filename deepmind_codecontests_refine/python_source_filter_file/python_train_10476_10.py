def solve(s):
    count = 0
    n = len(s)

    for i in range(n-2):
        if s[i] == 'Q':
            for j in range(i+1,n-2):
                if s[j] == 'A':
                    for k in range(j+1,n-2):
                        if s[k] == 'Q':
                            count += 1
    return count
        
s = input()
print(solve(s))
