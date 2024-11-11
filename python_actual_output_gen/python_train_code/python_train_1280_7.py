prime = [2,3,5,7,9,11,13,17,19,23,29,31,37,41,43,47,53]
n,nxt = map(int,input().split())
if prime[prime.index(n)+1] == nxt:
    print("YES")
else:
    print("NO")     