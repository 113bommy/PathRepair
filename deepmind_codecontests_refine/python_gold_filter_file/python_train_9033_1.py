n,k=map(int,input().split())
H=list(map(int,input().split()))
H.sort(reverse = True)
print(sum(H[k:n]))