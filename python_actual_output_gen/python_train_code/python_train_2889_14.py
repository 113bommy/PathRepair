x=int(input())

def pr(n):
    for p in range(2,n):
        if n%p==0:
            return pr(n+1)
    return n

print(pr(x+1))