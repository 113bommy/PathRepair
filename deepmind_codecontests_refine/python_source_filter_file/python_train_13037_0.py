from sys import stdin
input = stdin.readline

def answer():

    prefix = [[0 for i in range(n + 1)] for j in range(26 + 1)]

    for i in range(1 , n + 1):

        for j in range(1 , 26 + 1):
            prefix[j][i] = prefix[j][i - 1]

        prefix[a[i - 1]][i] += 1

    ans = 1
    for x in range(1 , 26 + 1):

        i , j , v1 , v2 = 0 , n - 1 , 0 , 0 
        while(i < j):

            v1 = prefix[x][i + 1]

            while(i < j and v1 != v2):
                v2 = prefix[x][n] - prefix[x][j]
                j -= 1

            if(i >= j):break

            value = 0
            for v in range(1 , 26 + 1):
                value = max(value , prefix[v][j + 1] - prefix[v][i + 1])

            ans = max(ans , v1 + v2 + value)
                
            i += 1

    return ans
                
        
    
for T in range(int(input())):

    n = int(input())

    a = list(map(int,input().split()))

    print(answer())
