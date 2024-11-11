import sys
input = sys.stdin.readline
from collections import deque
x = int(input())
*li1, = map(int, input().split())
*li2, = map(int, input().split())
a,b = li1[0], li2[0]
cnt =0
li1 = deque(li1[1:])
li2 = deque(li2[1:])
while cnt <100:
	c= li1.popleft()
	d = li2.popleft()
	if c>d:
		li1 += [d,c]
	else:
		li2 += [c,d]
	cnt+=1
	if len(li1)==0 or len(li2)==0:
		print(cnt, 1 if len(li2) ==0 else 2)
		break
else:
	print(-1)

