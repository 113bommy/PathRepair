N = input()
print(min(abs(int(N[i:3+i]) - 753) for i in range(len(N) - 2)))
