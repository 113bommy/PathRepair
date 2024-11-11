N = int(input())
 
result = 0
for i in range(1, int(N**0.5)+1):
  if (N - i) % i == 0 and i ** 2 + i < N:
    result += (N - i) // i
      
print(int(result))