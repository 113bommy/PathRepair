
n, m = [int(w) for w in input().split()]

cnt = [0] * ( n  ) 
for val in [ int(w) for w in input().split() ]:
    cnt[val - 1] += 1
    
print(min(cnt))