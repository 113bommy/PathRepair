X = int(input())
se = set(n**e for n in range(32) for e in range(2,11) if n**e <= X)

answer = max(se)
print(answer)
