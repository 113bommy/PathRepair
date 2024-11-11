n = int(input())

max_chess_start = -1
min_chess_end = 100000001

for i in range(n):
    start,end = [int(x) for x in input().split()]
    if start>max_chess_start:
        max_chess_start = start
    if end<min_chess_end : 
        min_chess_end = end
    
m = int(input())

max_program_start = -1
min_program_end = 100000001

for i in range(m):
    start,end = [int(x) for x in input().split()]
    if start>max_program_start:
        max_program_start = start
    if end<min_program_end : 
        min_program_end = end
    
a = max_program_start - min_chess_end
if a < 0 :
    a = 0
b = max_chess_start - min_program_end
if b < 0:
    b = 0
if a==0 and b == 0:
    print(0)
    exit()
else:
    print(max([a,b]))

