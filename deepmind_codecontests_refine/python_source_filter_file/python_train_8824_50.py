
N = int(input())
print(sum(i*(N//i)*(N//i + 1) // 2 for i in range(1,N+1) )
