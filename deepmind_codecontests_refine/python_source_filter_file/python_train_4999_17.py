import sys
from collections import deque

n = int( sys.stdin.readline( ) )
que = deque( )
lines = sys.stdin.readlines()
for line in lines:
	op = line.split( " " )
	if "insert" == op[0]:
		que.appendleft( op[1] )
	elif "delete" == op[0]:
		if op[1] in que:
			que.remove( op[1] )
	elif "deleteFirst" == op[0] :
		que.popleft( )
	elif "deleteLast" == op[0]:
		que.pop( )


print( " ".join( que ) )