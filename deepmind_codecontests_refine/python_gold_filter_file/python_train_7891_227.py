N = str(input())
print(min(abs(int(N[i:i+3]) - 753) for i in range(len(N)-2)))