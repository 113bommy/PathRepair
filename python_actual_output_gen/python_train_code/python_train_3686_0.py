'''input
3
3 3 3
1 10 2
2 1 1
'''
def ternary (n):
    if n == 0:
        return '0'
    nums = []
    while n:
        n, r = divmod(n, 3)
        nums.append(str(r))
    return ''.join(reversed(nums))
t=int(input())
for _ in range(t):
	s=list(map(int,input().split()))
	s.sort()
	if s[2]>(s[0]+s[1]):
		print("No")
	else:
		print("Yes")