X, N = map(int, input().split()) #6,5
p = list(map(int, input().split())) #[4,7,10,6,5]
 
q = [(abs(X-i),i) for i in range(0,101) if not i in p]
q.sort()
 
print(q[0][1])