#計数ソート
n = int(input())
a = list(map(int, input().split()))

def countSort(a):
    N = max(a)
    c = [0]*(N+2)
    b = [0]*len(a)
    for i in a:
        c[i] += 1
    for i in range(1,len(c)):
        c[i] += c[i-1]
        
    for i in a:
        b[c[i]-1] = i
        c[i] -= 1
    print(b)

countSort(*a)
