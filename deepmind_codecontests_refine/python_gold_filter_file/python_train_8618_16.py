N,K = map(int,input().split())
H = list(map(int,input().split()))
print(sum(K<=h for h in H))