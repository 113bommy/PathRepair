n,k,s = map(int,input().split())
ans = [s]*k + [(s%(2)+1) for i in range(n-k)]
 
print(" ".join(map(str,ans)))