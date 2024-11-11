N = int(input())
A = list(map(int,input().split()))
B = [x//400 for x in A if x//400 <= 7]
num_l = len(B)
var_l = len(set(B))
print(max(1,var_l),min(8,var_l+N-num_l))