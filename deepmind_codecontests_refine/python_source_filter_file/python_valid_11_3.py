


# f = open("inp.txt")


t = int(input())
# t = int(f.readline())


def key1(a):
    return a[ind], (-1)*sum(a)

for qwe in range(t):
    
    
    n = int(input())
    # n = int(f.readline())
    l = [0]*n
    
    for i in range(n):
        s = input()
        # s = f.readline()[:-1]
        tl = [0]*5
        for j in s:
            if j == 'a':
                tl[0] += 1
            elif j == 'b':
                tl[1] += 1
            elif j == 'c':
                tl[2] += 1
            elif j == 'd':
                tl[3] += 1
            elif j == 'e':
                tl[4] += 1
        tl = tuple(tl)
        l[i] = tl
    
    ans = [0]*5
    
    
    for ind in range(5):
        
        b = [0]*5
        l.sort(key=key1, reverse=True)
        tempans = 0
        
        for i in range(n):
            
            for j in range(5):
                b[j] += l[i][j]
                
            if 2 * b[ind] <= sum(b):
                for j in range(5):
                    b[j] -= l[i][j]
            else:
                tempans += 1
                
        ans[ind] = tempans
    
    print(max(ans))


























