n = int(input())
l = [int(j) for j in input().split()]
d = dict()
pre = []
for i in range(n):
	if l[i] in d:
		d[l[i]]+=1
	else:
		d[l[i]]=1

	pre.append(d[l[i]])
suf = [0 for i in range(n)]
d = dict()
for i in range(n-1, -1, -1):
	if l[i] in d:
		d[l[i]]+=1
	else:
		d[l[i]]=1
	suf[i] = d[l[i]]
def update(bit, index, val):
	n = len(bit)
	while(index<n):
		bit[index]+=val
		index += index&(-1*index)

	
	
def getsum(bit, index):
	n = len(bit)
	ans = 0
	while(index>0):
		ans+=bit[index]
		index -= index&(-1*index)
	return ans
# arr = [3, 6, 2, 4, 1, 7]
n = len(pre)
# print(pre, suf)
bit = [0]*(max(pre)+1)
inv_ct = 0
for i in range(n-1, -1, -1):
	# index = pre[i]
	inv_ct += getsum(bit, suf[i]-1)
	update(bit, pre[i], 1)
	# print(inv_ct, bit)
print(inv_ct)



# print(pre, suf)
# for i in range(n):
	# val = pre[i]
