from collections import defaultdict

Q = int(input())
for _ in range(Q):
	n = int(input())
	a = list(map(int,input().split()))
	ev = a[0:n:2]
	od = a[1:n:2]
	sa = [0]
	tmp = 0
	for i in range(len(od)):
		tmp = max(0, tmp+od[i]-ev[i])
		sa.append(tmp)
	if len(od) > len(ev):
		tmp += od[i+1]
		sa.append(tmp)
	tmp = 0
	for i in range(1, len(od)):
		tmp = max(0, tmp+od[i]-ev[i-1])
		sa.append(tmp)
	print(sum(ev)+max(sa))