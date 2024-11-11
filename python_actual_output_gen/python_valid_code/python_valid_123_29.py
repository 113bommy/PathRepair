n = int(input())
end = []
for i in range(n):
	t = input().split()
	end.append(int(t[1]))
k = int(input())
print(len([i for i in range(n) if i >= k]))