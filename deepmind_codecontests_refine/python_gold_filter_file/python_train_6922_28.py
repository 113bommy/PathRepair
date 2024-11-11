R=lambda:list(map(int,input().split()))
n,m = R(); k,l = R(); n1 = R(); m1 = R()
k1 = [1 for i in n1 if i<m1[m-l]]
print(['NO','YES'][sum(k1)>=k])