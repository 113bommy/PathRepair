N,K=(int(i) for i in input().split())
typ = [int(i) for i in input().split()]
diff_min=pow(10,19)
many=N//typ[0]
opt_typ=1
for b in range(K):
	tmp_many = N//typ[b]
	tmp_diff = N-tmp_many
	if tmp_diff<diff_min:
		diff_min=tmp_diff
		many=tmp_many
		opt_typ=b+1
print(opt_typ,many)
