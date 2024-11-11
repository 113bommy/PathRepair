N = int(input())
num_list = [(i-1) + (N//i-1) for i in range(1, int(N**(1//2))+1) if N%i == 0]
print(min(num_list))