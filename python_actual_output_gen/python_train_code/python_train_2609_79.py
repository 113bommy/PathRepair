n,k = map(int,input().split())
h = [int(input()) for i in range(n)]
h.sort()
print(min([b-a for a,b in zip(h[:k],h[-k:])]))