n,k=map(int,input().split())
l=sorted(int(input().split()) ,reverse=True)
print(sum(l[:k]))