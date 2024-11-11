

def Solve(k, m, n, V):
    a = None
    m = m-1
    k = min(m, k)
    #print('>', k, m, n)
    for i in range(k+1):
        b = max(V[i], V[n-1-k-(m-k)])
        for j in range(m-k+1):
            left = i + j
            right = n-1 - (k-i) - (m-k-j)
            #print('.', left, right)

            b = min(b, max(V[left], V[right]))

        #print(b)
        
        if a == None:
            a = b
        else:
            a = max(a, b)

    return a

if __name__ == '__main__':
    cases = int(input())
    for i in range(cases):
        n, m, k = map(int, input().split())
        V = list(map(int, input().split()))

        print(Solve(k, m, n, V))



