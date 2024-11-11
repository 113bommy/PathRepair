import sys
LI=lambda:list(map(int, sys.stdin.readline().split()))
MI=lambda:map(int, sys.stdin.readline().split())
SI=lambda:sys.stdin.readline().strip('\n')
II=lambda:int(sys.stdin.readline())
# sys.stdin=open('input.txt')
# sys.stdout=open('output.txt', 'w')
# for _ in range(II()):
num=[[0 for i in range(26)] for j in range(26)]
cnt={}
ans=0
for c in SI()[::-1]:
	v=ord(c)-ord('a')
	for i in range(26):
		num[v][i]+=cnt.get(i, 0)
		ans=max(ans, num[v][i])
	cnt[v]=cnt.get(v, 0)+1
print(max(ans, *cnt.values()))