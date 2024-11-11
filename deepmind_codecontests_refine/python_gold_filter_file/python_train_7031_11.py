p,q,r,s,a,b = input().split()
p,q,r,s,a,b = [int(p),int(q),int(r),int(s),int(a),int(b)]
i = a
answer = 0
for j in range(a,b+1):
    if (j<p and j<q and j<r and j<s):
        answer = answer+1
    else:
        j=j+1
print(answer)