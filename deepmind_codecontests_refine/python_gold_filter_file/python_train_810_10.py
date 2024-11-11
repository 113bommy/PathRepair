n,a,b,c = map(int,input().split())

ko = [int(input()) for i in range(n)]
INF = 10**9

def dfs(q,w,e,r):
 	if q == n:
 		 return abs(a-w) + abs(b-e) + abs(c-r) - 30 if min(w,e,r) > 0 else INF
 	re0 = dfs(q+1,w,e,r)
 	re1 = dfs(q+1,w+ko[q],e,r) + 10
 	re2 = dfs(q+1,w,e+ko[q],r) + 10
 	re3 = dfs(q+1,w,e,r+ko[q]) + 10
 	return min(re0,re1,re2,re3)

print(dfs(0,0,0,0))
