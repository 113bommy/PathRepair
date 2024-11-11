N = int(input())
if N % 10 == 0:
    print(10)
else:
    s = 0
    for i in str(N):
        s += int(i)
	print(s)