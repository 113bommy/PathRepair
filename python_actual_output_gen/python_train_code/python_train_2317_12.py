t = int(input())

def countdig(n):
    return len(str(n))

def find(n):
    d = n % 10
    ans = countdig(n)
    return int(ans*(ans+1)/2) + 10*(ans-1)
        

for x in range(t):
    n = int(input())
    print(find(n))