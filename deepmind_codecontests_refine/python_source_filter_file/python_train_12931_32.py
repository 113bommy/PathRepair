#https://codeforces.com/contest/1284/problem/A
n,m = map(int,input().split())
l1 = list(map(str,input().split()))
l2 = list(map(str,input().split()))
q = int(input())
L = [0]
i = 0
j = 0
while(len(L)<(len(l1)*len(l2))):
	s1 = l1[i%len(l1)]
	s2 = l2[j%len(l2)]
	s = s1+s2
	L.append(s)
	i+=1
	j+=1

for i in range(q):
	y = int(input())
	print(L[y%len(L)])


