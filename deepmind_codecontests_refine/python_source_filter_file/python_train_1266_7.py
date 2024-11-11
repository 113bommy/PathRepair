n = int(input())

memory = [1]

for i in range(2, n+1):
  memory.append(memory[i-2]+2**i)

print(memory[n-1])